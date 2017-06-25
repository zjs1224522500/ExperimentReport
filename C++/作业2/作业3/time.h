#ifndef TIME_H_H
#define TIME_H_H
class Time
{
public:
	Time(int y = 2001, int M = 1, int d = 1, int h = 0, int m = 0, int s = 0);
	void Print();
	Time(const Time& t);
	Time& Modify(Time& time, int y = 0, int M = 0, int d = 0, int h = 0, int m = 0, int s = 0);
	void askUsers(Time& t);
	

private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};


#endif