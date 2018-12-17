#include<stdio.h>
#include<string.h>
namespace mystl{
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
					return *this;
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
					puts("    ERROR: In insert: Pos is too big or too small");
					puts("");
					return *this;
				} 
				int left=pos-begin();
				for(int i=0;i<num;++i){
					iterator _pos=begin()+left;
					if(_pos==end()){
						push_back(val);
					}else{
						iterator it=end()-2;
						T _val=*(end()-1);
						while(it>=_pos){
							*(it+1)=*it;
							it--;
						}
						*_pos=val;
						push_back(_val);
				    }
				}
				return *this;	
			}
			const vector& erase(const iterator pos,const int num=1){
				if(pos<begin()||pos>end()){
					puts("");
					puts("In vector:");
					puts("    ERROR: In erase: Pos is too big or too small");
					puts("");
					return *this;
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
					return *this;
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
}
using namespace mystl;
int main(){
}
 
