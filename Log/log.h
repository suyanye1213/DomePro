/**
 ** 版权说明：
 **     该程序是由苏彦业在2019年10月15日编写，并于2019年10月15日修改；
 **     该程序并不保证没有任何BUG，使用中出现的任何问题，本人不承担责任；
 **     该程序在git上共享，欢迎大家一起修改并优化
 **
 ** 使用说明：
 **/

#ifndef LOG_H
#define LOG_H

#include <string>

using namespace std;

class Log
{
public:
    ~Log();

    /* #brief   获取该类的实例
     * #note    该函数返回该类的引用
     * #param   None
     * #retval  实例的引用
     */
    static Log &getLogObject()
    {
        static Log log;

        return  log;
    }

    /* #brief   设置日志文件名
     * #note    None
     * #param   日志文件名
     * #retval  None
     */
    void setLogFileName(const string &logFileName);

    /* #brief   清除日志内容
     * #note    该函数返回该类的引用
     * #param   None
     * #retval  实例的引用
     */
    bool clean();

    /* #brief   将str信息写入日志文件
     * #note    None
     * #param   str：    日志信息
     * #retval  None
     */
    void writeLog(const string &str);

private:
    Log();

    /* #brief   获取当前系统时间
     * #note    None
     * #param   None
     * #retval  返回时间戳：年-月-日 时：分：秒
     */
    string getSystemTime() const;

private:
    string m_logFileName;   //保留日志文件名
};

#endif // LOG_H
