#include "stl.h"
queue<int>q;
int main(){
	for(int i=1;i<=10;++i){
		q.push(i*i/2);
	}
	for(int i=1;i<=10;++i){
		cout<<q.front()<<endl;
		q.pop();
	}
}
