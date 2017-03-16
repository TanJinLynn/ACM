// File Searching.cpp : 定义控制台应用程序的入口点。
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
		//测试数量
		c++;
		if (c > 1) cout << endl;
		//读入本例子所有文件名
		v.clear();
		for (i = 0; i < m; i++){
			cin >> s;
			v.push_back(s);
		}
		//读入要查询的文件名
		cin >> n;
		for ( i = 0; i < n; i++)
		{
			//读入一个要查询的文件名
			cin >> ss;
			//初始化left和right
			left = "";
			right = "";
			//把ss根据*号两边分出left和right两部分
			p = ss.find("*");
			//区分出left
			for (j = 0; j < p; j++)
				left += ss[j];
			//区分出right
			for (j = p + 1; j < ss.length(); j++)
				right += ss[j];
			//清空查询结果容器
			end.clear();
			//开始查找
			for (j = 0; j < v.size(); j++)
			{
				//文件名长度不能小于查询串*号左边加右边的长度
				if (v[j].size()<(left.size()+right.size()))
					continue;
				//比较查询串*号左边串
				if (left.size() != 0){
					if (v[j].find(left) != 0) continue;
				}
				//比较查询串*号右边串
				if (right.size() != 0){
					//反转
					reverse(right.begin(), right.end());
					reverse(v[j].begin(), v[j].end());
					if (v[j].find(right) != 0){
						reverse(right.begin(), right.end());
						reverse(v[j].begin(), v[j].end());
						continue;
					}
					//重新反转来
					reverse(right.begin(), right.end());
					reverse(v[j].begin(), v[j].end());
				}
				//符合条件的放入向量中
				end.push_back(v[j]);
			}
			//输出一次查询结果
			for (k = 0; k < end.size(); k++){
				cout << end[k];
				if (k != end.size() - 1)
					cout << ", ";
				else
					cout << endl;
			}
			//如果没有查出来，就打印"FILE NOT FOUND"
			if (end.size() == 0)
				cout << "FILE NOT FOUND" << endl;
		}
	}
	return 0;
}

