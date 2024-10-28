#include <iostream>
#include "CustomerQueue.h"
#include "ServerList.h"

using namespace std;

void initializeSimulation(int&, ServerList&, CustomerQueue&);
void examineQueue(CustomerQueue);

int main()
{
    ServerList myServers;
    CustomerQueue myCustomers;
    int simulationTime;
    int freeServer;
    int serverID, customerID, completedcustomerID;
    Customer cust;
    int totalCustomers, totalWaitTime, remainingInQueue, remainingWaitTime;
    double averageWaitTime;


    initializeSimulation(simulationTime, myServers, myCustomers);
    cout << "---------------------------------------------------------------\n";

    for (int i = 0; i < simulationTime; i++)
    {
        myServers.updateBusyServer(serverID, completedcustomerID);
        if (serverID > 0)
        {
            cout << "From server: " << serverID << " customer " << completedcustomerID << " departed at time unit " << i << endl;
        }
        myCustomers.updateCustomerWaitTimes();
        if (myCustomers.customerArrived())
        {
            customerID = myCustomers.addCustomer();
            cout << "Customer number: " << customerID << " arrived at time unit: " << i << endl;
        }
        freeServer = myServers.findFreeServer();
        if (freeServer >= 0)
        {
            cust = myCustomers.removeCustomer();
            if (cust.getID() > 0)
            {
                myServers.addCustomer(freeServer, cust);
            }
        }
    }

    totalCustomers = myServers.getTotalCustomersServed();
    totalWaitTime = myServers.getTotalWaitTime();
    remainingInQueue = myCustomers.getNumberInQueue();
    remainingWaitTime = myCustomers.getRemainingWaitTime();
    cout << "---------------------------------------------------------------\n";
    cout << "Number of customers left in queue: " << remainingInQueue << endl;
    cout << "Number of customers that arrived: " << totalCustomers + remainingInQueue << endl;
    cout << "Number of customers who completed a transaction: " << totalCustomers << endl;
    cout << "Average wait time for customers in the queue: " << static_cast<double>(totalWaitTime + remainingWaitTime) / (totalCustomers + remainingInQueue) << endl;
}

void initializeSimulation(int& time, ServerList& myServers, CustomerQueue& myCustomers)
{
    int numServers, transactionTime, timeBetweenArrivals;

    cout << "Enter the number of time units for the simulation: ";
    cin >> time;
    cout << "Enter the number of servers: ";
    cin >> numServers;
    cout << "Enter the server transaction time units: ";
    cin >> transactionTime;
    cout << "Enter time units between customer arrivals: ";
    cin >> timeBetweenArrivals;

    myServers.setTransactionTime(transactionTime);
    for (int i = 0; i < numServers; i++)
    {
        myServers.addServer();
    }
    myCustomers.setTimeBetweenArrivals(timeBetweenArrivals);
}



