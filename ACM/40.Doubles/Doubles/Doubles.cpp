// Doubles.cpp : 定义控制台应用程序的入口点。
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
		//读入一行数据
		if (n != 0){
			s.insert(n);
		}
		//一行已读完了
		if (n == 0)
		{
			//开始处理读入得到这一行数据
			for (it = s.begin(); it != s.end(); it++){
				if (s.find(2 * (*it)) != s.end())//查找到
				{
					sum++;
				}
			}
			cout << sum << endl;
			//初始化各种变量与容器
			sum = 0;
			s.clear();
		}
	}
	return 0;
}

