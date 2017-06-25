#include<iostream>
using namespace std;
class SalesMan
{
public:
	SalesMan(){}
	SalesMan(int num, int quantity, double price)
	{
		singleQuantity = quantity;
		if (quantity>10)
			singlePrice = quantity*price*0.98;
		else
			singlePrice= quantity*price;
		singlePrice *= 0.95;
	}
	void total()
	{
		sumSalePrice += singlePrice;
		sumSaleQuantity += singleQuantity;
	}
	static void display()
	{
		cout << "销售总额：" << sumSalePrice << endl << "平均售价：" 
			<< sumSalePrice / sumSaleQuantity<<endl;
	}
private:
	int singleQuantity;
	double singlePrice;
	static int sumSaleQuantity;
	static double discount;
	static double sumSalePrice;
};
double SalesMan::discount = 0.05;
double SalesMan::sumSalePrice = 0;
int SalesMan::sumSaleQuantity = 0;
int main()
{
	SalesMan S[10];
	int m, i;
	cout << "售货员人数：" ;
	cin >> m;
	int num;
	int quantity;
	double price;
	cout << "销货员号 销货件数 销货单价" << endl;
	for (i = 0; i < m; i++)
	{
		cin >> num >> quantity >> price;
		SalesMan temp(num, quantity, price);
		S[i] = temp;
	}
	for (i = 0; i < m; i++)
		S[i].total();

	SalesMan::display();

	return 0;
}
