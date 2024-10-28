#include "Customer.h"

void Customer::setID()
{
    static int newID = 0;
    ID = ++newID;
}

int Customer::getID()
{
    return ID;
}

int Customer::getWaitTime()
{
    return waitTime;
}

void Customer::updateWaitTime()
{
    waitTime++;
}