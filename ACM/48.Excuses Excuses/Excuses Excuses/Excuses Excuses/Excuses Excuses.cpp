// Excuses Excuses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//结构体，用来保存语句行及其包含的关键字个数
struct Info{
	//字符行
	string s;
	//本字符行包含了关键字个数
	int n;
};
//自定义比较函数，按包含关键字的多少，由大到小排列
bool comp(const Info &a,const Info &b)
{
	return a.n>b.n;
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	Info info;
	int m,n;
	char ss[71];
	string s,t;
	vector<string>v;//保存关键词
	vector<Info>vv;//保存语句结构体
	int line=0;
	int i,j,k;
	unsigned int p;
	while(cin>>m>>n){
		v.clear();
		vv.clear();
		line++;//案例号
		//读入关键词
		for(i=0;i<m;i++)
		{
			cin>>ss;
			s=ss;
			v.push_back(s);
		}
		//忽略空行，这句至关重要
		//因为cin读入单项后，仍然有一个回车符留在本行
		//这样，直接转入cin.getline读入一整行，第一次读入的是个空行
		cin.getline(ss,71);
		//读入语句行
		for(i=0;i<n;i++)
		{
			cin.getline(ss,71);
			s=ss;
			//为了实现不区分大小写比较
			//先把本行都变成小写后再比较
			for(j=0;j<s.size();j++)
			{
				//如果是大写字母则转化为小写字母
				if(s[j]>=65&&s[j]<=90)
					s[j]+=32;
			}
			info.n=0;
			//搜索本行包含多少个关键词
			for(j=0;j<v.size();j++)
			{	
				for(k=0;k<s.size()-v[j].size();k++)
				{
				//取出一个字串
				t = "";
				for (p = k; p < k + v[j].size(); p++)
				{
					t = t + s[p];
				}
				//如果子串在最开头，子串后一位置不能是字母
				if (k == 0 && v[j] == t && (s[p]<'a' || s[p]>'z'))
					info.n++;
				//如果字串出现在这行的其他位置
				//那么。字串的前一位置和后一位置不能是字母
				else if (v[j] == t && (s[p] < 'a' || s[p]>'z') && (s[k - 1]<'a' || s[k - 1]>'z'))
					info.n++;
				}
			}
		//字符串本身不能变，保持原样
		info.s = ss;
		vv.push_back(info);
		}
		sort(vv.begin(),vv.end(),comp); 
		cout << "Excuse Set #" << line << endl;
		for (i = 0; i < vv.size(); i++)
		{
			if (i != 0 && vv[i].n < vv[i - 1].n)
				break;
			else
			{
				cout << vv[i].s << endl;
			}
		}
	}
	

	return 0;
}

