// Semi-Prime.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

//����ȫ��������������������
vector<int>v;
//��ȫ���ڴ��ж���ȫ�ּ����������������������
//������ƽ������������������ٶ����
set<int> s;
//����[a,b]��Χ�ڵ�������
void pt(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		//2���������������2�ı���
		if (i != 2 && i % 2 == 0) continue;
		//��������ı���
		for (int j = 3; j*j<=i; j+=2)
		{
			if (i%j == 0) goto RL;
		}
		//����������������
		v.push_back(i);
	RL:continue;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	//����[2,500000]��Χ�ڵ�������
	pt(2, 500000);
	//����2~100000��Χ�ڵİ������������������
	int i, j, p;
	for (i = 0; i < v.size(); i++){
		for (j = 0; j < v.size(); j++){
			p = v[i] * v[j];
			if (p < 1000000)
				s.insert(p);
			else
				break;
		}
	}
	//�������ݣ��ڰ��������в��ң����Ƿ���ڸñ�
	int n;
	set<int>::iterator it;
	while (cin>>n)
	{
		it = s.find(n);
		if (it != s.end())
			cout << "Yes" << endl;
		else
			cout <<"No" << endl;
	}

	return 0;
}

