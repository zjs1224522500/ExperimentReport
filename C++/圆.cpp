/*
	Define a class named circle.The parts of data consist of the coordinate of the circal central and radius.
	成员方法宝库：构造函数、析构函数、计算圆面积、周长；显示圆心坐标和圆的半径！

*/

#include<iostream>

using namespace std;

class Circle
{
private:
	double radius;
	double central_X, central_Y;
public:
	Circle(double r,double x,double y)
	{
		radius = r;
		central_X = x;
		central_Y = y;
	}
	~Circle(){}

	double Get_girth()
	{
		return 3.14 * 2 * radius;
	}
	double Get_area()
	{
		return 3.14*radius*radius;
	}
	void show()
	{
		cout << "radius=" << radius << endl;
		cout << "central_X=" << central_X << ",central_Y=" << central_Y << endl;
	}

};
int main()
{
	/*Circle cr(10,1,1); //The data is set in advance!*/

	double r;
	double x, y;
	
	//
	cout << "Please enter the radius:";
	cin >> r;
	cin.get();
	cout << "Please rnter the coordinate:";
	cin >> x >> y;
	cin.get();

	Circle cr(r, x, y);

	cr.show();

	cout << "The girth of the circle:" << cr.Get_girth() << endl;
	cout << "The area of the circle:" << cr.Get_area() << endl;

	return 0;
}