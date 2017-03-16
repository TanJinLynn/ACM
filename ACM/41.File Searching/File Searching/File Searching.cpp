// File Searching.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	string s, ss, left, right;
	vector<string>v, end;
	int m, n;
	int i, j, k;
	int p, q;
	int c = 0;
	while (cin>>m)
	{
		//��������
		c++;
		if (c > 1) cout << endl;
		//���뱾���������ļ���
		v.clear();
		for (i = 0; i < m; i++){
			cin >> s;
			v.push_back(s);
		}
		//����Ҫ��ѯ���ļ���
		cin >> n;
		for ( i = 0; i < n; i++)
		{
			//����һ��Ҫ��ѯ���ļ���
			cin >> ss;
			//��ʼ��left��right
			left = "";
			right = "";
			//��ss����*�����߷ֳ�left��right������
			p = ss.find("*");
			//���ֳ�left
			for (j = 0; j < p; j++)
				left += ss[j];
			//���ֳ�right
			for (j = p + 1; j < ss.length(); j++)
				right += ss[j];
			//��ղ�ѯ�������
			end.clear();
			//��ʼ����
			for (j = 0; j < v.size(); j++)
			{
				//�ļ������Ȳ���С�ڲ�ѯ��*����߼��ұߵĳ���
				if (v[j].size()<(left.size()+right.size()))
					continue;
				//�Ƚϲ�ѯ��*����ߴ�
				if (left.size() != 0){
					if (v[j].find(left) != 0) continue;
				}
				//�Ƚϲ�ѯ��*���ұߴ�
				if (right.size() != 0){
					//��ת
					reverse(right.begin(), right.end());
					reverse(v[j].begin(), v[j].end());
					if (v[j].find(right) != 0){
						reverse(right.begin(), right.end());
						reverse(v[j].begin(), v[j].end());
						continue;
					}
					//���·�ת��
					reverse(right.begin(), right.end());
					reverse(v[j].begin(), v[j].end());
				}
				//���������ķ���������
				end.push_back(v[j]);
			}
			//���һ�β�ѯ���
			for (k = 0; k < end.size(); k++){
				cout << end[k];
				if (k != end.size() - 1)
					cout << ", ";
				else
					cout << endl;
			}
			//���û�в�������ʹ�ӡ"FILE NOT FOUND"
			if (end.size() == 0)
				cout << "FILE NOT FOUND" << endl;
		}
	}
	return 0;
}

