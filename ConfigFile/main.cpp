#include <iostream>

using namespace std;

#include <configfile.h>

int main()
{
    ConfigFile::getConfigFileObject().setFileName("/home/suyanye/project/config.ini");
    ConfigFile::getConfigFileObject().initConfigFileObject();

    ConfigFile::getConfigFileObject().dump();

    return 0;
}
