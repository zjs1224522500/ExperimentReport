
#include<iostream>
#include<string>
#include"Employee.h"
using namespace std;

int main()
{
	cout << "Manager:";
	Manager manager;
	cout << "Technicist:";
	Technicist technicist;
	cout << "SalesMan:";
	SalesMan salesman;
	Employee *p1 = &manager,*p2=&technicist,*p3=&salesman;
	p1->pay();
	p1->display();
	p2->pay();
	p2->display();
	p3->pay();
	p3->display();

	return 0;
}