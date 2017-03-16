// Phone List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	vector<string> v;
	//char ch[10];
	string s;
	int n;
	cin>>n;//不理会总块数
	int i,j;
	while(cin>>n){
		v.clear();
		for(i=0;i<n;i++){
			cin>>s;
			//scanf("%s",&ch);
			//s=ch;
			v.push_back(s);
		}
		sort(v.begin(),v.end());
		for(i=0;i<n-1;i++){
			if (v[i+1].find(v[i])==0)
			{	
				cout << "No" << endl;
				//printf("No\n");
				goto RL;
			}
		}
		cout << "Yes" << endl;
		//printf("Yes\n");
	RL:
		continue; 
	}
	return 0;
}

