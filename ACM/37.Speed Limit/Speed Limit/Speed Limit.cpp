// Speed Limit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	int n, a, b, bb, sum, i;
	while (cin >> n){
		if (n == -1) break;
		sum = 0;
		bb = 0;
		for (i = 0; i < n; i++){
			cin >> a >> b;
			if (i == 0)
			{
				bb = b;
				sum = sum + a*bb;
			}
			else
			{
				sum = sum + a*(b - bb);
				bb = b;
			}
		}
		cout << sum << " miles" << endl;
	}
	return 0;
}

