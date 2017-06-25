#include<iostream>
#include"mycomplex.h"
using namespace std;
int main(){
	myComplex c1;
	myComplex c2;
	cin >> c1;
	c2 = c1;
	cout << "c1=" << c1 << endl;
	cout << "c2=" << c2 << endl;
	cout << "c1+c2=" << c1 + c2 << endl;
	//c1+=c2后  此时的c1=c1+c2；故后面的c1-c2将等于最初的c2   c1-=c2   同理。
	cout << "c1+=c2 " << (c1 += c2) << endl;
	cout << "c1-c2=" << c1 - c2 << endl;
	cout << "c1-=c2 " <<(c1 -= c2) << endl;
	cout << "c1/c2=" << c1 / c2 << endl;
	cout << "c1/=c2 " << (c1 /= c2) << endl;
	cout << "c1*c2=" << c1 * c2 << endl;
	cout << "c1*=c2 " << (c1 *= c2) << endl;
	
	return 0;
}
