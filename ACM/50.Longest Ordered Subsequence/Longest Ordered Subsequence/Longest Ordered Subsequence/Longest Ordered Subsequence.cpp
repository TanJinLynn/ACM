// Longest Ordered Subsequence.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
//����ṹ��Info����������һ���յ����ݵ���Ϣ
struct Info
{
	int index;//�����ݵ����,1,2,3,...,n
	int a;//������
	int length;//�Ը�����Ϊ�յ�����ϵ�г���
};
vector<Info> v;//��������v���������е��յ�������Ϣ

int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	Info info;
	//���԰�������Ϊc
	int c;
	//ÿ�����԰����ĸ���
	int t;
	//����Ԫ��
	int e;
	//Ԫ�ؼ�����
	int n;
	//�����е���󳤶�
	int m;
	int i, j, k,p;
	cin >> c;
	for (i = 0; i < c; i++)//����c����԰���
	{
		//�������
		v.clear();
		//��ʼ��Ԫ�ؼ�ʱ��
		n = 0;
		//����ÿ�����԰����ĸ���
		cin >> t;
		//��ʼ����һ�����԰���
		for (j = 0; j < t; j++){
			cin >> e;//����һ��Ԫ��
			n++;//Ԫ��������1
			//һ��Ҫ������һ���ṹ��Ԫ�أ��ٶԽṹ��ĸ�������ֵ
			v.push_back(info);
			v[n - 1].index = n;
			v[n - 1].a = e;
			if (n == 1)//�ǵ�һ��Ԫ��
			{
				v[n - 1].length = 1;
				continue;
			}
			//�ҳ�λ�ڱ�Ԫ��֮ǰ���ȱ�Ԫ��С������������Ǹ�����ֵ
			m = 0;
			for (k = 0; k < n; k++){
				if (v[k].a < e){
					if (v[k].length>m) m = v[k].length;
				}
			}
			v[n - 1].length = m + 1;
		}
		//�ҳ�������԰�����������еĳ���ֵ
		m = 0;
		for (p = 0; p < n; p++){
			if (v[p].length>m)m = v[p].length;
		}
		//��������ע�⣬�����֮����һ����
		if (i != 0)cout << endl;//���ǵ�һ�У������һ�п���
		cout << m << endl;
	}
	return 0;
}

