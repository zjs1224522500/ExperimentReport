#include<iostream>
#include<iomanip>

#include"time.h"

using namespace std;

Time::Time(int y, int M, int d, int h, int m, int s)
{
	year = y;
	month = M;
	day = d;
	hour = h;
	minute = m;
	second = s;
}
void Time::Print()
{
	cout << "当前时间为：";
	cout << setw(4) << setfill('0') << year << "-";
	cout << setw(2) << setfill('0') << month << "-";
	cout << setw(2) << setfill('0') << day << ":";
	cout << setw(2) << setfill('0') << hour << ":";
	cout << setw(2) << setfill('0') << minute << ":";
	cout << setw(2) << setfill('0') << second << endl;
}
Time::Time(const Time& t)
:year(t.year), month(t.month), day(t.day), hour(t.hour), minute(t.minute), second(t.second)
{
	cout << "复制构造函数执行了ｙｅａｈ！" << endl;
}
Time& Time::Modify(Time& time, int y, int M, int d, int h, int m, int s)
{
	year += y;
	if ((month + M) != 12)
		month = (M + month) % 12;
	if ((day + d) != 30)
		day = (day + d) % 30;
	hour = (hour + h) % 24;
	minute = (minute + m) % 60;
	second = (second + s) % 60;
	return time;
}
void Time::askUsers(Time& t)
{
	cout << "Do you want to modify the time? y or n" << endl;
	char ch1;
	cin >> ch1;
	if (ch1 == 'n')
		exit(0);
	else
	{
		cout << "Which one do you want to modify?( y,M,d,h,m,s )" << endl;
		char ch2;
		cin >> ch2;
		cout << "Add:please enter a number(  >0  )" << endl;
		cout << "Minus:Please enter a number(  <0  )" << endl;
		int a;
		cin >> a;
		

		switch (ch2)
		{
		case 'y':t.Modify(t, a); break;
		case 'M':t.Modify(t, 0, a);break;
		case 'd':t.Modify(t, 0, 0, a); break;
		case 'h':t.Modify(t, 0, 0, 0, a);break;
		case 'm':t.Modify(t, 0, 0, 0, 0, a);break;
		case 's':t.Modify(t, 0, 0, 0, 0, 0, a);break;
		default:cout << "Wrong input !!!" << endl;
		}
		t.Print();

	}

}