#include <iostream>
#include <fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	int p[10][10];
	int n,m;
	int i,j,k;
	int flag=1;//1��ʾû�г�����
	while(cin>>n>>m) {
		if(n==0&&m==0) break;
		flag=1;//�ȱ��û�г�����
		//����һ������
		for(i=0; i<n; i++) {
			for(j=0; j<m; j++) {
				cin>>p[i][j];
				if(p[i][j]==0) flag=0;
			}
		}
		//��ʼ�ж�
		//��һ�����:û�޼�������ȫ��1����Ư��
		if(flag==1) {
			cout<<"No"<<endl;
			continue;
		}
		//�ڶ������:�������鹲һ�ߣ���ǰ������Ԫ�ػ���������Ԫ����00����Ư��
		//�жϵ�0��
		for(k=1; k<m; k++) {
			if(p[0][k]==0&&p[0][k-1]==0) {
				cout<<"No"<<endl;
				goto RL;
			}
		}
		//�жϵ�1~n-1��
		for(i=1; i<n; i++) {
			for(j=0; j<m; j++) {
				//��������һ��ͬһ��Ԫ�ض���0��
				if(p[i][j]==0&&p[i-1][j]==0) {
					cout<<"No"<<endl;
					goto RL;
				}
				//�����е�ǰԪ�غ�ǰһԪ�ض���0��
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
