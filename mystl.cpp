//mystl by zheglier
#include<bits/stdc++.h>
namespace mystl{
    //vector begin
	//Build. --2018.12.15
	template<typename T>
	class vector{
		public:
			vector(){
				data=NULL;
				Capacity=Size=0;
			}
			void clear(){
				delete[] data;
				Capacity=Size=0;
			}
			vector(const vector& other){
				if(this==&other)return;
				data=new T[other.Size];
				for(int i=0;i<Size;++i){
					data[i]=other[i];
				}
				capacity=other.Capacity;
				Size=other.Size;
			}
			T& operator[](int index){
				if(index>=Size){
					puts("");
					puts("In vector:");
					puts("    ERROR: Index is too large.");
					puts("");
					exit(0);
				}
				return data[index];
			}
			T* begin(){
				return data;
			}
			T* end(){
				return data+Size;
			}
			const vector& push_back(const T temp){
				if(Size>=Capacity){
					T* newdata=new T[Capacity*2+1];
					memmove(newdata,data,Size*sizeof(T));
					delete[] data;
					data=newdata;
					Capacity=Capacity*2+1;
				}
				data[Size++]=temp;
				return *this;
			}
			const vector& pop_back(){
				--Size;
			}
			unsigned int size(){
				return Size;
			}
			unsigned int capacity(){
				return Capacity;
			}
			typedef T* iterator;
		private:
			T* data;
			unsigned int Capacity,Size;
	};
	//vector end
	
	//sort begin
	//Build.It doesn't support cmp. --2018.12.15
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
	//sort end
}
int main(){}
