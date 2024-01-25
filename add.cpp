#include "add.h"

using namespace std;

void addOneHour()
{
    int currentHour = getHour();

    if ((0 <= currentHour) && (currentHour <= 22))
    {
        setHour(currentHour + 1);
    }
    else
    {
        setHour(0);
    }
}

void addOneMinute()
{
    int currentMinute = getMinute();

    if ((0 <= currentMinute) && (currentMinute <= 58))
    {
        setMinute(currentMinute + 1);
    }
    else
    {
        setMinute(0);
        addOneHour();
    }
}

void addOneSecond()
{

    int currentSecond = getSecond();

    if ((0 <= currentSecond) && (currentSecond <= 58))
    {
        setSecond(currentSecond + 1);
    }
    else
    {
        setSecond(0);
        addOneMinute();
    }
}