// Excuses Excuses.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//�ṹ�壬������������м�������Ĺؼ��ָ���
struct Info{
	//�ַ���
	string s;
	//���ַ��а����˹ؼ��ָ���
	int n;
};
//�Զ���ȽϺ������������ؼ��ֵĶ��٣��ɴ�С����
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
	vector<string>v;//����ؼ���
	vector<Info>vv;//�������ṹ��
	int line=0;
	int i,j,k;
	unsigned int p;
	while(cin>>m>>n){
		v.clear();
		vv.clear();
		line++;//������
		//����ؼ���
		for(i=0;i<m;i++)
		{
			cin>>ss;
			s=ss;
			v.push_back(s);
		}
		//���Կ��У����������Ҫ
		//��Ϊcin���뵥�����Ȼ��һ���س������ڱ���
		//������ֱ��ת��cin.getline����һ���У���һ�ζ�����Ǹ�����
		cin.getline(ss,71);
		//���������
		for(i=0;i<n;i++)
		{
			cin.getline(ss,71);
			s=ss;
			//Ϊ��ʵ�ֲ����ִ�Сд�Ƚ�
			//�Ȱѱ��ж����Сд���ٱȽ�
			for(j=0;j<s.size();j++)
			{
				//����Ǵ�д��ĸ��ת��ΪСд��ĸ
				if(s[j]>=65&&s[j]<=90)
					s[j]+=32;
			}
			info.n=0;
			//�������а������ٸ��ؼ���
			for(j=0;j<v.size();j++)
			{	
				for(k=0;k<s.size()-v[j].size();k++)
				{
				//ȡ��һ���ִ�
				t = "";
				for (p = k; p < k + v[j].size(); p++)
				{
					t = t + s[p];
				}
				//����Ӵ����ͷ���Ӵ���һλ�ò�������ĸ
				if (k == 0 && v[j] == t && (s[p]<'a' || s[p]>'z'))
					info.n++;
				//����ִ����������е�����λ��
				//��ô���ִ���ǰһλ�úͺ�һλ�ò�������ĸ
				else if (v[j] == t && (s[p] < 'a' || s[p]>'z') && (s[k - 1]<'a' || s[k - 1]>'z'))
					info.n++;
				}
			}
		//�ַ��������ܱ䣬����ԭ��
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

