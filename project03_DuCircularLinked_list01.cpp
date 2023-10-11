#include <iostream>
#include<stdlib.h>
using namespace std;

typedef struct DouCircularLinkedList{
	struct DouCircularLinkedList* prior;
	int data;
	struct DouCircularLinkedList* next;
}DouCircularLinkedList,*Link;

int InitLinkedList(Link &L);					//��ʼ��˫��ѭ������ 
int LinkedListLength(Link L);					//��ȡ����ĳ��� 
void TranverseLinkedList(Link L);				//����˫��ѭ������ 
void InsertLinkedList(Link L);					//��˫��ѭ�������е�ָ��λ�ò���ָ�������������� 
void DeleteLinkedList(Link L, int &var);		//��ָ��λ�õĽڵ����ɾ�� 
int LocateData(Link L);							//����ָ�������ݻ�ȡ��λ�� 
void ClearLinkedList(Link L);					//���˫��ѭ������ 

int main(int argc, char** argv) {
	Link L1;
	int i;
	int var;
	i = InitLinkedList(L1);
	cout<<"��ʼ���ɹ���"<<i<<endl;
	i = LinkedListLength(L1);
	cout<<"��ʼ��������ĳ��ȣ�"<<i<<endl;
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
		cout<<"��������ǰ������Ϊ0��δ�洢����"<<endl; 
	}else{
		cout<<"����ı���Ϊ��";
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
	cout<<"����������λ�ã�";
	cin>>loc;
	while(1){
		if(loc>LinkedListLength(L)+1 || loc<=0){
			cout<<"��ǰ����ĳ���Ϊ��"<<LinkedListLength(L)<<",�������������λ�ã�";
			cin>>loc; 
		}else{
			break;
		}
	}
	cout<<"������������ݵĸ���:";
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
		cout<<"���������ĵ�"<<quantity1-quantity+1<<"������:";
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
	cout<<"��������Ҫɾ���ĸ�λ�õ����ݣ�";
	cin>>loc;
	cout<<endl;
	while(1){
		if(loc>LinkedListLength(L) || loc == 0){
			cout<<"��ǰ����ĳ���Ϊ:"<<LinkedListLength(L)<<"ɾ��λ����������������:";
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
	cout<<"��������Ҫ����λ�õ�����:";
	cin>>elem;
	p = L;
	p = p->next;
	while(p != L){
		if(p->data == elem){
			cout<<"������������ĵ�"<<count<<"���ڵ�"<<endl; 
			return count;
		}
		p = p->next;
		count++;
	}
	cout<<"�����ݲ�������������"<<endl; 
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


