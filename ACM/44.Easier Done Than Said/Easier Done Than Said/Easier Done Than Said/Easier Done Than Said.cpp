// Easier Done Than Said.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	string s;
	int a, b;
	int i, t;
	while (cin >> s){
		if (s == "end") break;
		//����1:���뺬��һ��Ԫ��a,e,i,o,u��Ԫ��
		if (s.find("a") > s.size() && s.find("e") > s.size() && s.find("i") > s.size() && s.find("o") > s.size() && s.find("u") > s.size())
		{
			cout << "<" << s << ">" << " is not acceptable." << endl;
			continue;
		}
		//����2:���ܰ���3������Ԫ����������������
		a = 0;//����Ԫ������
		b = 0;//������������
		for (i = 0; i < s.size(); i++){
			//�ж���Ԫ�����Ǹ�����ĸ
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
				if (i == 0) a = 1;
				else
				{
					if (s[i - 1] == 'a' || s[i - 1] == 'e' || s[i - 1] == 'i' || s[i - 1] == 'o' || s[i - 1] == 'u'){
						a++;
						b = 0;
					}
					else
					{
						a = 1;
						b = 0;
					}
				}
			}
			else
			{
				if (i == 0)b = 1;
				else
				{
					if (s[i - 1] != 'a' || s[i - 1] != 'e' || s[i - 1] != 'i' || s[i - 1] != 'o' || s[i - 1] != 'u'){
						b++;
						a= 0;
					}
					else
					{
						b = 1;
						a = 0;
					}
				}
			}
			//�������������ģ�����ֹ
			if(a==3||b==3)
			{
				cout<<"<"<<s<<">"<<" is not acceptable."<<endl;
				goto RL;
			}
		}
		//����3:���ܰ�������������ĸ����ee��oo����
		t=0;
		for(i=0;i<s.size();i++){
			if(i==0)t=1;
			else if(s[i]=='e'||s[i]=='o')
				t=0;
			else
			{
				if(s[i]==s[i-1])t++;
				else t=1;
			}
			if(t==2)
			{
				cout<<"<"<<s<<">"<<" is not acceptable."<<endl;
				goto RL;
			}
		}
		cout<<"<"<<s<<">"<<" is acceptable."<<endl;
		RL:
			continue;
	}
	return 0;
}



