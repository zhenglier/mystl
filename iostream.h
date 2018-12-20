#include<stdio.h>
//iostream begin
//Build. --2018.12.16
//Support int,unsigneed int,long longunsigned long long,char. --2018.12.16
//Suppor float,double. --2018.12.17
struct istream{}cin;
struct ostream{}cout;
#define gc(x) (x=getchar())
#define pc(x) putchar(x)
#define isdigit(c) ('0'<=(c)&&(c)<='9')
#define ok(x) ((x)!=' '&&(x)!='\r'&&(x)!='\n')
//IN:
//int
istream& operator >>(const istream& in,int& val){
	int ret=0;bool f=0;char c;
	for(gc(c);!isdigit(c);c=getchar())f=(c=='-');
	for(;isdigit(c);ret=(ret<<1)+(ret<<3)+c-'0',gc(c));
	val=(f?-ret:ret);
}
//unsigned int
istream& operator >>(const istream& in,unsigned int& val){
	unsigned int ret=0;char c;
	for(gc(c);!isdigit(c);c=getchar());
	for(;isdigit(c);ret=(ret<<1)+(ret<<3)+c-'0',gc(c));
	val=ret;
}
//long long
istream& operator >>(const istream& in,long long& val){
	long long ret=0;bool f=0;char c;
	for(gc(c);!isdigit(c);c=getchar())f=(c=='-');
	for(;isdigit(c);ret=(ret<<1ll)+(ret<<3ll)+c-'0',gc(c));
	val=(f?-ret:ret);
}
//unsigned long long
istream& operator >>(const istream& in,unsigned long long& val){
	unsigned long long ret=0;char c;
	for(gc(c);!isdigit(c);c=getchar());
	for(;isdigit(c);ret=(ret<<1)+(ret<<3)+c-'0',gc(c));
	val=ret;
}
//char
istream& operator >>(const istream& in,char& val){
    gc(val);
	while(!ok(val))gc(val);
}
//float I'm lazy.
istream& operator >>(const istream& in,float& val){
	scanf("%f",&val);
}
//double I'm lazy.
istream& operator >>(const istream& in,double& val){
	scanf("%lf",&val);
}

//OUT:
//endl
struct _endl{}endl;
ostream& operator <<(const ostream& out,_endl endl){
	putchar('\n'),putchar('\r');
}
//int
ostream& operator <<(const ostream& out,int val){
	char* c=new char[10];int cnt=0;
	if(val<0)pc('-'),val=-val;
	while(val){
		*(c+cnt)=val%10+'0';
		val/=10;
		cnt++;
	}
	while(cnt){
		cnt--;
		pc(*(c+cnt));
	}
	delete[]c;
}
//unsigned int
ostream& operator <<(const ostream& out,unsigned int val){
	char* c=new char[10];int cnt=0;
	while(val){
		*(c+cnt)=val%10+'0';
		val/=10;
		cnt++;
	}
	while(cnt){
		cnt--;
		pc(*(c+cnt));
	}
	delete[]c;
}
//long long
ostream& operator <<(const ostream& out,long long val){
	char* c=new char[20];int cnt=0;
	if(val<0)pc('-'),val=-val;
	while(val){
		*(c+cnt)=val%10+'0';
		val/=10;
		cnt++;
	}
	while(cnt){
		cnt--;
		pc(*(c+cnt));
	}
	delete[]c;
}
//unsigned long long
ostream& operator <<(const ostream& out,unsigned long long val){
	char* c=new char[20];int cnt=0;
	while(val){
		*(c+cnt)=val%10+'0';
		val/=10;
		cnt++;
	}
	while(cnt){
		cnt--;
		pc(*(c+cnt));
	}
	delete[]c;
}
//char
ostream& operator <<(const ostream& out,char val){
	pc(val);
}
//float I'm lazy.
ostream& operator <<(const ostream& out,float& val){
	printf("%f",&val);
}
//double I'm lazy.
ostream& operator <<(const ostream& out,double& val){
	printf("%lf",&val);
}
#undef gc
#undef pc
#undef isdigit
//iostream end