#include "A.h"

A operator /(A a1, A a2)
{
	if (a1.num1 > a2.num1)
		a1.sum1 = a1.num1 / a2.num1;
	else if (a1.num1 >  a2.num1)
		a1.sum1 =a2.num1 / a1.num1;
	if (a1.num2 > a2.num2)
		a1.sum2 = a1.num2 / a2.num2;
	else if (a2.num2 > a1.num2)
		a1.sum2 = a2.num2 / a1.num2;
	return a1;
}
void main()
{
	A ov1(10,20),ov2(5,40);
	ov1.Print();
	ov2.Print();
	ov1 = ov1 / ov2;
	ov1.Print_sum();
}