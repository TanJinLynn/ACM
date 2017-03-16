#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
	ifstream cin("aaa.txt");
	vector<int>v;
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		v.clear();
		for (int j = a; j; j = j / 2){
			v.push_back(j % 2 ? 1 : 0);
		}
		int p = 0;
		for (int k = 0; k < v.size(); k++){
			if (v[k] == 1){
				if (p == 0) cout << k;
				else cout << " " << k;
				p = 1;
			}
		}
		cout << endl;
	}
	return 0;
}
