#include <iostream>

using namespace std;

#include "log.h"

int main()
{
    Log::getLogObject().setLogFileName("/home/suyanye/project/Log.txt");

    Log::getLogObject().clean();

    Log::getLogObject().writeLog("Holle world");

    return 0;
}
