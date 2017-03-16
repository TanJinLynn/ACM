// Magic Square.cpp : �������̨Ӧ�ó������ڵ㡣
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
	int line[9], column[9];//ÿ�к�ÿ�еĺ�
	int a, b;//�����Խ��ߵĺ�
	set<int>s;//set�����ظ�������ͬ��ֵ��Ԫ�أ�����ȡ���Դ���
	int n, i, j;
	while (cin>>n)
	{
		if (n == 0) break;
		//�������
		for ( i = 0; i < n; i++)
		{
			for (j= 0; j <n; j++)
			{
				cin >> matrix[i][j];
			}
		}
		s.clear();//��ռ���
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				//��ÿ��Ԫ�طŵ������У��ظ����ݲ������
				//all the numbers in the input do not exceed 1000
				//˵��������е�Ԫ�صķ�Χ��1~1000������������1~n*n��Χ��
				s.insert(matrix[i][j]);
			}
		}
		if (s.size() != n*n){
			cout << "No" << endl;
			continue;
		}
		//����ÿ�У�ÿ�У�ÿ���Խ��ߵĺ�
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
		//�ж�ÿ�С�ÿ�С������Խ��ߵĺ��Ƿ���ȫ���
		s.clear();//��ռ���
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

