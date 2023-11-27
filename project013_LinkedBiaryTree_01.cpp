#include <iostream>
#define ElemType char
typedef struct LinkBinNode{
	ElemType data;
	struct LinkBinTree* lchild;
	struct LinkBinTree* rchild;
}BinTreeNode,*LinkBinTree;

void InitLinkBinTree(LinkBinTree &bt);
void CreateLinkBinTree(LinkBinTree bt);

int main(int argc, char** argv) {
	LinkBinTree bt1;
	InitLinkBinTree(bt1);
	CreateLinkBinTree(bt1);
	return 0;
}

void InitLinkBinTree(LinkBinTree &bt){
	bt = NULL;
}

void CreateLinkBinTree(LinkBinTree bt){
	ElemType data;
	cin>>data;
	
}
