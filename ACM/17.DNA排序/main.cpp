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
	//����s1��Ҫ�ƶ��Ĵ���c1
	for(i=0;i<s1.size();i++){
		for(j=i+1;j<s1.size();j++){
			if(s1[i]>s1[j])
				c1++;
		}
	}
	//����s2��Ҫ�ƶ��Ĵ���c2
	for(i=0;i<s2.size();i++){
		for(j=i+1;j<s2.size();j++){
			if(s2[i]>s2[j])
				c2++;
		}
	}
	//��������ַ����ƶ��Ĵ�����ͬ����ô��ԭ�ȹ��е�λ������
	return c1!=c2?c1<c2:c1<c2; 
}

int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	string s;
	vector<string>v;
	int n,a,b;
	cin>>n;
	int i,j,k;
	int p=0;//���� 
	for(i=0;i<n;i++){//����n��case 
		cin.clear();
		cin>>a>>b;
		v.clear();//������� 
		p++;//����һ�� 
		for(j=0;j<b;j++)//����һ���е�a���ַ�
		{
			cin>>s;
			v.push_back(s);	
		}
		//��comp�����������
		sort(v.begin(),v.end(),comp);
		if(p!=1)cout<<endl;//���ǵ�һ�У�����һ�¿���
		//���v�����е�ÿ��Ԫ��
		for(k=0;k<v.size();k++){
			cout<<v[k]<<endl;
		} 
	}
	return 0;
}
