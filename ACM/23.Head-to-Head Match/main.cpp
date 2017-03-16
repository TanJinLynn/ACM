#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	//pow乘方函数的参数需要定义为double类型
	double i,n,count;
	while(cin>>n)
	{
		if(n==0) break;
		count=0;
		for(i=0;i<32;i++)
		{
			if(pow(2,i)>=n)
			{
				count=i;
				break;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
