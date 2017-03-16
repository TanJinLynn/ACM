// Total Amount.cpp : 定义控制台应用程序的入口点。
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
	//定义映照容器
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
	//定义映照容器
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
	//进位标记，0表示无进位，1表示有进位
	int flag = 0;

	while (cin>>n)
	{
		if (n == 0) break;
		for (i = 0; i < n; i++){
			cin >> sb;
			//删除"$"符号
			sb.erase(0,1);
			//删除","符号
			t = "";
			for (j = 0; j < sb.size(); j++){
				if (sb[j] != ',') t+= sb[j];
			}
			sb = t;
			//反转字符
			reverse(sb.begin(), sb.end());
			//删除"."符号
			sb.erase(2, 1);
			//读入的是第一个字符串
			if (i == 0) sa = sb;
			//sa+sb
			else
			{
				//进位标志设为0，即无进位
				flag = 0;
				//把长的字符串放到sa里
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
						pc = pc - 10;//本位
						flag = 1;//有进位
					}
					else flag = 0;//进位标记清0
					sa[j] = mm[pc];
				}
				//如果有进位，则需再加一位
				if (flag == 1) sa += "1";
			}
		}
		//加入小数点和逗号
		t = "";
		for (i = 0; i < sa.size(); i++)
		{
			t = t + sa[i];
			//加"."号
			if (i == 1) t = t + ".";
			//加","号
			if (i != 1 && (i - 1) % 3 == 0 && i != (sa.size() - 1))
				t = t + ",";
		}
		sa = t;
		//反向输出结果
		cout << "$";
		for (i = sa.size() - 1; i >= 0; i--)
			cout << sa[i];
		cout << endl;
	}
	return 0;
}

