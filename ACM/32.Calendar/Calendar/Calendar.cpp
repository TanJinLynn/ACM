// Calendar.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//����Ϊ���������յĳ�ʶ
//1 3 5 7 8 10 12��Ϊ����
//4 6 9 11ΪС��
//��������꣬2����29�죬����2��ֻ��28��
//�����ӡ���ڽṹ
struct Info
{
	short int year;
	short int month;
	short int day;
	short int week; 
};
//�����������洢������Ϣ��
vector<Info>v;
bool RR(int year){
	//����������������֮һ����������
	//��1���ܱ�4�����������ܱ�100������
	//(2)�ܱ�4���������ܱ�400����
	if ((year%4==0&&year%100!=0)||(year%400==0))                               
		return true;
	else
		return false;
}                            
int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("aaa.txt");
	int i, j, k;
	int p=0;
	Info info;
	int flag = 0;//�����־
	int week = 5;
	//����2000-01-01��9999-12-31�����ڼ��ձ�
	for ( i = 2000; i <=9999; i++)//���
	{
		flag = RR(i);
		for (j = 1; j <= 12; j++){//�·�
			for (k = 1; k <= 31; k++){//��
				//1 3 5 7 8 10 12��Ϊ���£�ÿ����31��
				if ((j == 1) || (j == 3) || (j == 5) || (j == 7) || (j == 8) || (j == 10) || (j == 12)){
					p++;
				//4 6 9 11��ΪС�£�ÿ����30��
				}
				else if ((j==4)||(j==6)||(j==9)||(j==11))
				{
					if (k != 31)p++;
					else
						break;//������һ����
				}
				//��������꣬2����29�죬����2��ֻ��28��
				else if (j == 2){
					if (flag)//������
					{
						if (k != 30 && k != 31)p++;
						else
							break;//������һ����
					}
					else//��������
					{
						if (k != 29 && k != 30 && k != 31)p++;
						else
							break;//������һ����
					}
				}
				info.year = i;
				info.month = j;
				info.day = k;
				week++;
				if (week == 8)week = 1;
				info.week = week;
				v.push_back(info);
			}
		}
	}
	int n;
	while (cin>>n)
	{
		if (n == -1) break;
		else
		{
			cout << v[n].year << "-";
			if (v[n].month < 10) cout << "0" << v[n].month << "-";
			else
				cout << v[n].month << "-";
			if (v[n].day < 10) cout << "0" << v[n].day << " ";
			else
				cout << v[n].day << " ";
			if (v[n].week == 1)
				cout << "Monday" << endl;
			else if (v[n].week == 2)
				cout << "Tuesday" << endl;
			else if (v[n].week == 3)
				cout << "Wednesday" << endl;
			else if (v[n].week == 4)
				cout << "Thursday" << endl;
			else if (v[n].week == 5)
				cout << "Friday" << endl;
			else if (v[n].week ==6)
				cout << "Saturday" << endl;
			else if (v[n].week == 7)
				cout << "Sunday" << endl;
		}
	}
return 0;
}
