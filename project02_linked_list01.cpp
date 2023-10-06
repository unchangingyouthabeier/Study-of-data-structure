#include <iostream>
#include<stdlib.h>
using namespace std;
typedef struct LinkedList{
	int data;
	struct LinkedList* next;
}LinkedList,*Link;

int InitLinkedList(Link &L);						//������ĳ�ʼ��������һ��ͷ�ڵ� 
void TranverseLinkedList(Link L);					//���������� 
int LinkedListLength(Link L);						//��ȡ������ĳ��ȣ�Ĭ��ͷ�ڵ�Ϊ0�� 
void InsertLinkedList(Link &L);						//�������ָ��λ�ò���ָ�������Ľڵ� 
void DeleteLinkedList(Link &L,int &var);			//ɾ��ָ��λ�õĽڵ㲢����ɾ���ڵ������ 
int LocateLinkedList(Link L);						//����ָ���������ڽڵ�λ�� 
void CreateLinkedList(Link &L);						//����һ��ָ�����ȵĵ����� 
void MergeLinkedList(Link &La,Link &Lb,Link &Lc);	//�������ǵݼ�����ĵ�����ʵ�ֹ鲢����	
void FreeLinkedList(Link &L);						//�ͷ�ָ����������ڴ����ռ� 



int main(int argc, char** argv) {
	Link L1;
	int i;
	i = InitLinkedList(L1);										//��ʼ��L1,Ϊͷ�ڵ�����ڿռ� 
	cout<<"��ʼ���ɹ���"<<i<<endl;								
	int length;													
	TranverseLinkedList(L1);									//����L1 
	length = LinkedListLength(L1);								//��ȡ��ʼ��֮������ĳ��� 
	cout<<"δ��������ʱ��������L1�ĳ���Ϊ��"<<length<<endl;
	InsertLinkedList(L1);										//��L1�в���ָ�������Ľڵ� 
	TranverseLinkedList(L1);									//���������ĵ�����L1 
	length = LinkedListLength(L1);								//��ȡ���������ĳ��� 
	cout<<"�������ݺ󣬵�����L1�ĳ���Ϊ��"<<length<<endl;
	int var;
	DeleteLinkedList(L1,var);									//ɾ��L1ָ��λ�õĽڵ� 
	TranverseLinkedList(L1);									//��������ɾ����ĵ�����L1 
	length = LinkedListLength(L1);								//��ȡɾ��������L1�ĳ��� 
	cout<<"ɾ��������ĳ���Ϊ��"<<length<<endl;
	int loc;
	loc = LocateLinkedList(L1);									//����ָ��������L1�е��ĸ��ڵ�λ�� 
	cout<<"���ҵ�Ԫ�����ڵ������λ��Ϊ��"<<loc<<endl;
	Link L2;
	CreateLinkedList(L2);										//����ָ�����ȵĵ�����L2 
	TranverseLinkedList(L2);									//����L2 
	Link La,Lb,Lc;
	cout<<"�밴�ǵݼ����򴴽����Ա�La,Lb"<<endl;
	CreateLinkedList(La);										//�����ǵݼ�����ĵ�����La 
	CreateLinkedList(Lb);										//�����ǵݼ�����ĵ�����Lb 
	MergeLinkedList(La, Lb, Lc);								//�鲢�����ǵݼ��ĵ����� 
	TranverseLinkedList(Lc);									//�����鲢��ĵ�����Lc
	FreeLinkedList(L2);											//�ͷŵ�����L2����������ڴ�ռ� 
	FreeLinkedList(L1);											//�ͷŵ�����L1����������ڴ�ռ�
	FreeLinkedList(Lc);											//�ͷŹ鲢La,Lb��ĵ�����Lc����������ڴ�ռ� 
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
	cout<<"������ı�����";
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
	cout<<"����������λ�ã�";
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
			cout<<"������ĳ���Ϊ��"<<count<<"  ����λ���������޸Ĳ���λ�ã�";
			cin>>loc;
			cout<<endl;	
		}else{
			break;
		}
	}
	int quantity;
	cout<<"������Ҫ���뼸�����ݣ�";
	cin>>quantity;
	cout<<endl;
	Link temp;
	int i = 1;
	int data;
	while(quantity > 0){
		temp = (Link)malloc(sizeof(LinkedList));
		cout<<"�������"<<i<<"��������������ݣ�";
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
	cout<<"��������Ҫɾ���ĸ���λ��Ԫ�أ�";
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
			cout<<"������ĳ���Ϊ:"<<length<<" ,ɾ��λ����������������λ�ã�";
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
	cout<<"��������Ҫ���ҵ�Ԫ�أ�";
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
	cout<<"�����봴��������ĳ��ȣ�";
	cin>>length;
	cout<<endl;
	for(i = length; i > 0; i--){
		Link p;
		p = (Link)malloc(sizeof(LinkedList));
		cout<<"�������"<<i<<"���ڵ�洢�����ݣ�";
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

