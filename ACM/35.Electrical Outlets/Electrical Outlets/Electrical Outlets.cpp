// Electrical Outlets.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	int n;
	vector<int>v;
	int i, num, sum;
	cin >> n;//������һ������
	while (cin >> n){
		v.clear();
		sum = 0;//���
		for (i = 0; i < n; i++)
		{
			cin >> num;
			v.push_back(num);
		}
		//����������������������Ĳ������
		for (i = 0; i < v.size(); i++){
			if (i != v.size() - 1)//�������һ�������
				sum = sum + v[i] - 1;
			else
				sum = sum + v[i];
		}
		//����ṩ�������
		cout << sum << endl;
	}
	return 0;
}

