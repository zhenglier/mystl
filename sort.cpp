#include<bits/stdc++.h>
namespace mystl{
	template<typename T>
	void sort(T* begin,T* end){
		#define int unsigned int
		if(end-begin<=1)return;
		T* mid=begin+((int)(end-begin)/2);
		sort(begin,mid);
		sort(mid,end);
		T* ls=new T[end-begin];int cnt=0;
		T* i=begin;
		T* j=mid;
		while(i<mid&&j<end){
			if(*i<*j){
				ls[cnt++]=*i;
				i++;
			}else{
				ls[cnt++]=*j;
				j++;
			}
		}
		while(i<mid){
			ls[cnt++]=*i;
			i++;
		}
		while(j<end){
			ls[cnt++]=*j;
			j++;
		}
		for(int i=0;i<cnt;++i){
			begin[i]=ls[i];
		}
		delete[] ls;
		#undef int
	}
}
using namespace mystl;
struct data{
	int x,y;
}a[100010];
bool operator <(data a,data b){
    return a.x<b.x; 
} 
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		printf("%d %d\n",a[i].x,a[i].y);
	}
}
