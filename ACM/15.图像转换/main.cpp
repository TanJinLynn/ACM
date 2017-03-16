#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	vector<int> r;
	vector<int> g;
	vector<int> b;
	int n,m;
	int rr,gg,bb;
	int w;//ÑùÀýÊýÄ¿
	while(cin>>n>>m) {
		r.clear();
		g.clear();
		b.clear();
		w++;
		if(n==0&&m==0) break;
		for(int i=0; i<n*m; i++) {
			cin>>rr;
			r.push_back(rr);
		}
		for(int j=0; j<n*m; j++) {
			cin>>gg;
			g.push_back(gg);
		}
		for(int k=0; k<n*m; k++) {
			cin>>bb;
			b.push_back(bb);
		}
		cout<<"Case "<<w<<":"<<endl;
		for(int p=0;p<n*m;p++){
			cout<<(r[p]+g[p]+b[p])/3;
			if((p+1)%m==0) cout<<endl;
			else cout<<",";
		}
		
	}

	return 0;
}
