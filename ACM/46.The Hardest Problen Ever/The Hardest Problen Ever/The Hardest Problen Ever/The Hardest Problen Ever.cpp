// The Hardest Problen Ever.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{	
	ifstream cin("aaa.txt");
	string s;
	char ss[200];
	map<char, char>m;
	m['A'] = 'V';
	m['B'] = 'W';
	m['C'] = 'X';
	m['D'] = 'Y';
	m['E'] = 'Z';
	m['F'] = 'A';
	m['G'] = 'B';
	m['H'] = 'C';
	m['I'] = 'D';
	m['J'] = 'E';
	m['K'] = 'F';
	m['L'] = 'G';
	m['M'] = 'H';
	m['N'] = 'I';
	m['O'] = 'J';
	m['P'] = 'K';
	m['Q'] = 'L';
	m['R'] = 'M';
	m['S'] = 'N';
	m['T'] = 'O';
	m['U'] = 'P';
	m['V'] = 'Q';
	m['W'] = 'R';
	m['X'] = 'S';
	m['Y'] = 'T';
	m['Z'] = 'U';
	int i;
	while (cin.getline(ss, 200)){
		s = ss;
		if (s == "START") continue;
		else if (s == "END") continue;
		else if (s == "ENDOFINPUT")break;
		else
		{
			for (i = 0; i < s.size(); i++)
			{
				if (s[i] >= 'A'&&s[i] <= 'Z'){
					cout << m[s[i]];
				}
				else
				cout << s[i];
			}
			cout << endl;
		}
	}
	return 0;
}

