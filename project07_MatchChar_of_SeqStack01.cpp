#include <iostream>
#include <stdlib.h>
#define Elemtype char
#define Defaultsize 100
#define ExpDefaultsize 10
using namespace std;

typedef struct SeqStack{
	Elemtype* top;
	Elemtype* bottom;
	int SeqStackSize;
}SeqStack;

int InitSeqStack(SeqStack &s);
int SeqStackLength(SeqStack s);
int Push1(SeqStack &S,Elemtype data);
void Pop(SeqStack &s,Elemtype &var);
void DestroyStack(SeqStack &s);
int MatchChar();

int main(int argc, char** argv) {
	int flag;
	flag = MatchChar();
	if(flag){
		cout<<"Æ¥Åä³É¹¦";
	}else{
		cout<<"Æ¥ÅäÊ§°Ü";
	}
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

int SeqStackLength(SeqStack s){
	return s.top-s.bottom;
}

int Push1(SeqStack &S,Elemtype data){
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

void Pop(SeqStack &s,Elemtype &var){
	Elemtype* p;
	while(1){
		if(SeqStackLength(s) == 0){
			cout<<"µ±Ç°Ë³ÐòÕ»µÄ³¤¶ÈÎª"<<SeqStackLength(s)<<",É¾³ýÓÐÎó";
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

void DestroyStack(SeqStack &s){
	free(s.bottom);
	s.bottom = NULL;
	s.top = NULL; 
}

int MatchChar(){
	SeqStack s1;
	InitSeqStack(s1);
	char str[20];
	cout<<"ÇëÊäÈëÒªÆ¥ÅäµÄÀ¨ºÅ×Ö·û´®£º";
	cin>>str;
	int i = 0;
	while(str[i]!='\0'||i!=20){
		if(str[i] == '(' ||str[i] == '['||str[i] == '{'){
			Push1(s1,str[i]);
		}else if(str[i] == ')' ||str[i] == ']'||str[i] == '}'){
			if(i==0){
				return 0;
			}
			Elemtype var;
			if(SeqStackLength(s1)!=0){
				Pop(s1,var);
			}else{
				return 0;
			}
			if(var=='['||var=='{'){
				var = var+2;
				if(str[i]!=var){
					return 0;
				}
			}else{
				var+=1;
				if(str[i]!=var){
					return 0;
				}
			}
		}
		i++;
	}
	if(SeqStackLength(s1)!=0){
		return 0;
	}
	DestroyStack(s1);
	return 1;
}


