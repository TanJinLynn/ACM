#include <fstream>
#include <iostream>

using namespace std;
int main(){
	ifstream cin("aaa.txt");
	char ch;
	int i = 1;
	int sum = 0;
	//cin����Իس����ո�Tab����
	//����cin.get()һ��һ�������Ͳ�������κ��ַ�
	//Ҳ���Բ���cin.getline()һ��һ�ж���
	while (cin.get(ch))
	{
		if (ch == '#') break;//����ȫ������
		if (ch != '\n')//û����һ��
		{
			//�ո��ַ����ü���
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
