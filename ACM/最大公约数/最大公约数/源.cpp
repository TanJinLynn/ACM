#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main(){
	vector<int> v;
	vector<int>::iterator it;
	int a, b;
	while (cin>>a>>b)
	{
		v.push_back(gcd(a, b));
	}
	for (it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}