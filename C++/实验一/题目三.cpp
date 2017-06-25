#include<iostream>
using namespace std;
class Box
{
public:
	Box(int l, int w, int h) :length(l), width(w), height(h)
	{
		cout << "调用了构造函数！" << endl;
	}
	~Box()
	{
		cout << "调用了析构函数"<< endl;
	}
	int Volume()
	{
		return height*length*width;
	}
	int Superficialarea()
	{
		return 2 * (height*width + height*length + length*width);
	}
private:
	int length;
	int width;
	int height;
};
int main()
{
	Box box(1, 2, 3);
	int v, s;
	v = box.Volume();
	s = box.Superficialarea();
	cout << "Volume:" << v << "  " << "Superficial area:" << s << endl;
	return 0;

}