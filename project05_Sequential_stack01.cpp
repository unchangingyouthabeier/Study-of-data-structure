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

int InitSeqStack(SeqStack &s);				//��ʼ��˳��ջ 
int IsEmptySeqStack(SeqStack s);			//�ж�˳��ջ�Ƿ�Ϊ�գ�δ�洢���ݣ� 
int SeqStackLength(SeqStack s);				//��ȡ˳��ջ�ĳ��� 
int Push(SeqStack &S);						//ѹջ����ջ�����Ԫ�� 
void TranverseSeqStack(SeqStack s);			//��˳��ջ�д洢�����ݽ��б��� 
void Pop(SeqStack &s,int &var);				//��ջ����ջ 
void ClearSeqStack(SeqStack &s);			//���˳��ջ�д洢������ 
void GetTop(SeqStack s,int &var);			//��ȡջ��Ԫ�� 
void DestroyStack(SeqStack &s);				//��˳���������� 

int main(int argc, char** argv) {
	int i;
	SeqStack s1;
	i = InitSeqStack(s1);
	cout<<"��ʼ���ɹ���"<<i<<endl;
	i = IsEmptySeqStack(s1);
	cout<<"��ǰ��˳��ջΪ�գ�"<<i<<endl;
	i = SeqStackLength(s1); 
	cout<<"��ǰ��˳��ջ�ĳ��ȣ�"<<i<<endl;
	Push(s1);
	TranverseSeqStack(s1);
	int var,var1; 
	Pop(s1,var);
	TranverseSeqStack(s1);
	GetTop(s1,var1); 
	cout<<"��ǰջ��Ԫ��Ϊ��"<<var1;
	DestroyStack(s1);
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
	cout<<"��������Ҫ��ջ�з��뼸�����ݣ�";
	cin>>quantity;
	if(SeqStackLength(S)+quantity>S.SeqStackSize){
		S.bottom = (Elemtype*)realloc(S.bottom,(S.SeqStackSize+ExpDefaultsize)*(sizeof(Elemtype)));
		if(NULL==S.bottom){
			return 0;
		}
	}
	int i = 1;
	while(quantity!=0){
		Elemtype data;
		cout<<"���������ĵ�"<<i<<"������:";
		cin>>data;
		*S.top = data;
		S.top++;
		quantity--;
		i++; 
	}
	return 1;
}

void TranverseSeqStack(SeqStack s){
	Elemtype* p;
	if(SeqStackLength(s) == 0){
		cout<<"��������ǰ˳���Ϊ�洢����"<<endl; 
	}else{
		cout<<"˳��ջ�ı�����" ; 
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
			cout<<"��ǰ˳��ջ�ĳ���Ϊ"<<SeqStackLength(s)<<",ɾ������";
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

void GetTop(SeqStack s,int &var){
	if(SeqStackLength(s)==0){
		cout<<"��ǰ˳��ջδ�洢����,���ܻ�ȡջ��Ԫ��"<<endl; 
	}else{
		var = *(--s.top);
	}
}

void DestroyStack(SeqStack &s){
	free(s.bottom);
	s.bottom = NULL;
	s.top = NULL; 
}


