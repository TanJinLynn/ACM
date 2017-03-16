// Easier Done Than Said.cpp : 定义控制台应用程序的入口点。
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
		//条件1:必须含有一个元音a,e,i,o,u是元音
		if (s.find("a") > s.size() && s.find("e") > s.size() && s.find("i") > s.size() && s.find("o") > s.size() && s.find("u") > s.size())
		{
			cout << "<" << s << ">" << " is not acceptable." << endl;
			continue;
		}
		//条件2:不能包含3个连续元音或三个连续辅音
		a = 0;//连续元音个数
		b = 0;//连续辅音个数
		for (i = 0; i < s.size(); i++){
			//判断是元音还是辅音字母
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
			//出现三个连续的，就终止
			if(a==3||b==3)
			{
				cout<<"<"<<s<<">"<<" is not acceptable."<<endl;
				goto RL;
			}
		}
		//条件3:不能包含两个连续字母，但ee和oo除外
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



