#include<iostream>
using namespace std;
class Student
{
public:
	Student(int n, float s) :num(n), score(s){}
	
	void change(int n, float s)
	{
		num = n;
		score = s;
	}
	void display()
	{
		cout <<"修改代码后的输出结果："<< num << " " << score << endl;
	}
	
	
private:
	int num;
	float score;
};

void fun(Student& stu)
{
	stu.change(101, 80.5);
	stu.display();
}

int main()
{
	Student stud(101, 78.5);
	stud.display();
	fun(stud);
	/*stud.display();
	stud.change(101, 80.5);
	stud.display();*/
	return 0;
}