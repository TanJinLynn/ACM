// Electrical Outlets.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	int n;
	vector<int>v;
	int i, num, sum;
	cin >> n;//不理会第一个数字
	while (cin >> n){
		v.clear();
		sum = 0;//清空
		for (i = 0; i < n; i++)
		{
			cin >> num;
			v.push_back(num);
		}
		//计算可用来插入其他电器的插口数量
		for (i = 0; i < v.size(); i++){
			if (i != v.size() - 1)//不是最后一个插件板
				sum = sum + v[i] - 1;
			else
				sum = sum + v[i];
		}
		//输出提供插口数量
		cout << sum << endl;
	}
	return 0;
}

