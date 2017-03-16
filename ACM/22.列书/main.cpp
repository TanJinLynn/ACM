#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//数据存取结构
struct Book{
	string Name;
	int Year;
	int Price;
};
//自定义比较函数，Name主序
bool CompName(const Book &b1,const Book &b2)
{
	if(b1.Name!=b2.Name) return b1.Name<b2.Name;
	else if(b1.Year!=b2.Year) return b1.Year<b2.Year;
	else return b1.Price<b2.Price;
}
//自定义比较函数，Year主序
bool CompYear(const Book &b1,const Book &b2)
{
	if(b1.Year!=b2.Year) return b1.Year<b2.Year;
	else if(b1.Name!=b2.Name) return b1.Name<b2.Name;
	else return b1.Price<b2.Price;
}
//自定义比较函数，Price主序
bool CompPrice(const Book &b1,const Book &b2)
{
	if(b1.Price!=b2.Price) return b1.Price<b2.Price;
	else if(b1.Name!=b2.Name) return b1.Name<b2.Name;
	else return b1.Year<b2.Year;
}
int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	vector<Book> v;
	Book book;
	string sorting;//第一排序
	int n;
	int i;
	int line=0;
	while(cin>>n)
	{
		if(n==0) break;
		line++;//案例号
		v.clear();//清空向量
		//读入一个案例数据到向量中
		for(i=0;i<n;i++){
			cin>>book.Name>>book.Year>>book.Price;
			v.push_back(book);
		}
		//读入排序标准
		cin>>sorting;
		//给向量排序，要据主排序确定比较函数
		if(sorting=="Name")
			sort(v.begin(),v.end(),CompName);
		else if(sorting=="Year")
			sort(v.begin(),v.end(),CompYear);
		else if(sorting=="Price")
			sort(v.begin(),v.end(),CompPrice);
		//输出结果
		if(line!=1) cout<<endl;//不是第一行，先输出一空行
		for(i=0;i<v.size();i++)
		{
			cout<<v[i].Name<<" "<<v[i].Year<<" "<<v[i].Price<<endl;
		}
	}
	return 0;
}



























