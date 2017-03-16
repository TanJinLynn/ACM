#include <fstream>
#include <iostream>

using namespace std;
int main(){
	ifstream cin("aaa.txt");
	char ch;
	int i = 1;
	int sum = 0;
	//cin会忽略回车，空格，Tab跳格
	//采用cin.get()一个一个读，就不会忽略任何字符
	//也可以采用cin.getline()一行一行读入
	while (cin.get(ch))
	{
		if (ch == '#') break;//读完全部输入
		if (ch != '\n')//没读完一行
		{
			//空格字符不用计算
			if (ch != ' ') sum = sum + i*(ch - 64);
			i++;
		}
		if (ch == '\n'){
			cout << sum << endl;
			sum = 0;
			i = 1;
		}
	}
	return 0;
}
