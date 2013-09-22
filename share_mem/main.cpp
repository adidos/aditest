/**
 * =============================================================================
 * 
 * \file main.cpp
 * \brief 
 * \version 1.0
 * \date 2013年07月17日 22时31分33秒
 * \author  chenjian (chen), chenjian@email.com
 * \copyright Copyright (c) 2013, adidos 
 *
 * =============================================================================
 */
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <wait.h>

#include <iostream>

using namespace std;

struct shared_t{
    sem_t mutex;
    int count;
} shared;

int main()
{
    int fd = open("/tmp/mmap", O_RDWR|O_CREAT|O_EXCL, S_IRWXU);
    if( 0 > fd)
    {
        perror("open");
        return -1;
    }

    write(fd, &shared, sizeof(shared));
    shared_t *ptr = (shared_t*)mmap(NULL, sizeof(shared_t), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    sem_init(&ptr->mutex, 1, 1);

    if(fork() == 0)
    {
        for(int i = 0; i < 1000; ++i)
        {
            sem_wait(&ptr->mutex);
            printf("child : %d\n", ptr->count++); 
            sem_post(&ptr->mutex);
        }

        exit(0);
    }

    for(int i = 0; i < 1000; ++i)
    {
        sem_wait(&ptr->mutex);
        printf("parent: %d\n", ptr->count++); 
        sem_post(&ptr->mutex);
    }
    
    exit(0);
}
