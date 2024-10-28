#ifndef SERVERLIST_H
#define SERVERLIST_H

#include <string>
#include "Server.h"

using namespace std;

class ServerList
{
public:
    void addServer();
    int findFreeServer();
    void setTransactionTime(int);
    void addCustomer(int, Customer);
    void updateBusyServer(int&, int&);
    int getTotalCustomersServed();
    int getTotalWaitTime();

private:
    Server myList[100];
    int length = 0;
    int transactionTime;
    int totalCustomersServed = 0;
    int totalWaitTime = 0;
};

#endif