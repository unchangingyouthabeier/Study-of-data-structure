#include <iostream>
#include <stdlib.h>
#include <math.h>
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
void PreOrderTranverse(BiThrTree BT);
void InOrderTranverse(BiThrTree BT);
void PostTranverse(BiThrTree BT); 
int TreeDepth(BiThrTree BT);
int TreeLeaf(BiThrTree BT);
void InThreading(BiThrTree BT,BiThrTree &pre);
BiThrTree getFirst(BiThrTree BT);
BiThrTree getNext(BiThrTree BT);


int main(int argc, char** argv) {
	BiThrTree BT1;
	BiThrTree pre = NULL;
	CreateBirThrTree(BT1);
	cout<<"ǰ�������";
	PreOrderTranverse(BT1);
	cout<<endl;
	cout<<"���������";
	InOrderTranverse(BT1);
	cout<<endl;
	cout<<"���������";
	PostTranverse(BT1);
	cout<<endl;
	cout<<"��ǰ������ȣ��߶ȣ���"<<TreeDepth(BT1)<<endl;
	cout<<"��ǰҶ�ӽڵ�ĸ�����"<<TreeLeaf(BT1)<<endl;
	InThreading(BT1,pre);
	BiThrTree BT2;
	pre->rtag = 1;
	pre->rchild = NULL;
	cout<<"��������������";
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
		cout<<data<<"�����ӣ�"; 
		CreateBirThrTree(BT->lchild);
		cout<<data<<"���Һ��ӣ�";
		CreateBirThrTree(BT->rchild);
	}
}

void PreOrderTranverse(BiThrTree BT){
	if(BT){
		cout<<BT->data<<"  ";
		PreOrderTranverse(BT->lchild);
		PreOrderTranverse(BT->rchild); 
	}
}

void InOrderTranverse(BiThrTree BT){
	if(BT){
		InOrderTranverse(BT->lchild);
		cout<<BT->data<<"  ";
		InOrderTranverse(BT->rchild);
	}
}

void PostTranverse(BiThrTree BT){
	if(BT){
		PostTranverse(BT->lchild);
		PostTranverse(BT->rchild);
		cout<<BT->data<<"  ";
	}
}

int TreeDepth(BiThrTree BT){			//�ø߶������ 
	if(BT==NULL){
		return 0;
	}
	int lefthight = TreeDepth(BT->lchild);
	int righthight = TreeDepth(BT->rchild);
	return 1 + max(lefthight,righthight); 
}

int TreeLeaf(BiThrTree BT){
	if(BT->lchild == NULL && BT->rchild == NULL){
		return 1;
	}
	return TreeLeaf(BT->lchild) + TreeLeaf(BT->rchild);
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




