#include <iostream>
#define ElemType int 
#include <stdlib.h>

using namespace std;
typedef struct BinNode{
	ElemType data;
	struct BinNode *lchild,*rchild;
}BinNode,*BinTree;

void InitBinTree(BinTree &BT);
int InsertData(BinTree &BT,int data);
int Search(BinTree BT,int data,BinTree &last);
void InOderTranverse(BinTree BT);
int DeleteSearch(BinTree &BT,int data);
void DeleteNode(BinTree &BT);
void PreTranverse(BinTree BT);

int main(int argc, char** argv) {
	BinTree BT1;
	InitBinTree(BT1);
	int arr[7] = {45,24,53,45,12,24,90};
	for(int i = 0;i < 7; i ++){
		InsertData(BT1,arr[i]);
	}
	cout<<"插入或是创建后的二叉查找树遍历："; 
	InOderTranverse(BT1);
	DeleteSearch(BT1,24);
	cout<<endl;
	cout<<"删除24后遍历：";
	InOderTranverse(BT1);
	cout<<endl<<"前序遍历：";
	PreTranverse(BT1);
	return 0;
}

void InitBinTree(BinTree &BT){
	BT = NULL;
}

int Search(BinTree BT,int data,BinTree &last){
	if(BT == NULL){
		return 0;
	}else{
		if(data>BT->data){
			last = BT;
			return Search(BT->rchild,data,last);
		}else if(data<BT->data){
			last = BT;
			return Search(BT->lchild,data,last);
		}else{
			last = BT;
			return 1;
		}
	}
}

int InsertData(BinTree &BT,int data){			//此处插入与创建统一 
	if(BT == NULL){
		BT = (BinTree)malloc(sizeof(BinNode));
		BT->data = data;
		BT->lchild = NULL;
		BT->rchild = NULL;
		return 1;
	}else{
		BinTree last = NULL;
		int  temp = Search(BT,data,last);
		if(temp == 1){
			return 0;
		}else{
			if(data>last->data){
				last->rchild = (BinTree)malloc(sizeof(BinNode));
				last->rchild->data = data;
				last->rchild->lchild = NULL;
				last->rchild->rchild = NULL; 
			}else{
				last->lchild = (BinTree)malloc(sizeof(BinNode));
				last->lchild->data = data;
				last->lchild->lchild = NULL;
				last->lchild->rchild = NULL;
			}
			return 1;
		}
	}
}

void InOderTranverse(BinTree BT){
	if(BT){
		cout<<BT->data<<"  ";
		InOderTranverse(BT->lchild);
		PreTranverse(BT->rchild);
	}
}

int DeleteSearch(BinTree &BT,int data){
	if(NULL == BT){
		return 0;
	}else if(data > BT->data){
		return DeleteSearch(BT->rchild,data);
	}else if(data < BT->data){
		return DeleteSearch(BT->lchild,data);
	}else{
		DeleteNode(BT);
	}
	return 1;
}

void DeleteNode(BinTree &BT){				//删除节点 
	BinTree p;								//一共三种情况：	
	if(BT->lchild == NULL && BT->rchild){	//该删除的节点为叶子节点，我直接就是删除			
		p = BT;								
		BT = NULL;
		free(p);
	}else if(BT->lchild == NULL){			//没有左子树或右子树，连接后删除 
		p = BT;
		BT = BT->rchild;
		free(p);
	}else if(BT->rchild == NULL){			
		p = BT;
		BT = BT->lchild;
		free(p);
	}else{									//左右子树都有，我选择将该节点的数值由左子树的最大值替代 
		BinTree pre = BT->lchild;			
		BinTree parent = BT;				 
		while(pre->rchild != NULL){
			parent = pre;
			pre = pre->rchild;
		}
		BT->data = pre->data;
		if(parent == BT){
			BT->lchild = pre->lchild;
			free(pre);
		}else{
			parent->rchild = NULL;
			pre = NULL;
			free(pre);
		}
		
 	}
}

void PreTranverse(BinTree BT){
	if(BT){
		PreTranverse(BT->lchild);
		cout<<BT->data<<"  ";
		InOderTranverse(BT->rchild);
	}
}


















