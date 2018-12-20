#include<stdio.h>
//queue begin
//Build. --2018.12.20
//Support push,pop,front; 
template<typename T>
class queue{
	private:
		struct node{
			node* nxt;
			T val;
		};
		node* head;
		node* tail;
		int size;
	public:
		queue(){tail=new node;head=tail->nxt=new node,size=0;}
		void clear(){
		tail=new node;
			head=tail->nxt=new node;
			size=0;
		}
		queue& push(T val){
			size++;
			tail=tail->nxt;
			tail->val=val;
			tail->nxt=new node;
			return *this;
		}
		T front(){
			return head->val;
		}
		queue& pop(){
			if(!size){
				puts("POP ERROR");
				return *this;
			}
			size--;
			head=head->nxt;
			return *this;
		}
};
//queue end
