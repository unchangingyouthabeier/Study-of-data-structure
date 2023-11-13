#include <iostream>
#include <stdlib.h>
#define ElemType char
using namespace std;

typedef struct BiThrNode{
	ElemType data;
	struct BiThrNode* lchild;
	struct BiThrNode* rchild;
	int ltag;
	int rtag;
}BiThrNode,*BiThrTree;

void CreateBirThrTree(BiThrTree &BT);
void InThreading(BiThrTree BT,BiThrTree &pre);
BiThrTree getFirst(BiThrTree BT);
BiThrTree getNext(BiThrTree BT);
void PreOrderTranverse(BiThrTree BT);

int main(int argc, char** argv) {
	BiThrTree BT1;
	BiThrTree pre = NULL;
	CreateBirThrTree(BT1);
	PreOrderTranverse(BT1);
	cout<<endl;
	InThreading(BT1,pre);
	BiThrTree BT2;
	pre->rtag = 1;
	pre->rchild = NULL;
	for(BT2 = getFirst(BT1);BT2!=NULL;BT2 = getNext(BT2)){
		cout<<BT2->data<<"  ";
	}
	return 0;
}

void CreateBirThrTree(BiThrTree &BT){
	ElemType data;
	cin>>data;
	if(data == '#'){
		BT = NULL;
	}else{
		BT = (BiThrTree)malloc(sizeof(BiThrNode));
		BT->data = data;
		BT->ltag = 0;
		BT->rtag = 0; 
		CreateBirThrTree(BT->lchild);
		CreateBirThrTree(BT->rchild);
	}
}

void InThreading(BiThrTree BT,BiThrTree &pre){
	if(BT){
		InThreading(BT->lchild,pre);
		if(BT->lchild == NULL){
			BT->ltag = 1;
			BT->lchild = pre;
		} 
		if(pre!=NULL && pre->rchild==NULL){
			pre->rtag = 1;
			pre->rchild = BT;
		}
		pre = BT;
		InThreading(BT->rchild,pre);
	}
}

BiThrTree getFirst(BiThrTree BT){
	while(BT->ltag==0){
		BT=BT->lchild;
	}
	return BT;
}

BiThrTree getNext(BiThrTree BT){
	if(BT->rtag == 1){
		return BT->rchild;
	}else{
		return getFirst(BT->rchild);
	}
}

void PreOrderTranverse(BiThrTree BT){
	if(BT){
		cout<<BT->data<<"  ";
		PreOrderTranverse(BT->lchild);
		PreOrderTranverse(BT->rchild); 
	}
}


