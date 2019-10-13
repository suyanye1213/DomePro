/**
 ** 版权说明：
 **     该程序是由苏彦业在2019年10月13日编写，并于2019年10月13日修改；
 **     该程序并不保证没有BUG，使用中出现的任何问题，本人不承担责任；
 **     该程序在git上共享，欢迎大家一起修改并优化。
 **/

#include <iostream>

using namespace std;

#include <singleton.h>

int main()
{
    cout << "Hello World!" << endl;

    cout << "first : " << &(Singleton::getSingleton()) << endl;
    cout << "second : " << &(Singleton::getSingleton()) << endl;

    return 0;
}
