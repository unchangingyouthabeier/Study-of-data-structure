#include <iostream>
#include <stdlib.h>
#define Elemtype int
#define Defaultsize 100
#define ExpDefaultsize 10

using namespace std;

typedef struct SeqStack{
	Elemtype* top;
	Elemtype* bottom;
	int SeqStackSize;
}SeqStack;

int InitSeqStack(SeqStack &s);				//初始化顺序栈 
int IsEmptySeqStack(SeqStack s);			//判断顺序栈是否为空（未存储数据） 
int SeqStackLength(SeqStack s);				//获取顺序栈的长度 
int Push(SeqStack &S);						//压栈，向栈里添加指定个数的元素 
int Push1(SeqStack &S,int data);			//压栈，向栈里一个个地添加元素 
void TranverseSeqStack(SeqStack s);			//对顺序栈中存储的数据进行遍历 
void Pop(SeqStack &s,int &var);				//从栈顶出栈 
void ClearSeqStack(SeqStack &s);			//清空顺序栈中存储的数据 
void GetTop(SeqStack s,int &var);			//获取栈顶元素 
void DestroyStack(SeqStack &s);				//对顺序表进行销毁
void Conversion(int e,int N);				//对数据进行指定的进制转换 

int main(int argc, char** argv) {
	int i;
	SeqStack s1;
	i = InitSeqStack(s1);
	cout<<"初始化成功："<<i<<endl;
	i = IsEmptySeqStack(s1);
	cout<<"当前的顺序栈为空："<<i<<endl;
	i = SeqStackLength(s1); 
	cout<<"当前的顺序栈的长度："<<i<<endl;
	Push(s1);
	TranverseSeqStack(s1);
	int var,var1; 
	Pop(s1,var);
	cout<<"出栈元素为:"<<var<<endl; 
	TranverseSeqStack(s1);
	GetTop(s1,var1); 
	cout<<"当前栈顶元素为："<<var1<<endl;
	ClearSeqStack(s1);
	DestroyStack(s1);
	Conversion(4,2);
	return 0;
}

int InitSeqStack(SeqStack &s){
	s.bottom = (Elemtype*)malloc(Defaultsize*sizeof(Elemtype));
	if(NULL == s.bottom){
		return 0;
	}
	s.top = s.bottom;
	s.SeqStackSize = Defaultsize;
	return 1;
}

int IsEmptySeqStack(SeqStack s){
	if(s.bottom == s.top){
		return 1;
	}
	return 0;
}

int SeqStackLength(SeqStack s){
	Elemtype* p;
	int count = 0;
	p = s.bottom;
	while(p!=s.top){
		count++;
		p++;
	}
	return count;
} 

int Push(SeqStack &S){
	int quantity;
	cout<<"请输入需要向栈中放入几个数据：";
	cin>>quantity;
	if(SeqStackLength(S)+quantity>S.SeqStackSize){
		int Length;
		Length = S.SeqStackSize;
		S.bottom = (Elemtype*)realloc(S.bottom,(S.SeqStackSize+ExpDefaultsize)*(sizeof(Elemtype)));
		if(NULL==S.bottom){
			return 0;
		}
		S.top = S.bottom+Length;
		S.SeqStackSize = S.SeqStackSize+ExpDefaultsize;
	}
	int i = 1;
	while(quantity!=0){
		Elemtype data;
		cout<<"请输入存入的第"<<i<<"个数据:";
		cin>>data;
		*S.top = data;
		S.top++;
		quantity--;
		i++; 
	}
	return 1;
}

int Push1(SeqStack &S,int data){
	Elemtype* p;
	if((S.top - S.bottom) == S.SeqStackSize){
		S.bottom = (Elemtype*)realloc(S.bottom,(Defaultsize + ExpDefaultsize)*sizeof(Elemtype));
		if(NULL == S.bottom){
			return 0;
		}
		S.SeqStackSize = Defaultsize+ExpDefaultsize;
		S.top = S.bottom+Defaultsize;
	}
	p = S.top;
	*p = data;
	S.top+=1;
	return 1;
} 

void TranverseSeqStack(SeqStack s){
	Elemtype* p;
	if(SeqStackLength(s) == 0){
		cout<<"遍历：当前顺序表为存储数据"<<endl; 
	}else{
		cout<<"顺序栈的遍历：" ; 
		p = s.bottom;
		while(p!=s.top){
			cout<<*p<<"  ";
			p++;
		}
		cout<<endl;
	}
}

void Pop(SeqStack &s,int &var){
	Elemtype* p;
	while(1){
		if(SeqStackLength(s) == 0){
			cout<<"当前顺序栈的长度为"<<SeqStackLength(s)<<",删除有误";
		}else{
			break;
		}
	}
	p = s.top;
	p--;
	var = *p;
	*p = 0;
	s.top-=1;
}

void ClearSeqStack(SeqStack &s){
	while(1){
		if(SeqStackLength(s) == 0){
			cout<<"当前栈为空，不需清空"<<endl; 
			break;
		}else{
			break;
		}
	}
	while((s.top-s.bottom)!=0){
		s.top-=1;
		*s.top = 0;
	}
} 

void GetTop(SeqStack s,int &var){
	if(SeqStackLength(s)==0){
		cout<<"当前顺序栈未存储数据,不能获取栈顶元素"<<endl; 
	}else{
		var = *(--s.top);
	}
}

void DestroyStack(SeqStack &s){
	free(s.bottom);
	s.bottom = NULL;
	s.top = NULL; 
}

void Conversion(int e,int N){
	SeqStack S;
	InitSeqStack(S);
	cout<<e<<"转化为"<<N<<"进制为："; 
	while(e){
		Push1(S,e%N);
		e = e/N;
	}
	while(SeqStackLength(S)!=0){
		int var;
		Pop(S,var);
		cout<<var;
	}
	cout<<endl;
}


