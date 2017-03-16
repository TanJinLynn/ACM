// Lowest Bit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	int n, num;
	while (cin >> n)
	{
		num = 0;
		if (n == 0)break;
		while (n % 2 != 1)
		{
			num++;
			n = n / 2;
		}
		cout << pow(2.0, num*1.0) << endl;
	}
	return 0;
}

