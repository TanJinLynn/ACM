// Beautiful Number.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
using namespace std;
//����ȫ��ӳ����������Ư����
//ӳ�������Ǻڰ�����������
map<int, int> m;
int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	//������1����10000��Ư������
	int i = 0;
	int p = 0;
	while (1){
		i++;
		if (i % 3 == 0 || i % 5 == 0){
			p++;
			if (p > 100000) break;//���˵�10000��Ư�������˳�
			m[p] = i;
		}
	}
	//�������ݣ�����ӳ�������м���
	int n;
	map<int, int>::iterator it;
	while (cin >> n)
	{
		cout << m[n] << endl;
	}
	return 0;
}

