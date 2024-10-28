#include <iostream>
#include "Server.h"

using namespace std;

void Server::setID()
{
	static int newID = 0;
	ID = ++newID;
}

int Server::getID()
{
	return ID;
}

void Server::setServerStatus(int newStatus)
{
	serverBusy = newStatus;
}

int Server::getServerStatus()
{
	return serverBusy;
}

void Server::setTransactionTime(int time)
{
	transactionTime = time;
}

int Server::getTransactionTime()
{
	return transactionTime;
}

void Server::updateTransactionTime()
{
	transactionTime--;
}

int Server::getCustomerWaitTime()
{
	return myCustomer.getWaitTime();
}

int Server::getCustomerID()
{
	return myCustomer.getID();
}

void Server::addCustomer(Customer cust)
{
	myCustomer = cust;
}

