#include<stdio.h>
namespace mystl{
	//equal_to
	template<typename T>
	struct equal_to{
		const bool operator()(T a,T b)const{
			return (a)==(b);
		}
	};
	//not_equal_to
	template<typename T>
	struct not_equal_to{
		const bool operator()(T a,T b)const{
			return (a)!=(b);
		}
	};
	//greater
	template<typename T>
	struct greater{
		const bool operator()(T a,T b)const{
			return (a)>(b);
		}
	};
	//less
	template<typename T>
	struct less{
		const bool operator()(T a,T b)const{
			return (a)<(b);
		}
	};
	//greater_equal
	template<typename T>
	struct greater_equal{
		const bool operator()(T a,T b)const{
			return (a)>=(b);
		}
	};
	//less_equal
	template<typename T>
	struct less_equal{
		const bool operator()(T a,T b)const{
			return (a)<=(b);
		}
	};
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
	//with cmp
	template<typename T,typename _cmp>
	void sort(T* begin,T* end,_cmp _comp){
		#define int unsigned int
		if(end-begin<=1)return;
		T* mid=begin+((int)(end-begin)/2);
		sort(begin,mid,_comp);
		sort(mid,end,_comp);
		T* ls=new T[end-begin];int cnt=0;
		T* i=begin;
		T* j=mid;
		while(i<mid&&j<end){
			if(_comp(*i,*j)){
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
int main(){
}
