/**
 * =============================================================================
 * 
 * \file main.cpp
 * \brief 
 * \version 1.0
 * \date 2013年07月23日 01时18分51秒
 * \author  chenjian (chen), chenjian@mail.com
 * \copyright Copyright (c) 2013, adidos 
 *
 * =============================================================================
 */

#include <stdio.h>
#include <zlog.h>

int main(int argc, char** argv)
{
    int rc;
    rc = dzlog_init("test_default.conf", "my_cat");
    if (rc) 
    {
        printf("init failed\n");
        return -1;
    }

    dzlog_info("hello, zlog");
    zlog_fini();
    return 0;
}
