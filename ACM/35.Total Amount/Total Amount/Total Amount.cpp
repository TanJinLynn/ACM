// Total Amount.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	string sa, sb, t;
	int pa, pb, pc;//pc=pa+pb;
	//����ӳ������
	map<char, int>m;
	m['0'] = 0;
	m['1'] = 1;
	m['2'] = 2;
	m['3'] = 3;
	m['4'] = 4;
	m['5'] = 5;
	m['6'] = 6;
	m['7'] = 7;
	m['8'] = 8;
	m['9'] = 9;
	//����ӳ������
	map<int, char>mm;
	mm[0] = '0';
	mm[1] = '1';
	mm[2] = '2';
	mm[3] = '3';
	mm[4] = '4';
	mm[5] = '5';
	mm[6] = '6';
	mm[7] = '7';
	mm[8] = '8';
	mm[9] = '9';

	int n, i, j;
	//��λ��ǣ�0��ʾ�޽�λ��1��ʾ�н�λ
	int flag = 0;

	while (cin>>n)
	{
		if (n == 0) break;
		for (i = 0; i < n; i++){
			cin >> sb;
			//ɾ��"$"����
			sb.erase(0,1);
			//ɾ��","����
			t = "";
			for (j = 0; j < sb.size(); j++){
				if (sb[j] != ',') t+= sb[j];
			}
			sb = t;
			//��ת�ַ�
			reverse(sb.begin(), sb.end());
			//ɾ��"."����
			sb.erase(2, 1);
			//������ǵ�һ���ַ���
			if (i == 0) sa = sb;
			//sa+sb
			else
			{
				//��λ��־��Ϊ0�����޽�λ
				flag = 0;
				//�ѳ����ַ����ŵ�sa��
				if (sa.size() < sb.size()){
					t = sa; sa = sb; sb = t;
				}
				for (j = 0; j < sa.size(); j++){
					pa = m[sa[j]];
					if (j >= sb.size()) pb = 0;
					else pb = m[sb[j]];
					pc = pa + pb + flag;
					if (pc>9)
					{
						pc = pc - 10;//��λ
						flag = 1;//�н�λ
					}
					else flag = 0;//��λ�����0
					sa[j] = mm[pc];
				}
				//����н�λ�������ټ�һλ
				if (flag == 1) sa += "1";
			}
		}
		//����С����Ͷ���
		t = "";
		for (i = 0; i < sa.size(); i++)
		{
			t = t + sa[i];
			//��"."��
			if (i == 1) t = t + ".";
			//��","��
			if (i != 1 && (i - 1) % 3 == 0 && i != (sa.size() - 1))
				t = t + ",";
		}
		sa = t;
		//����������
		cout << "$";
		for (i = sa.size() - 1; i >= 0; i--)
			cout << sa[i];
		cout << endl;
	}
	return 0;
}

