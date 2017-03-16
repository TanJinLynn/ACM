// Beat the Spread.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	int n, x, y, a, b;
	cin >> n;//不理会第一个数字
	while (cin >> a >> b){
		//和比差小，不成立
		if (a < b){
			cout << "impossible" << endl;
			continue;
		}
		//分数只能是自然数(包括0)
		if ((a + b) % 2 != 0 || abs(a - b) % 2 != 0)
		{
			cout << "impossible" << endl;
			continue;
		}
		x = abs((a + b) / 2);
		y = abs((a - b) / 2);
		if (x > y)
			cout << x << " " << y << endl;
		else
			cout << y << " " << x << endl;
	}
	return 0;
}

