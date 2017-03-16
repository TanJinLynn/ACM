#include <iostream>
#include <fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int matrix[100][100];//全局数组
int SL[100];//数组每行的和
int SC[100];//数组每列的和

int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	//先定义好各种循环变量
	int i,j,PL,PC,CountL,CountC;
	int n;//矩阵行数或列数
	while(cin>>n) {
		if(n==0) break;//读入数据结束
		//初始化各种变量
		PL =0;
		PC =0;
		CountL=0;
		CountC=0;
		for(i=0; i<n; i++) {
			SL[i]=0;
			SC[i]=0;
		}
		//读入所有数据，同时计算出每行，列的元素和
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++) {
				cin>>matrix[i][j];
				SL[i]=SL[i]+matrix[i][j];
				SC[j]=SC[j]+matrix[i][j];
			}
		}
		//判断矩阵每行、列的和是否是偶数
		for(i=0; i<n; i++) {
			//判断每行的和
			if(SL[i]%2!=0) { //和是奇数
				PL=i;//记下行数
				CountL++;//记下次数
			}
			//判断每列的和
			if(SC[i]%2!=0) { //和是奇数
				PC=i;//记下列数
				CountC++;//记下次数
			}
		}
		//输出结果
		if(CountL==0&&CountC==0)
			cout<<"OK"<<endl;
		else if(CountL==1&&CountC==1)
			cout<<"Change bit ("<<PL+1<<","<<PC+1<<")"<<endl;
		else
			cout<<"Corrupt"<<endl;
	}
	return 0;
}
