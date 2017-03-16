// Longest Ordered Subsequence.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
//定义结构体Info，用来保存一个终点数据的信息
struct Info
{
	int index;//该数据的序号,1,2,3,...,n
	int a;//该数据
	int length;//以该数据为终点的最长子系列长度
};
vector<Info> v;//定义向量v来保存所有的终点数据信息

int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	Info info;
	//测试案例个数为c
	int c;
	//每个测试案例的个数
	int t;
	//单个元素
	int e;
	//元素计数器
	int n;
	//子序列的最大长度
	int m;
	int i, j, k,p;
	cin >> c;
	for (i = 0; i < c; i++)//共有c组测试案例
	{
		//清空向量
		v.clear();
		//初始化元素计时器
		n = 0;
		//读入每个测试案例的个数
		cin >> t;
		//开始计算一个测试案例
		for (j = 0; j < t; j++){
			cin >> e;//读入一个元素
			n++;//元素数量加1
			//一定要先增加一个结构体元素，再对结构体的各变量赋值
			v.push_back(info);
			v[n - 1].index = n;
			v[n - 1].a = e;
			if (n == 1)//是第一个元素
			{
				v[n - 1].length = 1;
				continue;
			}
			//找出位于本元素之前，比本元素小但子序列最长的那个长度值
			m = 0;
			for (k = 0; k < n; k++){
				if (v[k].a < e){
					if (v[k].length>m) m = v[k].length;
				}
			}
			v[n - 1].length = m + 1;
		}
		//找出本组测试案例中最长子序列的长度值
		m = 0;
		for (p = 0; p < n; p++){
			if (v[p].length>m)m = v[p].length;
		}
		//输出结果，注意，输出块之间有一空行
		if (i != 0)cout << endl;//不是第一行，先输出一行空行
		cout << m << endl;
	}
	return 0;
}

