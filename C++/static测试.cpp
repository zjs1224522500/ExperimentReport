/*


	静态变量的 存在域为从变量定义开始到文件结束，内存始终都为其分配存储单元，
它可以是局部变量，也可以是全局变量 。但静态变量的 可见域“ 为从“{”后定义开始
到遇到“}”  结束，但仍然 存在内存中
非静态变量 ，其 寿命局限于其块作用域，从“{” 后定义开始到遇到“}” 结束，内存
自动释放空间。在不同作用域中，生命相同的变量名，遵
从局部变量优先的原则（ 在内层，外层同名标识符不可见)

*/
#include<iostream>
using namespace std;
int static b=0;
int main()
{
    int static a=1;
{
    int a=2;
    int static b=3;

    cout<<"a="<<a<<endl;//a=2
    cout<<"b="<<b<<endl;//b=3
}
    cout<<"a="<<a<<endl;//a=1
    cout<<"b="<<b<<endl;//b=0



	return 0;
}
