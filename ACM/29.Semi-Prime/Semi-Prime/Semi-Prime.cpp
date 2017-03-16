// Semi-Prime.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

//建立全局向量，用来保存素数
vector<int>v;
//在全局内存中定义全局集合容器，用来保存半素数
//集合是平衡检索二叉树，搜索速度最快
set<int> s;
//建立[a,b]范围内的素数表
void pt(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		//2是素数，这是清除2的倍数
		if (i != 2 && i % 2 == 0) continue;
		//清除素数的倍数
		for (int j = 3; j*j<=i; j+=2)
		{
			if (i%j == 0) goto RL;
		}
		//放入向量，不排序
		v.push_back(i);
	RL:continue;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	//建立[2,500000]范围内的素数表
	pt(2, 500000);
	//建立2~100000范围内的半素数表，两个素数相乘
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
	//读入数据，在半素数表中查找，看是否存在该表
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

