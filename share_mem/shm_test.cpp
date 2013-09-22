/**
 * =============================================================================
 * 
 * \file shm_test.cpp
 * \brief 
 * \version 1.0
 * \date 2013年07月18日 09时32分45秒
 * \author  chenjian (chen), chenjian@email.com
 * \copyright Copyright (c) 2013, adidos 
 *
 * =============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <iostream>

using namespace std;

int main()
{
    int shm_fd = shm_open("/shm.test", O_RDWR | O_CREAT|O_EXCL, S_IRWXU|S_IRWXG|S_IRWXO);
    if(shm_fd < 0)
    {
        if(errno == EEXIST) shm_unlink("/shm.test");
        perror("shm_open");
        exit(0);
    }

    cout << "create shared memory success, shm id is " << shm_fd <<endl;
    ftruncate(shm_fd, 8192);

    void* ptr = mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if(NULL == ptr)
    {
        perror("mmap");
        exit(0);
    }
    printf("ptr address is %p ", ptr);
    memset(ptr, '\0', 8192);
    munmap(ptr, 8192);



    //shm_unlink("/shm.test");
}
