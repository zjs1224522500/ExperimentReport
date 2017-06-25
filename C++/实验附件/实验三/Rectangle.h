#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle
{
public:
	Rectangle(int l = 5, int w = 5);
	Rectangle(const Rectangle& r);	

	int area();
	void Print();

//成员函数重载
	int operator +(Rectangle r);
	int operator -(Rectangle r);
	Rectangle& operator ++();//前缀，返回对象本身的引用
	Rectangle operator ++(int);//返回临时值
	Rectangle& operator --();//前缀，返回对象本身的引用
	Rectangle operator --(int);//返回临时值
	//参数为右值的常量引用，返回值为对左值对象的引用
	Rectangle& operator =(const Rectangle& r);
	bool operator >(Rectangle r);//只为类重载>和<两个运算符之一
	/*Rectangle& operator +=(const Rectangle& r);
	Rectangle& operator -=(const Rectangle& r);*/
	friend int operator +=(Rectangle r1, Rectangle r2);
	friend int operator -=(Rectangle r1, Rectangle r2);
	bool operator ==(const Rectangle& r);
	

//友元函数重载
	/*
	friend Rectangle operator +(const Rectangle& r1,const Rectangle& r2);
	friend Rectangle operator -(const Rectangle& r1, const Rectangle& r2);

	//最好作为成员函数重载
	friend Rectangle& operator ++(const Rectangle& r2);//前缀，返回对象本身的引用
	friend Rectangle operator ++(const Rectangle& r2,int);//返回临时值
	friend Rectangle& operator --(const Rectangle& r);//前缀，返回对象本身的引用
	friend Rectangle operator --(const Rectangle& r,int);//返回临时值
	//赋值操作只能作为成员函数重载
	friend bool operator >(const Rectangle& r1, const Rectangle& r2);//只为类重载>和<两个运算符之一
	friend Rectangle& operator +=(const Rectangle& r1, const Rectangle& r2);
	friend Rectangle& operator -=(const Rectangle& r1, const Rectangle& r2);
	friend Rectangle& operator ==(const Rectangle& r1, const Rectangle& r2);
	*/

private:
	int length;
	int width;
};







#endif