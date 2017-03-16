#include <iostream>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
struct Message {
	char Name[100];
	int  Date;
	int Priority;
	//重载<操作符，自定义排序规则
	bool operator < (const Message &a) const {
		return a.Priority<Priority;
	}
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
priority_queue<Message> v;
int main(int argc, char** argv) {
	ifstream cin("aaa.txt");
	char command[100];
	Message message;
	while(cin>>command) {
		if(strcmp(command,"GET")==0) {
			//队列为空
			if(v.size()==0) {
//				printf("EMPTY QUEUE!\n");
				//使用下面这句话不会超时
				cout<<"EMPTY QUEUE!"<<endl;
			} else {
				//cout<<<<" "<<<<endl;
//				printf("%s %d\n",v.top().Name,v.top().Date);
				//使用下面这句话会超时
				cout<<v.top().Name<<" "<<v.top().Date<<endl;
				//出队列操作，即将当前消息清除
				v.pop();
			}
		} else if(strcmp(command,"PUT")==0) {
			cin>>message.Name>>message.Date>>message.Priority;
//			scanf("%s%d%d",&message.Name,&message.Date,&message.Priority);
			v.push(message);
		}
	}
	return 0;
}
