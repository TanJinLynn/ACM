// 43.Drivisor Summation.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//1��ÿ������Լ��
	m[1] = 0;//1û�г�1���Լ��
	for (i = 2; i <= 500000; i++)
		m[i] = 1;
	//��ʼͳ��ÿ������Լ����
	for ( i = 2; i <=d; i++)
	{
		m[i*i] += i;
		for (j = i + 1; j <= (500000 / i); j++){
			m[i*j] += (i + j);
		}
	}
	cin>>n;
//	scanf("%d",&n);//������һ������
	//����cin���룬�����س�ʱ
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


