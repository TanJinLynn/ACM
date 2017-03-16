#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(){
	ifstream cin("aaa.txt");
	string s, ssa, ssb;
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n;
		for (int j = 0; j < n; j++){
			cin >> s;
			ssa = ssa + s[0];
		}
		cin >> m;
		for (int k = 0; k < m; k++){
			cin >> s;
			ssb = ssb + s[0];
		}
		if (ssa == ssb)
		{
			cout << "SAME" << endl;
		}
		else
		{
			cout << "DIFFERENT" << endl;
		}
		ssa = "";
		ssb = "";
	}
	return 0;
}