// Magic Square.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <set>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	int matrix[9][9];
	int line[9], column[9];//每行和每列的和
	int a, b;//两条对角线的和
	set<int>s;//set不会重复插入相同键值的元素，而存取忽略处理
	int n, i, j;
	while (cin>>n)
	{
		if (n == 0) break;
		//读入矩阵
		for ( i = 0; i < n; i++)
		{
			for (j= 0; j <n; j++)
			{
				cin >> matrix[i][j];
			}
		}
		s.clear();//清空集合
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				//把每个元素放到集合中，重复数据不会插入
				//all the numbers in the input do not exceed 1000
				//说明矩阵块中的元素的范围是1~1000，而不限于在1~n*n范围内
				s.insert(matrix[i][j]);
			}
		}
		if (s.size() != n*n){
			cout << "No" << endl;
			continue;
		}
		//计算每行，每列，每条对角线的和
		a = 0;
		b = 0;
		for (i = 0; i < n; i++){
			line[i] = 0;
			column[i] = 0;
		}
		for ( i = 0; i < n; i++)
		{
			for ( j = 0; j < n; j++)
			{
				line[i] += matrix[i][j];
				column[j] += matrix[i][j];
				if (i == j) a = a + matrix[i][j];
				if (i + j == n - 1)b = b + matrix[i][j];
			}
		}
		//判断每行、每列、两条对角线的和是否完全相等
		s.clear();//清空集合
		s.insert(a);
		s.insert(b);
		for (i = 0; i < n; i++){
			s.insert(line[i]);
			s.insert(column[i]);
		}
		if (s.size() != 1) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}

