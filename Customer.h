#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
public:
    void setID();
    int getID();
    int getWaitTime();
    void updateWaitTime();

private:
    int ID = 0;
    int waitTime = 0;
};

#endif