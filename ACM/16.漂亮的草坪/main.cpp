#include <iostream>
#include <fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	int p[10][10];
	int n,m;
	int i,j,k;
	int flag=1;//1表示没有锄过草
	while(cin>>n>>m) {
		if(n==0&&m==0) break;
		flag=1;//先标记没有锄过草
		//读入一个矩阵
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				cin>>p[i][j];
				if(p[i][j]==0) flag=0;
			}
		}
		//开始判断
		//第一种情况:没修剪过，即全是1，则不漂亮
		if(flag==1) {
			cout<<"No"<<endl;
			continue;
		}
		//第二种情况:剪的两块共一边，即前后两个元素或上下两个元素是00，不漂亮
		//判断第0行
		for(k=1; k<m; k++) {
			if(p[0][k]==0&&p[0][k-1]==0) {
				cout<<"No"<<endl;
				goto RL;
			}
		}
		//判断第1~n-1行
		for(i=1; i<n; i++) {
			for(j=0; j<m; j++) {
				//本行与上一行同一列元素都是0吗
				if(p[i][j]==0&&p[i-1][j]==0) {
					cout<<"No"<<endl;
					goto RL;
				}
				//本行中当前元素和前一元素都是0吗
				if(j!=0) {
					if(p[i][j]==0&&p[i][j-1]==0) {
						cout<<"No"<<endl;
						goto RL;
					}
				}
			}
		}
		cout<<"Yes"<<endl;
		continue;
RL:
		continue;
	}
	return 0;
}
