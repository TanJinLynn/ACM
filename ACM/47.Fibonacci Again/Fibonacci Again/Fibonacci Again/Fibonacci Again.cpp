// Fibonacci Again.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
vector<unsigned int>v;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	unsigned int n1, n2, t;
	unsigned int n;
	int i;
	n1 = 7 % 3;
	n2 = 11 % 3;
	v.push_back(n1);
	v.push_back(n2);
	for (i = 2; i <= 1000000; i++){
		t = (n1 + n2) % 3;
		v.push_back(t);
		n1 = n2;
		n2 = t;
	}
	while (cin>>n)
	{
		if (v[n] % 3 == 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}

