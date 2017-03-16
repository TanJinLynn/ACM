#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool comp(const string &s1,const string &s2)
{
	int i,j,k,m,n;
	int c1=0,c2=0;
	//计算s1需要移动的次数c1
	for(i=0;i<s1.size();i++){
		for(j=i+1;j<s1.size();j++){
			if(s1[i]>s1[j])
				c1++;
		}
	}
	//计算s2需要移动的次数c2
	for(i=0;i<s2.size();i++){
		for(j=i+1;j<s2.size();j++){
			if(s2[i]>s2[j])
				c2++;
		}
	}
	//如果两行字符串移动的次数相同，那么按原先固有的位置排序
	return c1!=c2?c1<c2:c1<c2; 
}

int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	string s;
	vector<string>v;
	int n,a,b;
	cin>>n;
	int i,j,k;
	int p=0;//块数 
	for(i=0;i<n;i++){//读入n组case 
		cin.clear();
		cin>>a>>b;
		v.clear();//清空向量 
		p++;//增加一块 
		for(j=0;j<b;j++)//读入一组中的a行字符
		{
			cin>>s;
			v.push_back(s);	
		}
		//按comp排序规则排序
		sort(v.begin(),v.end(),comp);
		if(p!=1)cout<<endl;//不是第一行，产生一新空行
		//输出v向量中的每个元素
		for(k=0;k<v.size();k++){
			cout<<v[k]<<endl;
		} 
	}
	return 0;
}
