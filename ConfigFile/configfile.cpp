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

#include "configfile.h"

#include <fstream>

ConfigFile::ConfigFile()
{
    m_fileName = string("");
    m_mapConfigInfo.clear();
}

ConfigFile::~ConfigFile()
{
}

//ConfigFile::ConfigFile(const string &fileName)
//{
//    m_fileName = fileName;
//    m_mapConfigInfo.clear();

//    cout << "constructor fileName" << endl;
//}

void ConfigFile::setFileName(const string &fileName)
{
    m_fileName = fileName;
}

bool ConfigFile::loadConfigFile()
{
    if (m_fileName == "")
    {
        cout << "Config file name null" << endl;
        return false;
    }

    ifstream inFile;
    inFile.open(m_fileName, ios_base::in);
    if (!inFile.is_open())
    {
        cout << "Error open config file \'" << m_fileName << "\'" << endl;
        return false;
    }

    string lineData;
    getline(inFile, lineData);

    while (!lineData.empty())
    {
        string key;
        string value;

        if (!parseData(lineData, key, value))
        {
            cout << "class ConfigFile, Function loadConfigFile parse data error" << endl;
            return false;
        }

        m_mapConfigInfo.insert(pair<string, string>(key, value));

        getline(inFile, lineData);
    }

    inFile.close();

    return true;
}

void ConfigFile::writeConfigFile()
{
    ofstream outFile;

    //打开文件时丢弃文件内容
    outFile.open(m_fileName, ios_base::trunc);
    
    map<string, string>::iterator it = m_mapConfigInfo.begin();

    while (it != m_mapConfigInfo.end())
    {
        outFile << (*it).first << "=" << (*it).second << endl;
        it++;
    }

    outFile.close();
}

void ConfigFile::writeConfigInfo(const string &key, const string &value)
{
    map<string, string>::iterator it = m_mapConfigInfo.begin();

    while (it != m_mapConfigInfo.end())
    {
        if ((*it).first == key)
        {
            (*it).second = value;
            return;
        }

        it++;
    }

    m_mapConfigInfo.insert(pair<string, string>(key, value));

}

string ConfigFile::readConfigInfo(const string &key, const string &defaultValue)
{
    string result;

    map<string, string>::iterator it = m_mapConfigInfo.begin();

    while (it != m_mapConfigInfo.end())
    {
        if ((*it).first == key)
        {
            result = (*it).second;
            return result;
        }

        it++;
    }

    result = defaultValue;
    return result;
}

bool ConfigFile::parseData(string &data, string &key, string &value)
{
    if (data.empty())
    {
        cout << "class ConfigFile, function parseData() Data is null" << endl;
        return false;
    }

    size_t index = data.find("=");

    if (0 >= index)
    {
        cout << "class ConfigFile, function parseData() Data error" << endl;
        return false;
    }

    char *charKey = new char[index + 1];
    size_t size = data.copy(charKey, index, 0);
    if (size <= 0)
    {
        cout << "class ConfigFile, function parseData() Key error" << endl;
        return false;
    }
    charKey[index] = '\0';
    key.append(charKey);
    delete [] charKey;

    char *charValue = new char[data.size() - index - 1 + 1];
    size = data.copy(charValue, data.size() - index - 1, index + 1);
    if (size <= 0)
    {
        cout << "class ConfigFile, function parseData() Value error" << endl;
        return false;
    }
    charValue[data.size() - index - 1] = '\0';
    value.append(charValue);

    delete [] charValue;

    return true;
}

void ConfigFile::dump()
{
    cout << "Config map data : " << m_mapConfigInfo.size() << endl;

    map<string, string>::iterator it = m_mapConfigInfo.begin();

    while (it != m_mapConfigInfo.end())
    {
        cout << (*it).first << "=" << (*it).second << endl;
        it++;
    }

    cout << "-----------------------------" << endl;
}

void ConfigFile::initConfigData()
{
    m_configData.key = readConfigInfo(strKey, defaultKey);
}

void ConfigFile::initMapConfigData()
{
    writeConfigInfo(strKey, m_configData.key);
}

void ConfigFile::initConfigFileObject()
{
    loadConfigFile();
    initConfigData();
    initMapConfigData();
    writeConfigFile();
}
