// Champion of the Swordsmanship.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	int n, d, m, sum = 0;
	while (cin>>n)
	{
		if (n == 0) break;
		sum = 0;
		while (1)
		{
			if (n == 1){
				cout << sum << endl;
				break;
			}
			if (n == 2){
				cout << sum + 1 << endl;
				break;
			}
			d = n / 3;
			m = n % 3;
			n = d + m;
			sum = sum + d;
		}
	}
	return 0;
}

