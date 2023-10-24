#include <iostream>
#include <stdlib.h>
#define Default_Size 7
#define ElemType int 

using namespace std;
typedef struct SeqQueue{
	ElemType *base;
	int front;
	int rear;
}SeqQueue;

int InitQueue(SeqQueue &sq);				  	//��ʼ��˳����� 
int SeqQueueLength(SeqQueue sq);				//��ȡ˳����еĳ��� 
void TranverseSeqQueue(SeqQueue sq);			//��˳����н��б��� 
int EnQueue(SeqQueue &sq,int data);				//˳�������� 
void DeQueue(SeqQueue &sq,int &var);			//˳����г��� 
void GetHead(SeqQueue sq,int &e);				//�õ���ͷԪ�� 
void ClearQueue(SeqQueue &sq);					//��ն��� 
void QueueEmpty(SeqQueue sq);					//�ж϶����Ƿ�Ϊ�� 
void DestroyQueue(SeqQueue &sq);				//����˳����� 

int main(int argc, char** argv) {
	SeqQueue sq1;
	cout<<"��û�г�ʼ��ʱsq1.front="<<sq1.front<<endl;
	cout<<"û�г�ʼ��ʱsq1.base="<<sq1.base<<endl; 
	int flag;
	int length;
	int var;
	int e1;
	flag = InitQueue(sq1);
	cout<<"��ʼ���ɹ�:"<<flag<<endl;
	cout<<"��ʼ�������ǰsq1.base[sq1.front]="<<sq1.base[sq1.front]<<endl;
	length = SeqQueueLength(sq1);
	cout<<"��ǰ˳����еĳ���Ϊ��"<<length<<endl;
	cout<<"δ����ʱ�Ķ��б���Ϊ��";
	TranverseSeqQueue(sq1);
	EnQueue(sq1,1);
	EnQueue(sq1,2); 
	EnQueue(sq1,3);
	EnQueue(sq1,4);
	EnQueue(sq1,5);
	EnQueue(sq1,6);
	EnQueue(sq1,7);
	EnQueue(sq1,8);
	cout<<"��Ӻ�ı�����"; 
	TranverseSeqQueue(sq1);
	DeQueue(sq1,var);
	cout<<"���Ӻ�ı�����";
	TranverseSeqQueue(sq1);
	GetHead(sq1,e1);
	cout<<"��ǰ����Ԫ��Ϊ��"<<e1<<endl;
	ClearQueue(sq1);
	QueueEmpty(sq1);
	length = SeqQueueLength(sq1);
	cout<<"��յĶ��г��ȣ�"<<length<<endl;
	cout<<"��ʼ��������ǰsq1.base="<<sq1.base<<endl; 
	DestroyQueue(sq1);
	cout<<"���ٺ�sq1.front="<<sq1.front<<endl;
	cout<<"���ٺ�sq1.base="<<sq1.base<<endl;
	return 0;
}

int InitQueue(SeqQueue &sq){
	sq.base = (ElemType*)malloc(Default_Size*sizeof(ElemType));
	if(NULL == sq.base){
		return 0;
	}
	sq.front = 0;
	sq.rear = 0;
	return 1;
}

int SeqQueueLength(SeqQueue sq){
	int i;
	int count;
	count = 0;
	i = sq.front;
	while(i!=sq.rear){
		count++;
		i = (i+1)%Default_Size;
	}
	return count;
}

void TranverseSeqQueue(SeqQueue sq){
	int i;
	i = sq.front;
	while(i!=sq.rear){
		cout<<sq.base[i]<<"  ";
		i = (i+1)%Default_Size;
	}
	cout<<endl;
}

int EnQueue(SeqQueue &sq,int data){
	if(sq.front==(sq.rear+1)%Default_Size){
		return 0;
	}
	sq.base[sq.rear] = data;
	sq.rear = (sq.rear+1)%Default_Size;
	return 1;
}

void DeQueue(SeqQueue &sq,int &var){
	while(1){
		if(SeqQueueLength(sq) == 0){
			cout<<"��ǰ����Ϊ�գ��������"<<endl;
			break;
		}else{
			break;
		}
	}
	var = sq.base[sq.front];
	sq.base[sq.front] = 0;
	sq.front = (sq.front+1)%Default_Size;
}

void GetHead(SeqQueue sq,int &e){
	while(1){
		if(SeqQueueLength(sq) == 0){
			cout<<"��ǰ����Ϊ�գ�û�ж���Ԫ�ؿɷ���"<<endl; 
			break;
		}else{
			break;
		}
	}
	e = sq.base[sq.front];
}

void ClearQueue(SeqQueue &sq){
	while(sq.front != sq.rear){
		sq.base[sq.front] = 0;
		sq.front = (sq.front+1)%Default_Size;
	}
}

void QueueEmpty(SeqQueue sq){
	if(sq.front == sq.rear){
		cout<<"��ǰ����Ϊ��"<<endl; 
	}else{
		cout<<"��ǰ���в�Ϊ��"<<endl;
	}
}

void DestroyQueue(SeqQueue &sq){
	free(sq.base);
}
