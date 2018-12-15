#include<bits/stdc++.h>
namespace mystl{
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
}
using namespace mystl;
vector<int>q;
int main(){
	q[1];
}
 
