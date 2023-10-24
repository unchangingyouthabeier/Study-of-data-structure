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

int InitQueue(SeqQueue &sq);				  	//初始化顺序队列 
int SeqQueueLength(SeqQueue sq);				//获取顺序队列的长度 
void TranverseSeqQueue(SeqQueue sq);			//对顺序队列进行遍历 
int EnQueue(SeqQueue &sq,int data);				//顺序队列入队 
void DeQueue(SeqQueue &sq,int &var);			//顺序队列出队 
void GetHead(SeqQueue sq,int &e);				//得到队头元素 
void ClearQueue(SeqQueue &sq);					//清空队列 
void QueueEmpty(SeqQueue sq);					//判断队列是否为空 
void DestroyQueue(SeqQueue &sq);				//销毁顺序队列 

int main(int argc, char** argv) {
	SeqQueue sq1;
	cout<<"当没有初始化时sq1.front="<<sq1.front<<endl;
	cout<<"没有初始化时sq1.base="<<sq1.base<<endl; 
	int flag;
	int length;
	int var;
	int e1;
	flag = InitQueue(sq1);
	cout<<"初始化成功:"<<flag<<endl;
	cout<<"初始化后，入队前sq1.base[sq1.front]="<<sq1.base[sq1.front]<<endl;
	length = SeqQueueLength(sq1);
	cout<<"当前顺序队列的长度为："<<length<<endl;
	cout<<"未插入时的队列遍历为：";
	TranverseSeqQueue(sq1);
	EnQueue(sq1,1);
	EnQueue(sq1,2); 
	EnQueue(sq1,3);
	EnQueue(sq1,4);
	EnQueue(sq1,5);
	EnQueue(sq1,6);
	EnQueue(sq1,7);
	EnQueue(sq1,8);
	cout<<"入队后的遍历："; 
	TranverseSeqQueue(sq1);
	DeQueue(sq1,var);
	cout<<"出队后的遍历：";
	TranverseSeqQueue(sq1);
	GetHead(sq1,e1);
	cout<<"当前对首元素为："<<e1<<endl;
	ClearQueue(sq1);
	QueueEmpty(sq1);
	length = SeqQueueLength(sq1);
	cout<<"清空的队列长度："<<length<<endl;
	cout<<"初始化后，销毁前sq1.base="<<sq1.base<<endl; 
	DestroyQueue(sq1);
	cout<<"销毁后sq1.front="<<sq1.front<<endl;
	cout<<"销毁后sq1.base="<<sq1.base<<endl;
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
			cout<<"当前队列为空，无需出队"<<endl;
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
			cout<<"当前队列为空，没有对首元素可返回"<<endl; 
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
		cout<<"当前队列为空"<<endl; 
	}else{
		cout<<"当前队列不为空"<<endl;
	}
}

void DestroyQueue(SeqQueue &sq){
	free(sq.base);
}
