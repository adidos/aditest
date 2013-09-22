/**
 * =============================================================================
 * 
 * \file once_flag_test.cpp
 * \brief 
 * \version 1.0
 * \date 2013年09月15日 18时24分04秒
 * \author  chenjian (chen), chenjian@mail.com
 * \copyright Copyright (c) 2013, adidos 
 *
 * =============================================================================
 */

#include <pthread.h>

#include <iostream>
#include <mutex>

using namespace std;


std::once_flag g_flag;

void once_func()
{
    cout << __FUNCTION__ << "\t" << pthread_self() << " this is once call function!" << endl;
};

void* one_func(void*)
{
    cout << __FUNCTION__ << "\t" << "my thread id is " <<  pthread_self() << endl;
    std::call_once(g_flag, once_func);

    return NULL;
};

void* two_func(void*)
{
    cout << __FUNCTION__ << "\t" << "my thread id is " <<  pthread_self() << endl;
    std::call_once(g_flag, once_func);

    return NULL;
};

int main()
{
    pthread_t one,two,three;
    pthread_create(&one, NULL, one_func, NULL);
    usleep(1000);
    pthread_create(&two, NULL, two_func, NULL);
    usleep(1000);
    pthread_create(&three, NULL, one_func, NULL);
    usleep(1000);

    pthread_join(one, NULL);
    pthread_join(two, NULL);
    pthread_join(three, NULL);

    return 0;
}

