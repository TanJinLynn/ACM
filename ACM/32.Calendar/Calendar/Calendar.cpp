// Calendar.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
//以下为阳历年月日的常识
//1 3 5 7 8 10 12月为大月
//4 6 9 11为小月
//如果是闰年，2月有29天，否则，2月只有28天
//定义打印日期结构
struct Info
{
	short int year;
	short int month;
	short int day;
	short int week; 
};
//定义向量来存储日期信息表
vector<Info>v;
bool RR(int year){
	//符合下面两个条件之一，就是闰年
	//（1）能被4整除，但不能被100整除；
	//(2)能被4整除，又能被400整除
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
	int flag = 0;//闰年标志
	int week = 5;
	//建立2000-01-01到9999-12-31的日期计日表
	for ( i = 2000; i <=9999; i++)//年份
	{
		flag = RR(i);
		for (j = 1; j <= 12; j++){//月份
			for (k = 1; k <= 31; k++){//日
				//1 3 5 7 8 10 12月为大月，每月有31天
				if ((j == 1) || (j == 3) || (j == 5) || (j == 7) || (j == 8) || (j == 10) || (j == 12)){
					p++;
				//4 6 9 11月为小月，每月有30天
				}
				else if ((j==4)||(j==6)||(j==9)||(j==11))
				{
					if (k != 31)p++;
					else
						break;//跳到下一个月
				}
				//如果是闰年，2月有29天，否则，2月只有28天
				else if (j == 2){
					if (flag)//是闰年
					{
						if (k != 30 && k != 31)p++;
						else
							break;//跳到下一个月
					}
					else//不是闰年
					{
						if (k != 29 && k != 30 && k != 31)p++;
						else
							break;//跳到下一个月
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
