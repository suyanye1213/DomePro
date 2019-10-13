/**
 ** 版权说明：
 **     该程序是由苏彦业在2019年10月13日编写，并于2019年10月13日修改；
 **     该程序并不保证没有任何BUG，使用中出现的任何问题，本人不承担责任；
 **     该程序在git上共享，欢迎大家一起修改并优化
 **/

#ifndef SINGLETON_H
#define SINGLETON_H

/* 单例模式（懒汉）
 * 在使用该类对象时，确保只有一个该对象被创建
 */

#include <iostream>

using namespace std;


class Singleton
{
public:
    ~Singleton()
    {
        cout << "singleton destructor" << endl;
    }

    static Singleton &getSingleton()
    {
        static Singleton singleton;

        return singleton;
    }

private:
    Singleton()
    {
        cout << "singleton constructor" << endl;
    }

};

#endif // SINGLETON_H
