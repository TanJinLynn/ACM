// Beat the Spread.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cin >> n;//������һ������
	while (cin >> a >> b){
		//�ͱȲ�С��������
		if (a < b){
			cout << "impossible" << endl;
			continue;
		}
		//����ֻ������Ȼ��(����0)
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

