#include<iostream>

#include"Rectangle.h"

using namespace std;

Rectangle::Rectangle(int l, int w)
{
	length = l;
	width = w;
}
Rectangle::Rectangle(const Rectangle& r) :length(r.length), width(r.width)
{
	cout << "复制构造函数执行了" << endl;
}
int Rectangle::area()
{
	return length*width;
}
void Rectangle::Print()
{
	cout << "length:" << length << "   " << "width:" << width << endl;
}
int Rectangle::operator +(Rectangle r)
{
	return this->area() + r.area();
}
int Rectangle::operator -(Rectangle r)
{
	return area() - r.area();
}
int operator +=(Rectangle r1,Rectangle r2)
{
	return r1+r2;
}
int operator -=(Rectangle r1, Rectangle r2)
{
	return r1 - r2;
}
Rectangle& Rectangle::operator =(const Rectangle& r)
{
	length = r.length;
	width = r.width;
	return *this;
}
bool Rectangle::operator >(Rectangle r)
{
	if (this->area() > r.area())
		return 1;
	else
		return 0;
}
Rectangle& Rectangle::operator ++()
{
	++length;
	++width;
	return *this;
}
Rectangle& Rectangle::operator --()
{
	--length;
	--width;
	return *this;
}
Rectangle Rectangle::operator ++(int)
{
	Rectangle temp(this->length, this->width);
	length++;
	width++;
	return temp;
}
Rectangle Rectangle::operator --(int)
{
	Rectangle temp(this->length, this->width);
	length--;
	width--;
	return temp;
}
bool Rectangle::operator ==(const Rectangle& r)
{
	if (length == r.length && width == r.width)
		return 1;
	else
		return 0;
}
