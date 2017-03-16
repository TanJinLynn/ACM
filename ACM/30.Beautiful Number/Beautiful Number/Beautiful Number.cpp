// Beautiful Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
using namespace std;
//建立全局映照容器保存漂亮数
//映照容器是黑白树，检索快
map<int, int> m;
int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	//建立第1到第10000个漂亮数表
	int i = 0;
	int p = 0;
	while (1){
		i++;
		if (i % 3 == 0 || i % 5 == 0){
			p++;
			if (p > 100000) break;//到了第10000个漂亮数就退出
			m[p] = i;
		}
	}
	//读入数据，并从映照容器中检索
	int n;
	map<int, int>::iterator it;
	while (cin >> n)
	{
		cout << m[n] << endl;
	}
	return 0;
}

