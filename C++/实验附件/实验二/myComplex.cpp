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
	//c1+=c2��  ��ʱ��c1=c1+c2���ʺ����c1-c2�����������c2   c1-=c2   ͬ��
	cout << "c1+=c2 " << (c1 += c2) << endl;
	cout << "c1-c2=" << c1 - c2 << endl;
	cout << "c1-=c2 " <<(c1 -= c2) << endl;
	cout << "c1/c2=" << c1 / c2 << endl;
	cout << "c1/=c2 " << (c1 /= c2) << endl;
	cout << "c1*c2=" << c1 * c2 << endl;
	cout << "c1*=c2 " << (c1 *= c2) << endl;
	
	return 0;
}
