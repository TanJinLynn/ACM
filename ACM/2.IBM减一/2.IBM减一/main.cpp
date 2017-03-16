#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ifstream cin("aaa.txt");
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cout << "String #" << i + 1 << endl;
		for (int j = 0; j < s.size(); j++) {
			cout << ((s[j] != 'Z') ? char(s[j] + 1) : 'A');
		}
		cout << endl;
		cout << endl;//要产生一个空行
	}
	return 0;
}
