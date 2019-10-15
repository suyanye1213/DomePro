/**
 ** 版权说明：
 **     该程序是由苏彦业在2019年10月13日编写，并于2019年10月13日修改；
 **     该程序并不保证没有任何BUG，使用中出现的任何问题，本人不承担责任；
 **     该程序在git上共享，欢迎大家一起修改并优化
 **
 ** 使用说明：
 **     在使用前需要在头文件第22行添加配置文件字段名，在头文件第25行添加配置文件字段默认值，
 ** 在函数initConfigData()中添加m_configData初始化，在函数initMapConfigData()
 ** 中添加m_mapConfigData初始化
 **/

#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <iostream>
#include <string>
#include <map>

using namespace std;


// 配置文件字段
#define strKey "key"

//字段默认值
#define defaultKey "value"

typedef struct configData
{
    string key;
}configData;

class ConfigFile
{
public:
    ~ConfigFile();

    /* #brief   带参构造函数
     * #note    None
     * #param   fileName :  传入   配置文件的路径及文件名
     * #retval  None
     */
//    ConfigFile(const string &fileName);

    /* #brief   获取该类的实例
     * #note    该函数返回该类的引用
     * #param   None
     * #retval  实例的引用
     */
    static ConfigFile &getConfigFileObject()
    {
        static ConfigFile configFile;

        return configFile;
    }

    /* #brief   初始化ConfigFile实例
     * #note    在初始化前需要先调用setFileName函数
     * #param   None
     * #retval  None
     */
    void initConfigFileObject();

    /* #brief   设置配置文件的路径及文件名
     * #note    None
     * #param   fileName :  传入   配置文件的路径及文件名
     * #retval  None
     */
    void setFileName(const string &fileName);

    /* #brief   从配置文件中加载配置信息
     * #note    None
     * #param   None
     * #retval  加载成功返回true，失败返回false
     */
    bool loadConfigFile();
    /* #brief   将配置信息写入配置文件
     * #note    None
     * #param   None
     * #retval  None
     */
    void writeConfigFile();

    /* #brief   写入配置信息
     * #note    None
     * #param   key :   传入  键值
     *          value : 传入  键值对应的数据
     * #retval  None
     */
    void writeConfigInfo(const string &key, const string &value);
    /* #brief   读出配置信息
     * #note    None
     * #param   key :           传入  键值
     *          defaultValue :  传入  键值对应的默认数据
     * #retval  键值对应的数据
     */
    string readConfigInfo(const string &key, const string &defaultValue);

    /* #brief   将map中的配置信息打印出来
     * #note    None
     * #param   None
     * #retval  None
     */
    void dump();

private:
    ConfigFile();

    /* #brief   将从配置文件中加载出来的一行数据进行解析
     * #note    None
     * #param   data :          传入  数据
     *          key :           传出  该数据中的键值
     *          value :  传出  键值对应的数据
     * #retval  解析成功，返回true, 否则false
     */
    bool parseData(string &data, string &key, string &value);

    /* #brief   使用m_mapConfigData初始化m_configData
     * #note    None
     * #param   None
     * #retval  None
     */
    void initConfigData();

    /* #brief   使用m_configDatam_mapConfigData初始化m_mapConfigData
     * #note    None
     * #param   None
     * #retval  None
     */
    void initMapConfigData();

private:
    string m_fileName;                      //保留配置文件的路径及文件名
    map<string, string> m_mapConfigInfo;    //保存配置信息，用于写入配置文件
    configData m_configData;                //保存配置文件，用于系统使用

};

#endif // CONFIGFILE_H
