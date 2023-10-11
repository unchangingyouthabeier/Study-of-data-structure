#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct DouCircularLinkedList{
	struct DouCircularLinkedList* prior;
	int data;
	struct DouCircularLinkedList* next;
}DouCircularLinkedList,*Link;

int InitLinkedList(Link &L);					//初始化双向循环链表 
int LinkedListLength(Link L);					//获取链表的长度 
void TranverseLinkedList(Link L);				//遍历双向循环链表 
void InsertLinkedList(Link L);					//向双向循环链表中的指定位置插入指定个数的数据项 
void DeleteLinkedList(Link L, int &var);		//对指定位置的节点进行删除 
int LocateData(Link L);							//对于指定的数据获取其位置 
void ClearLinkedList(Link L);					//清空双向循环链表 

int main(int argc, char** argv) {
	Link L1;
	int i;
	int var;
	i = InitLinkedList(L1);
	cout<<"初始化成功："<<i<<endl;
	i = LinkedListLength(L1);
	cout<<"初始化后链表的长度："<<i<<endl;
	TranverseLinkedList(L1);
	InsertLinkedList(L1);
	TranverseLinkedList(L1);
	DeleteLinkedList(L1,var);
	TranverseLinkedList(L1);
	LocateData(L1);
	ClearLinkedList(L1);
	TranverseLinkedList(L1);
	return 0;
}

int InitLinkedList(Link &L){
	L = (Link)malloc(sizeof(DouCircularLinkedList));
	if(NULL == L){
		return 0;
	}
	L->prior = L;
	L->next = L;
	return 1;
}

int LinkedListLength(Link L){
	Link p;
	int count = 0;
	p = L;
	p = p->next;
	while(p != L){
		p = p->next;
		count++;
	}
	return count;
}

void TranverseLinkedList(Link L){
	Link p;
	p = L;
	p = p->next;
	if(LinkedListLength(L)==0){
		cout<<"遍历：当前链表长度为0，未存储数据"<<endl; 
	}else{
		cout<<"链表的遍历为：";
	}
	while(p!=L){
		cout<<p->data<<"  ";
		p = p->next;
	}
	cout<<endl;
}

void InsertLinkedList(Link L){
	int loc; 
	int quantity;
	int quantity1;
	cout<<"请输入插入的位置：";
	cin>>loc;
	while(1){
		if(loc>LinkedListLength(L)+1 || loc<=0){
			cout<<"当前链表的长度为："<<LinkedListLength(L)<<",请重新输入插入位置：";
			cin>>loc; 
		}else{
			break;
		}
	}
	cout<<"请输入插入数据的个数:";
	cin>>quantity;
	quantity1 = quantity;
	cout<<endl;
	while(quantity!=0){
		int i = 1;
		int data;
		Link p,temp;
		temp = (Link)malloc(sizeof(DouCircularLinkedList));
		p = L;
		while(i <= loc-1){
			p = p->next;
			i++;
		}
		cout<<"请输入插入的第"<<quantity1-quantity+1<<"个数据:";
		cin>>data;
		cout<<endl;
		temp->data = data;
		temp->next = p->next;
		temp->prior = p;
		p->next = temp;
		temp->next->prior = temp;
		quantity--;
	}
}

void DeleteLinkedList(Link L,int &var){
	int loc;
	Link pa, pb;
	cout<<"请输入需要删除哪个位置的数据：";
	cin>>loc;
	cout<<endl;
	while(1){
		if(loc>LinkedListLength(L) || loc == 0){
			cout<<"当前链表的长度为:"<<LinkedListLength(L)<<"删除位置有误请重新输入:";
			cin>>loc;
			cout<<endl;	
		}else{
			break;
		}		
	}
	pa = L;
	pb = L;
	pb = pb->next;
	while(loc>1){
		pa = pa->next;
		pb = pb->next;
		loc--;
	}
	pa->next = pb->next;
	pb->next->prior = pa;
	var = pb->data;
	free(pb);
}

int LocateData(Link L){
	int elem;
	Link p;
	int count = 1;
	cout<<"请输入需要查找位置的数据:";
	cin>>elem;
	p = L;
	p = p->next;
	while(p != L){
		if(p->data == elem){
			cout<<"该数据在链表的第"<<count<<"个节点"<<endl; 
			return count;
		}
		p = p->next;
		count++;
	}
	cout<<"该数据不存在于链表中"<<endl; 
	return -1;
}

void ClearLinkedList(Link L){
	Link pa,pb;
	pa = L;
	pb = L;
	pb = pb->next;
	while(pb!=L){
		pa->next = pb->next;
		pb->next->prior = pa;
		free(pb);
		pb = pa->next;
	}
	free(pa);
}


