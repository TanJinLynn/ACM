#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
	ifstream cin("aaa.txt");
	string s, t;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int c = 0;
		t = s[0];
		int temp = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == t[0]) {
				temp++;
				//如果已经是最后一个，直接输出
				if (j == s.size() - 1) {
					//cout<<temp<<t[0];
					printf("%d%c", temp, t[0]);
				}
			} else {
				//cout<<temp<<t[0];
				printf("%d%c", temp, t[0]);
				t[0] = s[j];
				temp = 1;
				//如果已经是最后一个，直接输出
				if (j == s.size() - 1) {
					//cout<<temp<<t[0];
					printf("%d%c", temp, t[0]);
				}
			}
		}
		cout << endl;
	}
	return 0;
}
