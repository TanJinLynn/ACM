// Palindromes.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	char s[5000];
	int p,i,Half,Left,Right,Count;
	while(cin>>s)
	{
		i=strlen(s);
		Count=0;//总回文数
		//从左到右钉住最后一个
		for (p= 0; p < i-1; p++)
		{
			Half = ((i - 1) - p) / 2;
			//如果子串是偶数个字符
			if (((i - 1) - p) % 2 == 0){
				Left = p + Half - 1;
				Right = p + Half + 1;
			}
			else//如果子串是奇数个字符
			{
				Left = p + Half;
				Right = p + Half + 1;
			}
			while (Left>=p)
			{
				if (s[Left] == s[Right]){
					Count++;//发现了一个回文串
					Left--;
					Right++;
				}
				else
				{
					//如果不相等，立即中止，由中心向外扩散不可能会有回文串
					break;
				}
			}
		}
		//从右到左钉住第一个
		for (p = i-2; p >=1; p--)
		{
			Half = p / 2;
			//如果子串是奇数个
			if (p % 2 == 0){
				Left = Half - 1;
				Right = Half + 1;
			}
			else
			{
				//如果子串是偶数个
				Left = Half;
				Right = Half + 1;
			}
			while (Left>=0)
			{
				if (s[Left] == s[Right]){
					Count++;//发现一个回文串
					Left--;
					Right++;
				}
				else
				{
					//如果不相等，立即中止，有中心向外扩散不可能会有回文串
					break;
				}
			}
		}
		cout << Count + i;
	}
	return 0;
}

