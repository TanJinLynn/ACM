// Quick Change.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	int q, d, n, p;
	int m;
	cin >> m;//不理会第一项数据
	int i = 0;
	while (cin>>m)
	{
		q = m / 25;
		m = m % 25;

		d = m / 10;
		m = m % 10;

		n = m / 5;
		m = m % 5;

		p = m;

		i++;
		cout << i << " " << q << " QUARTER(S), " << d << " DIME(S), " << n << " NICKEL(S), " << p << " PENNY(S)" << endl;
	}
	return 0;
}

