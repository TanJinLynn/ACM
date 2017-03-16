#include <iostream>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	int n;
	int a,b,c;
	while(cin>>n){
		a=n/100;
		b=(n-a*100)/10;
		c=n%10;
		if(n==a*a*a+b*b*b+c*c*c)
		{
			cout<<"Yes"<<endl;
		}else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
