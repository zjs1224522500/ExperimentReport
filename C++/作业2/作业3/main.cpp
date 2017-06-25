#include<iostream>

#include"time.h"

int main()
{
	Time time1(2002);
	time1.Print();
	Time time2(time1);
	time2.Print();
	time1 = time1.Modify(time1,1, 13, 1, 1, 1, 1);
	time1.Print();
	time1.askUsers(time1);
	

	return 0;
}