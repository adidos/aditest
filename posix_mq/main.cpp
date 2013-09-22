/**
 * =============================================================================
 * 
 * \file main.cpp
 * \brief 
 * \version 1.0
 * \date 2013年07月11日 15时43分04秒
 * \author  chenjian (chen), chenjian@skybility.com
 * \copyright Copyright (c) 2013, skybility 
 *
 * =============================================================================
 */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <chrono>
#include <thread>

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>

using namespace std;

int main()
{
    key_t fd = ftok("mq.txt", 0x12);
    if(-1 == fd)
    {
        perror("ftok");
        return -1;
    }

    int msgid = msgget(fd, IPC_CREAT|IPC_EXCL);
    if(-1 == fd)
    {
        perror("msgget");
        return -1;
    }

    std::this_thread::sleep_for(std::chrono::seconds(60));

    return 0;
}

