#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//����gets()�����getline()��Ķ࣬��gets()���ܴ�cin�ж�ȡ���ݣ������ϲ���
//gets�����÷�
//��stdin���ж�ȡ�ַ�����ֱ�����ܴ��з���EOFʱֹͣ
//���з�����Ϊ��ȡ�������ݣ���ȡ�Ļ��з���ת��Ϊnullֵ�����ɴ��������ַ���
int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	string s;
	char ss[100],s1[100],s2[100];
	int x,y;
	map<string,string> m;
	//mapӳ������:��ֵ+ӳ������
	map<string,string>::iterator p;
	while(getline(cin,s)) {
		//�������һ��Ϊ����(ֻ����һ���س���)�����ѭ��
		if(s=="") break;
		else {
			//ǰ���Թ̶��ַ���Ϊ����Դ��Ĭ���Կո����ֿ��ַ���
			sscanf(s.c_str(),"%s %s",s1,s2);
			m[s2]=s1;
		}
	}
	while(cin>>s) {
		//��ӳ�������в��Ҽ�ֵ
		p=m.find(s);
		if(p!=m.end())
			cout<<m[s]<<endl;
		else
			cout<<"eh"<<endl;
	}
	return 0;
}






















