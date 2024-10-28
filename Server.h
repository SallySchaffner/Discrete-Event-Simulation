#ifndef SERVER_H
#define SERVER_H

#include "Customer.h"

class Server
{
public:
    void setID();
    int getID();
    void setServerStatus(int);
    int getServerStatus();
    void setTransactionTime(int);
    int getTransactionTime();
    void updateTransactionTime();
    int getCustomerWaitTime();
    int getCustomerID();
    void addCustomer(Customer);

private:
    int ID;
    int serverBusy = 0;
    int transactionTime;
    Customer myCustomer;
};

#endif