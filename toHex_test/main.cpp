/**
 * =============================================================================
 * 
 * \file main.cpp
 * \brief 
 * \version 1.0
 * \date 2013年09月22日 08时37分00秒
 * \author  chenjian (chen), chenjian@mail.com
 * \copyright Copyright (c) 2013, adidos 
 *
 * =============================================================================
 */
#include <pthread.h>

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    ostringstream oss;
    oss.setf(std::ios::hex, std::ios::basefield);
    oss.setf(std::ios::showbase);
    oss << pthread_self();
    oss.unsetf(std::ios::showbase);

    string buf = oss.str();
    cout << buf <<endl;

    return 0;
}

