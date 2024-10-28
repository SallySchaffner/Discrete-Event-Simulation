#include <iostream>
#include "ServerList.h"

using namespace std;

void ServerList::addServer()
{
    Server s;
    s.setID();
    s.setTransactionTime(transactionTime);
    myList[length] = s;
    length++;
}

int ServerList::findFreeServer() //throw (NoFreeServer)
{
    int freeServer = -1;
    for (int i = 0; i < length; i++)
    {
        if (myList[i].getServerStatus() == 0)
            freeServer = i;
    }
    return freeServer;
}

void ServerList::setTransactionTime(int time)
{
    transactionTime = time;
}

void ServerList::addCustomer(int server, Customer cust)
{
    myList[server].addCustomer(cust);
    myList[server].setTransactionTime(transactionTime);
    myList[server].setServerStatus(1);
}

void ServerList::updateBusyServer(int& serverID, int& customerID)
{
    serverID = 0;
    customerID = 0;
    for (int i = 0; i < length; i++)
    {
        if (myList[i].getServerStatus() == 1)
        {
            myList[i].updateTransactionTime();
            if (myList[i].getTransactionTime() == 0)
            {
                serverID = i;
                totalCustomersServed++;
                totalWaitTime += myList[i].getCustomerWaitTime();
                serverID = myList[i].getID();
                customerID = myList[i].getCustomerID();
                myList[i].setServerStatus(0);
            }
        }
    }
}

int ServerList::getTotalCustomersServed()
{
    return totalCustomersServed;
}

int ServerList::getTotalWaitTime()
{
    return totalWaitTime;
}