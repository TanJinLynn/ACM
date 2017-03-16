// 43.Drivisor Summation.cpp : 定义控制台应用程序的入口点。
//

#include  <iostream>
#include <fstream>
#include  <cmath>
#include <vector>
using namespace std;
int m[500000];
int main(int argc, char** argv) 
{	
	fstream cin("aaa.txt");
//	freopen("aaa.txt","r",stdin);
	int i, j,k;
	int n,f;
	int d;
	vector<int> v;
	vector<int>::iterator it;
	d = sqrt(500000.0);
	//1是每个数的约数
	m[1] = 0;//1没有除1外的约数
	for (i = 2; i <= 500000; i++)
		m[i] = 1;
	//开始统计每个数的约数和
	for ( i = 2; i <=d; i++)
	{
		m[i*i] += i;
		for (j = i + 1; j <= (500000 / i); j++){
			m[i*j] += (i + j);
		}
	}
	cin>>n;
//	scanf("%d",&n);//不理会第一个数据
	//采用cin输入，会严重超时
	//while (cin>>n)
	for(k=0;k<n;k++)
	{	
		cin>>f;
//	scanf("%d",&f);
		v.push_back(f);
	}
	
	for(it=v.begin();it!=v.end();it++){
		cout<<m[*it]<<endl; 
//		printf("%d\n", m[*it]);
	}
	return 0;
}


