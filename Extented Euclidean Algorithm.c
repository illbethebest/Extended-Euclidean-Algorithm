/*
程序说明：扩展欧几里得算法，计算最大公约数和乘法逆元。
*/

#include "stdafx.h"

int exgcd(int Coprime_Number1, int Coprime_Number2, int &Inverse_Of_X, int &Inverse_Of_Y); 

int main()
{
	int Coprime_Number1,Coprime_Number2；
	int Inverse_Of_X,Inverse_Of_Y;   //用来存放ax+by=1(等价于ax≡1 mod b)的解。
	printf("请输入两个正整数：\n");
	scanf_s("%d%d", &Coprime_Number1, &Coprime_Number2);    
	int Greatest_Common_Divisor=exgcd(Coprime_Number1, Coprime_Number2, Inverse_Of_X, Inverse_Of_Y);    
	printf("%d和%d的最大公约数是：%d\n", Coprime_Number1, Coprime_Number2, Greatest_Common_Divisor);   
	while (Inverse_Of_X < 0)	
	{
		Inverse_Of_X += Coprime_Number2;	//输出正整数解。
	}
	Inverse_Of_Y = (1 - Coprime_Number1 * Inverse_Of_X) / Coprime_Number2;
	printf("%d和%d构成的贝祖等式的一组整数解为：%d,%d", Coprime_Number1, Coprime_Number2, Inverse_Of_X, Inverse_Of_Y); 
    return 0;
}

/*
函数说明：运用扩展欧几里得算法，计算最大公约数和乘法逆元。
*/
int exgcd(int Coprime_Number1, int Coprime_Number2, int &Inverse_Of_X, int &Inverse_Of_Y)	//注意传入的是地址。
{
	if (Coprime_Number2 == 0)     //gcd(Coprime_Number1,0)=Coprime_Number1。
	{
		Inverse_Of_X = 1;
		Inverse_Of_Y = 0;
		return Coprime_Number1;    //此时Coprime_Number1是最大公约数。
	}

	int Greatest_Common_Divisor = exgcd(Coprime_Number2, Coprime_Number1%Coprime_Number2, Inverse_Of_X, Inverse_Of_Y);      
	int Middle_Number = Inverse_Of_Y;
		Inverse_Of_Y = Inverse_Of_X - (Coprime_Number1 / Coprime_Number2) * Inverse_Of_Y;
		Inverse_Of_X = Middle_Number;

	return Greatest_Common_Divisor;   //Greatest_Common_Divisor的值在回调时不会改变。
}