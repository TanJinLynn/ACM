#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//采用gets()输入比getline()快的多，但gets()不能从cin中读取数据，调试上不易
//gets函数用法
//从stdin流中读取字符串，直至接受打换行符或EOF时停止
//换行符不作为读取串的内容，读取的换行符被转换为null值，并由此来结束字符串
int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	string s;
	char ss[100],s1[100],s2[100];
	int x,y;
	map<string,string> m;
	//map映射容器:键值+映射数据
	map<string,string>::iterator p;
	while(getline(cin,s)) {
		//如果读入一行为空行(只包含一个回车符)则结束循环
		if(s=="") break;
		else {
			//前者以固定字符串为输入源，默认以空格来分开字符串
			sscanf(s.c_str(),"%s %s",s1,s2);
			m[s2]=s1;
		}
	}
	while(cin>>s) {
		//从映射容器中查找键值
		p=m.find(s);
		if(p!=m.end())
			cout<<m[s]<<endl;
		else
			cout<<"eh"<<endl;
	}
	return 0;
}






















