/*
程序说明：扩展欧几里得算法，计算最大公约数和乘法逆元。
*/

#include "stdafx.h"

int exgcd(int a, int b, int &x, int &y); 

int main()
{
	int a,b,x,y;   //x,y用来存放ax+by=1(等价于ax≡1 mod b)的解。
	printf("请输入两个正整数：\n");
	scanf_s("%d%d", &a, &b);    
	int r=exgcd(a, b, x, y);    
	printf("%d和%d的最大公约数是：%d\n", a, b, r);    //a,b的值没有发生改变。
	while (x < 0)	
	{
		x += b;	//输出正整数解。
	}
	y = (1 - a * x) / b;
	printf("%d和%d构成的贝祖等式的一组整数解为：%d,%d", a, b, x, y); 
    return 0;
}

/*
函数说明：运用扩展欧几里得算法，计算最大公约数和乘法逆元。
*/
int exgcd(int a, int b, int &x, int &y)	//注意&x,&y传入的是x,y的地址。
{
	if (b == 0)     //gcd(a,0)=a。
	{
		x = 1;
		y = 0;
		return a;    //此时a是最大公约数。
	}

	int r = exgcd(b, a%b, x, y);      
	int t = y;
		y = x - (a / b) * y;
		x = t;

	return r;   //r的值在回调时不会改变。
}