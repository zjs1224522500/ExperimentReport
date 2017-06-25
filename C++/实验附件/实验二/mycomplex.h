#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H
#include<iostream>
using namespace std;
class myComplex
{
public:
	myComplex(){ real = 0; imag = 0; }
	myComplex(int a) :real(a){ imag = 0; }
	myComplex(int a, int b) :real(a), imag(b){}
	myComplex(myComplex& v) :real(v.real), imag(v.imag){};
	double getReal();
	double getImaginary();
	double getModulus();						//返回复数的模

	myComplex& operator = (myComplex& rhs);
	myComplex& operator +=(myComplex& rhs);
	myComplex& operator -=(myComplex& rhs);
	myComplex& operator *=(myComplex& rhs);
	myComplex& operator /=(myComplex& rhs);
	friend myComplex operator + (myComplex& rhs1, myComplex& rhs2);
	friend myComplex operator - (myComplex& rhs1, myComplex& rhs2);
	friend myComplex operator * (myComplex& rhs1, myComplex& rhs2);
	friend myComplex operator / (myComplex& rhs1, myComplex& rhs2);
	friend ostream& operator <<(ostream& os, myComplex &rhs);
	friend istream& operator >>(istream& is, myComplex &rhs);
private:
	double real;
	double imag;
};

double myComplex::getReal()
{
	return real;
}
double myComplex::getImaginary()
{
	return imag;
}
double myComplex::getModulus()
{
	return sqrt(real*real + imag*imag);
}
myComplex& myComplex::operator = (myComplex& rhs)
{
	real = rhs.real;
	imag = rhs.imag;
	return *this;
}
myComplex& myComplex::operator +=(myComplex& rhs)
{
	/*
	***************this为对象指针，*this则是指对象本身**************
	***************所以可以调用重载后的复数加法运算*****************
	*************** -= 、*= 、/= 、 同理  *********************************
	*/
	*this = *this + rhs;
	return *this;
}
myComplex& myComplex::operator -=(myComplex& rhs)
{
	*this=*this - rhs;
	return *this;
}
myComplex& myComplex::operator *=(myComplex& rhs)
{
	*this=*this * rhs;
	return *this;
}
myComplex& myComplex::operator /=(myComplex& rhs)
{
	 *this=*this / rhs;
	 return *this;
	/*return myComplex((real * rhs.real + imag * rhs.imag)
		/ (real * real + rhs.imag * rhs.imag),
		(imag * rhs.real - real * rhs.imag)
		/ (rhs.real * rhs.real + rhs.imag * rhs.imag));*/
}
myComplex operator + (myComplex& rhs1, myComplex& rhs2)
{
	return myComplex(rhs1.real + rhs2.real, rhs1.imag + rhs2.imag);
}
myComplex operator - (myComplex& rhs1, myComplex& rhs2)
{
	return myComplex(rhs1.real - rhs2.real, rhs1.imag - rhs2.imag);
}
myComplex operator * (myComplex& rhs1, myComplex& rhs2)
{
	return myComplex(rhs1.real * rhs2.real - rhs1.imag * rhs2.imag,
		rhs1.real * rhs2.imag + rhs1.imag * rhs2.real);
}
myComplex operator / (myComplex& c1, myComplex& c2)
{
	return myComplex((c1.real * c2.real + c1.imag * c2.imag)
		/ (c2.real * c2.real + c2.imag * c2.imag),
		(c1.imag * c2.real - c1.real * c2.imag)
		/ (c2.real * c2.real + c2.imag * c2.imag));
}

ostream& operator <<(ostream& os, myComplex &rhs)
{
	os << '(' << rhs.getReal() << ',' << rhs.getImaginary() << ')';
	return os;
}
istream& operator >>(istream& is, myComplex &rhs)
{
	is >> rhs.real >> rhs.imag;
	return is;
}
#endif