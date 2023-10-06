#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct LinkedList{
	int data;
	struct LinkedList* next;
}LinkedList,*Link;

int InitLinkedList(Link &L);						//单链表的初始化，创建一个头节点 
void TranverseLinkedList(Link L);					//遍历单链表 
int LinkedListLength(Link L);						//获取单链表的长度（默认头节点为0） 
void InsertLinkedList(Link &L);						//向单链表的指定位置插入指定个数的节点 
void DeleteLinkedList(Link &L,int &var);			//删除指定位置的节点并返回删除节点的数据 
int LocateLinkedList(Link L);						//查找指定数据所在节点位置 
void CreateLinkedList(Link &L);						//创建一个指定长度的单链表 
void MergeLinkedList(Link &La,Link &Lb,Link &Lc);	//将两个非递减排序的单链表实现归并操作	
void FreeLinkedList(Link &L);						//释放指定单链表的内存分配空间 



int main(int argc, char** argv) {
	Link L1;
	int i;
	i = InitLinkedList(L1);										//初始化L1,为头节点分配内空间 
	cout<<"初始化成功："<<i<<endl;								
	int length;													
	TranverseLinkedList(L1);									//遍历L1 
	length = LinkedListLength(L1);								//获取初始化之后单链表的长度 
	cout<<"未插入数据时，单链表L1的长度为："<<length<<endl;
	InsertLinkedList(L1);										//向L1中插入指定个数的节点 
	TranverseLinkedList(L1);									//遍历插入后的单链表L1 
	length = LinkedListLength(L1);								//获取插入后单链表的长度 
	cout<<"插入数据后，单链表L1的长度为："<<length<<endl;
	int var;
	DeleteLinkedList(L1,var);									//删除L1指定位置的节点 
	TranverseLinkedList(L1);									//遍历经过删除后的单链表L1 
	length = LinkedListLength(L1);								//获取删除后单链表L1的长度 
	cout<<"删除后单链表的长度为："<<length<<endl;
	int loc;
	loc = LocateLinkedList(L1);									//查找指定数据在L1中的哪个节点位置 
	cout<<"查找的元素所在单链表的位置为："<<loc<<endl;
	Link L2;
	CreateLinkedList(L2);										//创建指定长度的单链表L2 
	TranverseLinkedList(L2);									//遍历L2 
	Link La,Lb,Lc;
	cout<<"请按非递减排序创建线性表La,Lb"<<endl;
	CreateLinkedList(La);										//创建非递减排序的单链表La 
	CreateLinkedList(Lb);										//创建非递减排序的单链表Lb 
	MergeLinkedList(La, Lb, Lc);								//归并两个非递减的单链表 
	TranverseLinkedList(Lc);									//遍历归并后的单链表Lc
	FreeLinkedList(L2);											//释放单链表L2所有申请的内存空间 
	FreeLinkedList(L1);											//释放单链表L1所有申请的内存空间
	FreeLinkedList(Lc);											//释放归并La,Lb后的单链表Lc所有申请的内存空间 
	return 0;
}



int InitLinkedList(Link &L){
	L = (Link)malloc(sizeof(LinkedList));
	if(NULL == L){
		return 0;
	}
	L->next = NULL;
	return 1; 
}

void TranverseLinkedList(Link L){
	Link p;
	p = L;
	p = p->next;
	cout<<"单链表的遍历：";
	while(p != NULL){
		cout<<p->data<<"  ";
		p = p->next;
	}
	cout<<endl;
}

int LinkedListLength(Link L){
	Link p;
	p = L;
	p = p->next;
	int count = 0;
	while(p!=NULL){
		count++;
		p = p->next;
	}
	return count;
}

void InsertLinkedList(Link &L){
	int loc;
	cout<<"请输入插入的位置：";
	cin>>loc;
	cout<<endl;
	Link p;
	p = L;
	int count = 0;
	p = p->next;
	while(p!= NULL){
		count++;
		p = p -> next;
	}
	while(1){
		if(loc > (count+1) || loc == 0){
			cout<<"单链表的长度为："<<count<<"  插入位置有误，请修改插入位置：";
			cin>>loc;
			cout<<endl;	
		}else{
			break;
		}
	}
	int quantity;
	cout<<"请输入要插入几个数据：";
	cin>>quantity;
	cout<<endl;
	Link temp;
	int i = 1;
	int data;
	while(quantity > 0){
		temp = (Link)malloc(sizeof(LinkedList));
		cout<<"请输入第"<<i<<"个插入链表的数据：";
		cin>>data;
		temp->data = data;
		temp->next = NULL;
		cout<<endl;
		int col = loc;
		if(col == 1 && L->next == NULL){
			temp->next = NULL;
			L->next = temp;
		}else{
			Link p1,p2;
			p1 = L;
			p2 = L; 
			p2 = p2->next;
			while(col > 0){
				if(col == 1){
					temp->next = p2;
					p1->next = temp;
					break;
				}
				p1 = p1->next;
				p2 = p2->next;
				if(p2 == NULL){
					temp->next = NULL;
					p1->next = temp;
					break;
				}
				col--;
			}
		}
		i++;
		quantity--;
	}	
}

void DeleteLinkedList(Link &L,int &var){
	int loc;
	cout<<"请输入需要删除哪个的位置元素：";
	cin>>loc;
	int length = 0;
	Link p;
	p = L;
	while(p != NULL){
		length++;
		p = p->next; 
	}
	int col = loc;
	while(1){
		if(col > length || col == 0){
			cout<<"单链表的长度为:"<<length<<" ,删除位置有误请重新输入位置：";
			cin>>col;
			cout<<endl;
		}else{
			break;
		}
	}
	Link p1,p2;
	p1 = L;
	p2 = L;
	p2 = p2->next;
	while(col > 0){
		if(col == 1 && p2->next!=NULL){
			p1->next = p2->next;
			var = p2->data;
			free(p2);
			break;
		}else if(NULL == p2->next){
			var = p2->data;
			p1->next = NULL;
			free(p2);
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
		col--;
	}
}

int LocateLinkedList(Link L){
	int elem;
	cout<<"请输入需要查找的元素：";
	cin>>elem;
	cout<<endl;
	Link p;
	p = L;
	p = p->next;
	int count = 0;
	while(p != NULL){
		count++;
		if(p->data == elem){
			return count;
		}
		p = p->next;
	}
	return -1;
} 

void CreateLinkedList(Link &L){
	L = (Link)malloc(sizeof(LinkedList));
	L->next = NULL;
	int length,i;
	cout<<"请输入创建单链表的长度：";
	cin>>length;
	cout<<endl;
	for(i = length; i > 0; i--){
		Link p;
		p = (Link)malloc(sizeof(LinkedList));
		cout<<"请输入第"<<i<<"个节点存储的数据：";
		cin>>p->data;
		cout<<endl;
		if(i == length){
			p->next = NULL;
		}else{
			p->next = L->next;
		}
		L->next = p;
	} 
} 

void MergeLinkedList(Link &La, Link &Lb, Link &Lc){
	Link pa,pb,pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;
	while(pa&&pb){
		if(pa->data>=pb->data){
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}else{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
	}
	pc->next = pa?pa:pb;
	free(Lb);
} 



void FreeLinkedList(Link &L){
	Link p;
	while(L != NULL){
		p = L;
		L = p->next;
		free(p);
	}
}

