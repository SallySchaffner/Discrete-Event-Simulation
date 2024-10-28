#include <iostream>
#include <cmath>
#include "CustomerQueue.h"

int CustomerQueue::addCustomer()
{
    Customer c;
    c.setID();
    cQue.push(c);
    return c.getID();
}

Customer CustomerQueue::removeCustomer()
{
    Customer c;
    if (!cQue.empty())
    {
        c = cQue.front();
        cQue.pop();
    }
    return c;
}

bool CustomerQueue::customerArrived()
{
    double value;
    value = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
    return (value > exp(-1.0 / timeBetweenArrivals));
}

void CustomerQueue::updateCustomerWaitTimes()
{
    queue<Customer> temp;
    Customer cust;
    while (!cQue.empty())
    {
        cust = cQue.front();
        cQue.pop();
        cust.updateWaitTime();
        temp.push(cust);
    }
    while (!temp.empty())
    {
        cust = temp.front();
        temp.pop();
        cQue.push(cust);
    }
}

int CustomerQueue::getNumberInQueue()
{
    return cQue.size();
}

void CustomerQueue::setTimeBetweenArrivals(int time)
{
    timeBetweenArrivals = time;
}

int CustomerQueue::getRemainingWaitTime()
{
    int totalWaitTime = 0;
    Customer cust;
    while (!cQue.empty())
    {
        cust = cQue.front();
        cQue.pop();
        totalWaitTime += cust.getWaitTime();
    }
    return totalWaitTime;
}
