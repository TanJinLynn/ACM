#include <iostream>
#include <fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int matrix[100][100];//ȫ������
int SL[100];//����ÿ�еĺ�
int SC[100];//����ÿ�еĺ�

int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	//�ȶ���ø���ѭ������
	int i,j,PL,PC,CountL,CountC;
	int n;//��������������
	while(cin>>n) {
		if(n==0) break;//�������ݽ���
		//��ʼ�����ֱ���
		PL =0;
		PC =0;
		CountL=0;
		CountC=0;
		for(i=0; i<n; i++) {
			SL[i]=0;
			SC[i]=0;
		}
		//�����������ݣ�ͬʱ�����ÿ�У��е�Ԫ�غ�
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				cin>>matrix[i][j];
				SL[i]=SL[i]+matrix[i][j];
				SC[j]=SC[j]+matrix[i][j];
			}
		}
		//�жϾ���ÿ�С��еĺ��Ƿ���ż��
		for(i=0; i<n; i++) {
			//�ж�ÿ�еĺ�
			if(SL[i]%2!=0) { //��������
				PL=i;//��������
				CountL++;//���´���
			}
			//�ж�ÿ�еĺ�
			if(SC[i]%2!=0) { //��������
				PC=i;//��������
				CountC++;//���´���
			}
		}
		//������
		if(CountL==0&&CountC==0)
			cout<<"OK"<<endl;
		else if(CountL==1&&CountC==1)
			cout<<"Change bit ("<<PL+1<<","<<PC+1<<")"<<endl;
		else
			cout<<"Corrupt"<<endl;
	}
	return 0;
}
