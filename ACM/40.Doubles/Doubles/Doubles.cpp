// Doubles.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <set>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	set<int>s;
	set<int>::iterator it, itt;
	int sum = 0;
	int n;
	while (cin>>n)
	{
		if (n == -1)break;
		//����һ������
		if (n != 0){
			s.insert(n);
		}
		//һ���Ѷ�����
		if (n == 0)
		{
			//��ʼ�������õ���һ������
			for (it = s.begin(); it != s.end(); it++){
				if (s.find(2 * (*it)) != s.end())//���ҵ�
				{
					sum++;
				}
			}
			cout << sum << endl;
			//��ʼ�����ֱ���������
			sum = 0;
			s.clear();
		}
	}
	return 0;
}

