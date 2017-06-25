#include<iostream>
#include"Rectangle.h"
using namespace std;
int main()
{
	Rectangle r1;
	Rectangle r2;
	Rectangle a(0, 0);
	Rectangle b(0, 0);
	
	cout << "+   :"<< r1 + r2 << endl;
	cout << "-   :"<< r1 - r2 << endl;
	cout << "+=  :" << (r1 += r2)<< endl;
	cout << "-=  :" << (r1 -= r2)<< endl;
	
	cout <<"r1 > r2 ?   "<< (r1 > r2)<< endl;
	cout <<"r1 == r2 ?  "<< (r1 == r2)<< endl;
	
	cout << "++"<<endl;
	cout << "r1      :";
	r1.Print();
	a = r1++;
	cout << "r1      :";
	r1.Print();
	cout << "a=r1++   ";
	a.Print();
	++r1;
	cout << "r1      :";
	r1.Print();
	cout << "a=++r1   ";
	a.Print();

	cout << "--"<<endl;
	cout << "r2      :";
	r2.Print();
	b=r2--;
	cout << "r2      :";
	r2.Print();
	cout << "b=r2--   ";
	b.Print();
	--r2;
	cout << "r2      :";
	r2.Print();
	cout << "b=--r2   ";
	b.Print();

	cout << "½«r1¸³¸øa£¬Êä³öa£º  ";
	a = r1;
	a.Print();

	cout << "c   :";
	Rectangle c(r1);
	c.Print();

	return 0;
}