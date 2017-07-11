#pragma once
#include<stdio.h>


class A {
public:
	void f() {
		printf("hello");
	}
};


class TicketMachine
{
public:
	TicketMachine();
	virtual ~TicketMachine();
	void showPrompt();
	void insertMoney(int money);
	void showBalance();
	void showTotal();
	void printTicket();
private:
	const int PRICE;
	int total;
	int balance=0;
};

//#endif // !1

