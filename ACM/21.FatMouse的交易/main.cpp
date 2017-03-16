#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//数据存取结构
struct Mouse{
	double J;
	double F;
	double a;
};
//自定义排序比较规律
bool Comp(const Mouse &d1,const Mouse &d2)
{
	//按a由大到小排序
	if(d1.a!=d2.a) return d1.a>d2.a;
	//按F由大到小排序
	else return d1.F<d2.F;
}
int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	vector<Mouse> v;
	Mouse mouse;
	int m,n,i;
	//三位输出精度
	cout.precision(3);
	double sum;
	while(cin>>m>>n){
		if(m==-1&&n==-1)break;//读取结束
		v.clear();
		sum=0.0;
		//读入数据到向量中
		for(i=0;i<n;i++)
		{
			cin>>mouse.J>>mouse.F;
			mouse.a=mouse.J/mouse.F;
			v.push_back(mouse);//往向量里增加一元素
		}
		//使用自定义排序规则Comp给向量排序
		sort(v.begin(),v.end(),Comp);
		//计算交换数量
		for(i=0;i<v.size();i++)
		{
			if(m>=v[i].F)
			{
				sum=sum+v[i].J;
				m=m-v[i].F;
			}
			else
			{
				sum=sum+m*v[i].a;
				break;
			}
		}
		//定点三位精度输出数据
		cout<<fixed<<sum<<endl;
	}
	return 0;
}
