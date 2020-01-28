#include<iostream>
using namespace std;

class A
{
	int num1, num2;
	int sum1, sum2;
public:
	A (int x, int y) : num1(x), num2(y){}
	void Print() { cout << "x = " << num1 << " y = " << num2<< endl; }
	void Print_sum() { cout << "x = " << sum1 << "y = " << sum2 << endl; }
	friend A operator / (A a1, A a2);
	~A();
};
