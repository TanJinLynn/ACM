// Old Bill.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//�ṹ�壬��������������ݵĽṹ
struct  Info
{
	int first;
	int last;
	int average;
};
//�Զ���ȽϺ��������һ������ɴ�С����
bool comp(const Info &a, const Info &b){
	if (a.average != b.average) return a.average > b.average;
}
int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	Info info;
	vector <Info>v;
	int i, j;
	int n;
	int x, y, z, m;
	cin >> n;//������һ������
	while (cin>>n)		
	{
		cin >> x >> y >> z;
		m = x * 1000 + 100 * y + 10 * z;
		//�������
		v.clear();
		//������Ҫ������
		for (i = 1; i < 10; i++)
		{
			for (i = 0; j < 10; j++)
			{
				if ((i * 10000 + m + j) % n == 0)
				{	
					info.first = i;
					info.last = j;
					info.average = (i * 10000 + m + j) / n;
					v.push_back(info);
				}
			}
		}
		//���һ��������ɴ�С����
		sort(v.begin(), v.end(), comp);
		//�������
		if (v.size() == 0)
			cout << "0" << endl;
		else
			cout << v[0].first << " " << v[0].last << " " << v[0].average << endl;
	}
	return 0;
}

