#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct JosephRing{
	int data;
	struct JosephRing* next;
}JosephRing,*Link;

int CreateJosephRing(Link &L);
void TranverseJosephRing(Link L);
void ExecuteJosephRing(Link L);
int JosephRingLength(Link L);

int main(int argc, char** argv) {
	Link L1;
	CreateJosephRing(L1);
	TranverseJosephRing(L1);
	ExecuteJosephRing(L1);
	TranverseJosephRing(L1);
	return 0;
}

int CreateJosephRing(Link &L){
	int length;
	Link p1;
	int count = 1; 
	L = (Link)malloc(sizeof(JosephRing));
	if(NULL == L){
		return 0;
	}
	L->next = L;
	cout<<"请输入需要创建的JosephRing的长度:";
	cin>>length;
	p1 = L;
	while(length!=0){
		Link temp;
		temp = (Link)malloc(sizeof(JosephRing));
		temp->data = count;
		p1->next = temp;
		p1 = p1->next;
		length--;
		count++;
	}
	p1->next = L;
	return 1;
}

void TranverseJosephRing(Link L){
	Link p;
	p = L;
	p = p->next;
	cout<<"约瑟夫环的遍历:";
	while(p != L){
		cout<<p->data<<"  ";
		p = p->next;
	}
	cout<<endl;
}

void ExecuteJosephRing(Link L){
	Link p1,p2;
	p1 = L;
	p2 = L;
	p1 = p1->next;
	while(JosephRingLength(L)!=1){
		int i;
		for(i = 2; i <= 3; i++){
			p1 = p1->next;
			p2 = p2->next;
			if(p1 == L || p2== L){
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		p2->next = p1->next;
		free(p1);
		p1 = p2->next;
	}
}

int JosephRingLength(Link L){
	Link p;
	int count = 1;
	p = L;
	p = p->next;
	while(p->next != L){
		p = p->next;
		count++;
	}
	return count;
}
