#include <iostream>
#include <fstream>
#include <vector>//向量
#include <string>//字符容器
#include <algorithm>//算法
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using  namespace std;
int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	string sa,sb,t;
	vector<int>v;
	int i;
	int a,b,sum;
	int flag;
	while(cin>>sa>>sb) {
		//初始化各种变量和容器
		flag=0;//没有进位
		v.clear();//清空结果向量
		sum=0;//两位数的和
		//反转两个字符容器
		reverse(sa.begin(),sa.end());
		reverse(sb.begin(),sb.end());
		//sa里放长串,sb里放短串
		if(sa.size()<sb.size()) {
			t=sa;
			sa=sb;
			sb=t;
		}
		//从个位起，一位一位相加
		for(i=0; i<sa.size(); i++) {
			//0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
			//0 1 2 3 4 5 6 7 8 9 a b c d e f g h i j
			if (sa[i]=='0') a=0;
			else if(sa[i]=='1') a=1;
			else if(sa[i]=='2') a=2;
			else if(sa[i]=='3') a=3;
			else if(sa[i]=='4') a=4;
			else if(sa[i]=='5') a=5;
			else if(sa[i]=='6') a=6;
			else if(sa[i]=='7') a=7;
			else if(sa[i]=='8') a=8;
			else if(sa[i]=='9') a=9;
			else if(sa[i]=='a') a=10;
			else if(sa[i]=='b') a=11;
			else if(sa[i]=='c') a=12;
			else if(sa[i]=='d') a=13;
			else if(sa[i]=='e') a=14;
			else if(sa[i]=='f') a=15;
			else if(sa[i]=='g') a=16;
			else if(sa[i]=='h') a=17;
			else if(sa[i]=='i') a=18;
			else if(sa[i]=='j') a=19;

			if(i>=sb.size())b=0;//已超过b串的最长一位
			else {
				if (sb[i]=='0') b=0;
				else if(sb[i]=='1') b=1;
				else if(sb[i]=='2') b=2;
				else if(sb[i]=='3') b=3;
				else if(sb[i]=='4') b=4;
				else if(sb[i]=='5') b=5;
				else if(sb[i]=='6') b=6;
				else if(sb[i]=='7') b=7;
				else if(sb[i]=='8') b=8;
				else if(sb[i]=='9') b=9;
				else if(sb[i]=='a') b=10;
				else if(sb[i]=='b') b=11;
				else if(sb[i]=='c') b=12;
				else if(sb[i]=='d') b=13;
				else if(sb[i]=='e') b=14;
				else if(sb[i]=='f') b=15;
				else if(sb[i]=='g') b=16;
				else if(sb[i]=='h') b=17;
				else if(sb[i]=='i') b=18;
				else if(sb[i]=='j') b=19;
			}
			sum = a+b+flag;//求两位的和
			if(sum>19) {
				flag=1;//进位
				sum=sum-20;
			} else {
				flag=0;
			}
			v.push_back(sum);
		}
		if(flag==1) v.push_back(1);
		//输出结果
		for(i=v.size()-1; i>=0; i--) {
			if(v[i]<10) cout<<v[i];
			else if(v[i]==10) cout<<"a";
			else if(v[i]==11) cout<<"b";
			else if(v[i]==12) cout<<"c";
			else if(v[i]==13) cout<<"d";
			else if(v[i]==14) cout<<"e";
			else if(v[i]==15) cout<<"f";
			else if(v[i]==16) cout<<"g";
			else if(v[i]==17) cout<<"h";
			else if(v[i]==18) cout<<"i";
			else if(v[i]==19) cout<<"j";
		}
		cout<<endl;
	}
	return 0;
}
