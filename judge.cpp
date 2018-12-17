#include"mystl.h""
using namespace mystl;
int n;
vector<int> q;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		int a;
		cin>>a;
		q.push_back(a);
	}
	sort(q.begin(),q.end(),greater<int>());
	vector<int>::iterator it;
	for(it=q.begin();it!=q.end();++it){
		cout<<*it<<' ';
	}cout<<endl;
}
