#ifndef CUSTOMERQ_H
#define CUSTOMERQ_H

#include <string>
#include <queue>
#include "Customer.h"

using namespace std;

class CustomerQueue
{
public:
    int addCustomer();
    Customer removeCustomer();
    bool customerArrived();
    void updateCustomerWaitTimes();
    int getNumberInQueue();
    void setTimeBetweenArrivals(int);
    int getRemainingWaitTime();

private:
    queue<Customer> cQue;
    int timeBetweenArrivals;
};


#endif