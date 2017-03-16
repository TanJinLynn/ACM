// Let the Balloon Rise.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	map<string, int>m;
	int n;
	int i;
	string s;
	map<string, int>::iterator it, it2;
	while (cin>>n)
	{
		if(n==0) break;
		m.clear();
		for(i=0;i<n;i++){
			cin>>s;
			//在映照容器中查找键值
			if (m.find(s)!=m.end())
				m[s]=m[s]+1;
			else
				m[s]=1;
		}
		it2=m.begin();
		for(it=m.begin();it!=m.end();it++){
			//注意，映照容器中，元素的键值为it->first
			//元素映照值为it->second
			if(it2->second<it->second)
				it2=it;
		}
		cout<<it2->first<<endl;
	}
	return 0;
}

