#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>

using namespace std;

class Employee
{
public:
	Employee();//自动计算员工编号，姓名从键盘输入，工资初值为0
	~Employee();
//	virtual void pay() = 0;//计算月薪
//	virtual void display() = 0;//显示人员信息

	void pay() =0;
	void display() =0;

protected:
	int No;
	string name;
	float salary;
	static int totalNo;			//自动计算员工编号
};
int Employee::totalNo = 0;

Employee::Employee()
{
	salary = 0;
	cout << "Please enter the name:";
	cin >> name;
	totalNo++;
	No = totalNo;
}
Employee::~Employee(){}
void Employee::pay()
{
	cout << "基类pay函数执行" << endl;
}
void Employee::display()
{
	cout << "基类display函数执行" << endl;
}

class Manager : public Employee
{
public:
	Manager() :Employee()
	{ 
		monthPay = 8000; //经理固定月薪8000
	}
	void pay()
	{
		salary = monthPay;//月薪
	}
	void display()
	{
		cout << "编号为" << No << "的经理人员  " << name << "  本月薪水为" << salary << endl;
	}
private:
	float monthPay;
}; 
class SalesMan : public Employee
{
public:
	SalesMan() :Employee()
	{
		percantage = 0.03;//销售人员：当月销售额的百分之三
	}
	void pay()
	{
		cout << "Please enter the total sales of the salesman:";
		cin >> TotalSale;
		salary = TotalSale*percantage;//销售额*提成比例
	}
	void display()
	{
		cout << "编号为" << No << "的销售人员  " << name << "  本月薪水为" << salary << endl;
	}
private:
	float percantage;
	int TotalSale;
};

class Technicist : public Employee
{
public:
	Technicist() :Employee()
	{
		hourPay = 50;//技术人员：50元每小时
	}
	void pay()
	{
		cout << "Please enter the work hours of technicist:";
		cin >> hours;
		salary = hours*hourPay;//工作时长*每小时的工资
	}
	void display()
	{
		cout << "编号为" << No << "的技术人员  " << name << "  本月薪水为" << salary << endl;
	}
private:
	float hours;
	float hourPay;
};
#endif