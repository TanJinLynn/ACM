// Old Bill.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//结构体，用来保存输出数据的结构
struct  Info
{
	int first;
	int last;
	int average;
};
//自定义比较函数，按兑换比例由大到小排序
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
	cin >> n;//不理会第一个数据
	while (cin>>n)		
	{
		cin >> x >> y >> z;
		m = x * 1000 + 100 * y + 10 * z;
		//清除向量
		v.clear();
		//计算需要的数据
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
		//按兑换比例数由大到小排序
		sort(v.begin(), v.end(), comp);
		//输出数据
		if (v.size() == 0)
			cout << "0" << endl;
		else
			cout << v[0].first << " " << v[0].last << " " << v[0].average << endl;
	}
	return 0;
}

