/**
 * =============================================================================
 * 
 * \file mydelete.cpp
 * \brief 
 * \version 1.0
 * \date 2013年09月14日 09时43分08秒
 * \author  chenjian (chen), chenjian@mail.com
 * \copyright Copyright (c) 2013, adidos 
 *
 * =============================================================================
 */

#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

int main()
{
    map<int,int> arry;
    for(int i = 0; i < 25; ++i)
    {
        arry.insert(make_pair(i, i+1));
    }

    for_each(begin(arry), end(arry), [&arry](pair<int,int> val)
        {
            if(0 == val.second%3)
                arry.erase(val.first);
        });
    
    for_each(begin(arry), end(arry), [](pair<int,int> val)
        {
            cout<< val.first << "\t" << val.second <<endl;
        });

    return 0;
}
