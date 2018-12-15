//mystl by zheglier
#include<bits/stdc++.h>
namespace mystl{
	//vector begin
	//Build. --2018.12.15
	//Support Insert and erase. --2018.12.15
	template<typename T>
	class vector{
		private:
			T* data;
			unsigned int Capacity,Size;
		public:
			typedef T* iterator;
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
				for(int i=0;i<other.Size;++i){
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
			const iterator begin(){
				return data;
			}
			const iterator end(){
				return data+Size;
			}
			unsigned int size(){
				return Size;
			}
			unsigned int capacity(){
				return Capacity;
			}
			const T front(){
				return *begin();
			}
			const T back(){
				return *(end()-1);
			}
			const vector& push_back(const T temp){
				if(Size>=Capacity){
					iterator newdata=new T[Capacity*2+1];
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
				return *this;
			}
			const vector& insert(const iterator pos,const T val,const int num=1){
				if(pos<begin()||pos>end()){
					puts("");
					puts("In vector:");
					puts("    ERROR: In Insert: Pos is too big or too small");
					puts("");
					exit(0);
				} 
				for(int i=0;i<num;++i){
					iterator it=end()-1;
					while(it>=pos){
						*(it+1)=*it;
						it--;
					}
					*pos=val;
					Size++;
				}
				return *this;	
			}
			const vector& erase(const iterator pos,const int num=1){
				if(pos<begin()||pos>end()){
					puts("");
					puts("In vector:");
					puts("    ERROR: In erase: Pos is too big or too small");
					puts("");
					exit(0);
				}
				for(int i=0;i<num;++i){
					iterator it=pos;
					while(it!=end()){
						*it=*(it+1);
						it++;
					}
					Size--;
				}
				return *this;
			}
			const vector& erase(const iterator l,const iterator r){
				if(l<begin()||l>end()||r<begin()||r>end()||r<l){
					puts("");
					puts("In vector:");
					puts("    ERROR: In erase: Pos is too big or too small or l>r");
					puts("");
					exit(0);
				}
				iterator i=l,j=r;
				int del=r-l;
				Size-=del;
				while(i!=end()){
					*i=*j;
					i++,j++;
				}
				return *this;
			}
	};
	//vector end
	
	//sort begin
	//Build.It doesn't support cmp. --2018.12.15
	//Support struct. --2018.12.15
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
int main(){
	
}
