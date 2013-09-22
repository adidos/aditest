/**
 * =============================================================================
 * 
 * \file main.cpp
 * \brief 
 * \version 1.0
 * \date 2013年07月21日 22时37分42秒
 * \author  chenjian (chen), chenjian@mail.com
 * \copyright Copyright (c) 2013, adidos 
 *
 * =============================================================================
 */

#include <util/util.h>

int _atoi(const char* src,int length)
{
    int total = 0;
    char* tmp = (char*)src;

    char c = '0';
    while(length-- > 0)
    {
        c = *tmp;
        total = total*10 + (c - '0');
        ++tmp; 
    }
    
    return total;
};

