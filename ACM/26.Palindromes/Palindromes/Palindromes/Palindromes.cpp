// Palindromes.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	char s[5000];
	int p,i,Half,Left,Right,Count;
	while(cin>>s)
	{
		i=strlen(s);
		Count=0;//�ܻ�����
		//�����Ҷ�ס���һ��
		for (p= 0; p < i-1; p++)
		{
			Half = ((i - 1) - p) / 2;
			//����Ӵ���ż�����ַ�
			if (((i - 1) - p) % 2 == 0){
				Left = p + Half - 1;
				Right = p + Half + 1;
			}
			else//����Ӵ����������ַ�
			{
				Left = p + Half;
				Right = p + Half + 1;
			}
			while (Left>=p)
			{
				if (s[Left] == s[Right]){
					Count++;//������һ�����Ĵ�
					Left--;
					Right++;
				}
				else
				{
					//�������ȣ�������ֹ��������������ɢ�����ܻ��л��Ĵ�
					break;
				}
			}
		}
		//���ҵ���ס��һ��
		for (p = i-2; p >=1; p--)
		{
			Half = p / 2;
			//����Ӵ���������
			if (p % 2 == 0){
				Left = Half - 1;
				Right = Half + 1;
			}
			else
			{
				//����Ӵ���ż����
				Left = Half;
				Right = Half + 1;
			}
			while (Left>=0)
			{
				if (s[Left] == s[Right]){
					Count++;//����һ�����Ĵ�
					Left--;
					Right++;
				}
				else
				{
					//�������ȣ�������ֹ��������������ɢ�����ܻ��л��Ĵ�
					break;
				}
			}
		}
		cout << Count + i;
	}
	return 0;
}

