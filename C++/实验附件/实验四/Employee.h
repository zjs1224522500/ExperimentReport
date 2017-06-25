#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>

using namespace std;

class Employee
{
public:
	Employee();//�Զ�����Ա����ţ������Ӽ������룬���ʳ�ֵΪ0
	~Employee();
//	virtual void pay() = 0;//������н
//	virtual void display() = 0;//��ʾ��Ա��Ϣ

	void pay() =0;
	void display() =0;

protected:
	int No;
	string name;
	float salary;
	static int totalNo;			//�Զ�����Ա�����
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
	cout << "����pay����ִ��" << endl;
}
void Employee::display()
{
	cout << "����display����ִ��" << endl;
}

class Manager : public Employee
{
public:
	Manager() :Employee()
	{ 
		monthPay = 8000; //����̶���н8000
	}
	void pay()
	{
		salary = monthPay;//��н
	}
	void display()
	{
		cout << "���Ϊ" << No << "�ľ�����Ա  " << name << "  ����нˮΪ" << salary << endl;
	}
private:
	float monthPay;
}; 
class SalesMan : public Employee
{
public:
	SalesMan() :Employee()
	{
		percantage = 0.03;//������Ա���������۶�İٷ�֮��
	}
	void pay()
	{
		cout << "Please enter the total sales of the salesman:";
		cin >> TotalSale;
		salary = TotalSale*percantage;//���۶�*��ɱ���
	}
	void display()
	{
		cout << "���Ϊ" << No << "��������Ա  " << name << "  ����нˮΪ" << salary << endl;
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
		hourPay = 50;//������Ա��50ԪÿСʱ
	}
	void pay()
	{
		cout << "Please enter the work hours of technicist:";
		cin >> hours;
		salary = hours*hourPay;//����ʱ��*ÿСʱ�Ĺ���
	}
	void display()
	{
		cout << "���Ϊ" << No << "�ļ�����Ա  " << name << "  ����нˮΪ" << salary << endl;
	}
private:
	float hours;
	float hourPay;
};
#endif