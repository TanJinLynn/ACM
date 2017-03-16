// No Brainer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	int a, b;
	cin >> a;
	while (cin >> a>>b)
	{
		if (a < b) cout << "NO BRAINS" << endl;
		else
			cout << "MMM BRAINS" << endl;
	}
	return 0;
}

