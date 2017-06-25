#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle
{
public:
	Rectangle(int l = 5, int w = 5);
	Rectangle(const Rectangle& r);	

	int area();
	void Print();

//��Ա��������
	int operator +(Rectangle r);
	int operator -(Rectangle r);
	Rectangle& operator ++();//ǰ׺�����ض����������
	Rectangle operator ++(int);//������ʱֵ
	Rectangle& operator --();//ǰ׺�����ض����������
	Rectangle operator --(int);//������ʱֵ
	//����Ϊ��ֵ�ĳ������ã�����ֵΪ����ֵ���������
	Rectangle& operator =(const Rectangle& r);
	bool operator >(Rectangle r);//ֻΪ������>��<���������֮һ
	/*Rectangle& operator +=(const Rectangle& r);
	Rectangle& operator -=(const Rectangle& r);*/
	friend int operator +=(Rectangle r1, Rectangle r2);
	friend int operator -=(Rectangle r1, Rectangle r2);
	bool operator ==(const Rectangle& r);
	

//��Ԫ��������
	/*
	friend Rectangle operator +(const Rectangle& r1,const Rectangle& r2);
	friend Rectangle operator -(const Rectangle& r1, const Rectangle& r2);

	//�����Ϊ��Ա��������
	friend Rectangle& operator ++(const Rectangle& r2);//ǰ׺�����ض����������
	friend Rectangle operator ++(const Rectangle& r2,int);//������ʱֵ
	friend Rectangle& operator --(const Rectangle& r);//ǰ׺�����ض����������
	friend Rectangle operator --(const Rectangle& r,int);//������ʱֵ
	//��ֵ����ֻ����Ϊ��Ա��������
	friend bool operator >(const Rectangle& r1, const Rectangle& r2);//ֻΪ������>��<���������֮һ
	friend Rectangle& operator +=(const Rectangle& r1, const Rectangle& r2);
	friend Rectangle& operator -=(const Rectangle& r1, const Rectangle& r2);
	friend Rectangle& operator ==(const Rectangle& r1, const Rectangle& r2);
	*/

private:
	int length;
	int width;
};







#endif