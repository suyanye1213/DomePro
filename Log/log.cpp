/**
 ** 版权说明：
 **     该程序是由苏彦业在2019年10月16日编写，并于2019年10月16日修改；
 **     该程序并不保证没有任何BUG，使用中出现的任何问题，本人不承担责任；
 **     该程序在git上共享，欢迎大家一起修改并优化
 **
 **/

#include "log.h"

#include <fstream>
#include <iostream>

Log::Log()
{}

Log::~Log()
{}

void Log::setLogFileName(const string &logFileName)
{
    m_logFileName = logFileName;
}

bool Log::clean()
{
    ofstream outFile;

    outFile.open(m_logFileName, ofstream::trunc);

    if (!outFile.is_open())
    {
        cout << "Open log file \'" << m_logFileName << "\' error" << endl;

        return false;
    }

    outFile.close();

    return true;
}

void Log::writeLog(const string &str)
{
    ofstream outFile;

    outFile.open(m_logFileName, ofstream::app);

    if (!outFile.is_open())
    {
        cout << "Open log file \'" << m_logFileName << "\' error" << endl;

        return;
    }

    string strTime = getSystemTime();

    outFile << strTime << str << endl;
}

string Log::getSystemTime() const
{
    string strTime = string("");
    time_t tt;
    time(&tt);
    tt = tt + 8 * 3600;

    tm *t = gmtime(&tt);

    char str[22] = {0};
    sprintf(str, "[%d-%02d-%02d %02d:%02d:%02d]", t->tm_year + 1900, t->tm_mon + 1,
           t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);

    strTime.append(str);

    return strTime;
}
