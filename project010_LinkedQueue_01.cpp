#include <iostream>
#include <stdlib.h>

using namespace std;
typedef struct Node{
	int data;
	struct Node* next;
}Node,*Link;

typedef struct LinkedQueue{
	Link front;
	Link rear;
}LinkedQueue;
int InitLinkedQueue(LinkedQueue &lq);			//初始化链队列 
void TranverseLinkedQueue(LinkedQueue lq);		//对链队列进行初始化 
int LinkedQueueLength(LinkedQueue lq);			//获取链队列的长度 
int EnLinkedQueue(LinkedQueue &lq,int data);	//在链队列中进行入队 
int DeLinkedQueue(LinkedQueue &lq,int &var);	//在链队列中进行出队 

int main(int argc, char** argv) {
	LinkedQueue lq1;
	int flag;
	int length;
	int var;
	flag = InitLinkedQueue(lq1);
	cout<<"初始化成功:"<<flag<<endl;
	cout<<"未入对时遍历："; 
	TranverseLinkedQueue(lq1);
	length = LinkedQueueLength(lq1);
	cout<<"未入队时，队列长度："<<length<<endl;
	EnLinkedQueue(lq1,23);
	EnLinkedQueue(lq1,33);
	EnLinkedQueue(lq1,43);
	EnLinkedQueue(lq1,53);
	cout<<"入队后的遍历：";
	TranverseLinkedQueue(lq1);
	DeLinkedQueue(lq1,var);
	cout<<"出队一次后遍历：";
	TranverseLinkedQueue(lq1);
	return 0;
}

int InitLinkedQueue(LinkedQueue &lq){
	lq.front = (Link)malloc(sizeof(Node));
	if(NULL == lq.front){
		return 0;
	}
	lq.rear = lq.front;
	lq.front->next = NULL;
	return 1;
}

void TranverseLinkedQueue(LinkedQueue lq){
	Link p;
	p = lq.front;
	p = p->next;
	while(p!=NULL){
		cout<<p->data<<"  ";
		p = p->next;
	}
	cout<<endl;
}

int LinkedQueueLength(LinkedQueue lq){
	Link p;
	int count;
	count = 0;
	p = lq.front;
	p = p->next;
	while(p!=NULL){
		count++;
		p = p->next;
	}
	return count;
}

int EnLinkedQueue(LinkedQueue &lq,int data){
	Link temp;
	temp = (Link)malloc(sizeof(Node));
	if(NULL==temp){
		return 0;
	}
	temp->data = data;
	lq.rear->next = temp;
	lq.rear= temp;
	lq.rear->next=NULL;
	return 1;
}

int DeLinkedQueue(LinkedQueue &lq,int &var){
	Link p;
	if(LinkedQueueLength(lq)==0){
		cout<<"当前队列长度为0,不能出队列";
		return 0; 
	}
	p = lq.front;
	p = p->next;
	var = p->data;
	lq.front->next = p->next;
	free(p);
	if(LinkedQueueLength(lq)==0){
		lq.rear = lq.front;
	}	
	return 1;
}


