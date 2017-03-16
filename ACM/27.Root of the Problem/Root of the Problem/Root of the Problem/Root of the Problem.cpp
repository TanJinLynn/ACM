// Root of the Problem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	double B, N;
	int A;
	while (cin>>B>>N)
	{
		if (B == 0 && N == 0)break;
		{
			A = pow(B, 1 / N);
			if (B - pow(A, N) < pow(A + 1, N) - B)
				cout << A << endl;
			else
				cout << A + 1 << endl;
		}
	}
	return 0;
}

