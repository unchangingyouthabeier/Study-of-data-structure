#include <iostream>
#include <math.h>
#include <stdlib.h>
#define Default_Size 100
#define NIL 999


using namespace std;
typedef int SeqBinaryTree[Default_Size];				//创建存储树的数据结构 （以顺序结构存储） 
void InitTree(SeqBinaryTree sbt);						//初始化树将存储的数据改为默认为空的数据 
int Depth(SeqBinaryTree sbt);							//获取树的深度 
int EmptyTree(SeqBinaryTree sbt);						//判断是否为空树 
void PrintTree(SeqBinaryTree sbt);						//用层序遍历的方式遍历树 
void CreateTree(SeqBinaryTree sbt);						//创建一个树（从键盘录入数据） 
int Root(SeqBinaryTree sbt);							//获取根节点数据 
int Value(SeqBinaryTree sbt,int pos);					//获取指定节点的数值 
int Assign(SeqBinaryTree sbt,int pos,int data);			//对数据为空的指定节点赋值 
//int InsertChild(SeqBinaryTree sbt1,int pos,SeqBinaryTree sbt2);
int Parent(SeqBinaryTree sbt,int pos);					//获取指定节点的双亲节点 
int LeftChild(SeqBinaryTree sbt,int pos);				//获取指定节点的左孩子节点 
int RightChild(SeqBinaryTree sbt,int pos);				//获取指定节点的右孩子节点 
int LeftSibling(SeqBinaryTree sbt,int pos);				//获取指定右节点的左兄弟节点 
int RightSibling(SeqBinaryTree sbt,int pos);			//获取指定左节点的右兄弟节点 
void PreOrderTranverse(SeqBinaryTree sbt,int pos);		//进行前序遍历 （中左右） 
void InOrderTranverse(SeqBinaryTree sbt,int pos);		//进行中序遍历 （左中右） 
void PostOrderTranverse(SeqBinaryTree sbt,int pos);		//进行后序遍历（左右中） 
void ClearTree(SeqBinaryTree sbt);						//清空树 
void DestroyTree(SeqBinaryTree sbt);					//销毁树 

int main(int argc, char** argv) {
	SeqBinaryTree sbt1;
	InitTree(sbt1);
	cout<<"初始化后为空树："<<EmptyTree(sbt1)<<endl;
	cout<<"当前深度为："<<Depth(sbt1)<<endl;
	CreateTree(sbt1);
	cout<<"创建树后进行遍历："<<endl;
	PrintTree(sbt1);
	cout<<"当前树的根节点为："<<Root(sbt1)<<endl;
	cout<<"二叉树中的第1个节点值为："<<Value(sbt1,1)<<endl;
	Assign(sbt1,5,11);
	cout<<"对其节点赋值后遍历："<<endl;
	PrintTree(sbt1);
//	cout<<"请创建第二个树："<<endl; 
//	CreateSeqBinary(sbt2);
//	InsertChild(sbt1,2,sbt2);
	cout<<"第三个节点的双亲节点值："<<Parent(sbt1,3)<<endl;
	cout<<"第2个节点的左孩子的值："<<LeftChild(sbt1,2)<<endl;
	cout<<"第2个节点的右孩子的值："<<RightChild(sbt1,2)<<endl;
	cout<<"第一个节点的左兄弟节点："<<LeftSibling(sbt1,1)<<endl;
	cout<<"第一个节点的右兄弟节点："<<RightSibling(sbt1,1)<<endl;
	cout<<"前序遍历：" ; 
	PreOrderTranverse(sbt1,1);
	cout<<endl;
	cout<<"中序遍历：";
	InOrderTranverse(sbt1,1);
	cout<<endl;
	cout<<"后序遍历：";
	PostOrderTranverse(sbt1,1);
	cout<<endl;
//	InsertChild(sbt1,stb2,);
	ClearTree(sbt1);
	cout<<"对树进行清空后遍历：";
	PrintTree(sbt1); 
	DestroyTree(sbt1);
	return 0;
}

void InitTree(SeqBinaryTree sbt){
	int i;
	for(i = 0; i <= Default_Size-1;i++){
		sbt[i] = NIL;
	}
}

int Depth(SeqBinaryTree sbt){
	int i;
	for(i = Default_Size-1;i>=0;i--){
		if(sbt[i]!=NIL){
			return (int)(log(i+1)/log(2)+1.01); 
		}
	}
	return 0;
}

int EmptyTree(SeqBinaryTree sbt){
	if(sbt[0]==NIL){
		return 1;
	}
	return 0;
}

void PrintTree(SeqBinaryTree sbt){
	int d;
	int i,j;
	d = Depth(sbt);
	for(i = 1; i<=d; i++){
		for(j = 1;j<=pow(2,i-1);j++){
			if(sbt[(int)pow(2,i-1)-1+j-1] == NIL){
				cout<<"null  ";
			}else{
				cout<<sbt[(int)pow(2,i-1)-1+j-1]<<"  "; 
			} 
		}
		cout<<endl;
	}
}

void CreateTree(SeqBinaryTree sbt){
	InitTree(sbt);
	int data;
	int i;
	i = 0;
	while(data!=9999){
		cin>>data;
		if(i == 0 && data!=9999){
			sbt[i] = data;
		}else if(data != 9999 && sbt[(i+1)/2-1]!=999){
			sbt[i] = data;
		}
		i++;
	}
}

int Root(SeqBinaryTree sbt){
	return sbt[0];
}

int Value(SeqBinaryTree sbt,int pos){
	int d;
	d = Depth(sbt);
	if(pos<1 || pos>((int)pow(2,d)-1-1) || sbt[(int)(pos/2)-1]==NIL){
		cout<<"当前查找位置有误；";
		return 999; 
	}
	return sbt[pos-1];
}

int Assign(SeqBinaryTree sbt,int pos,int data){
	int d;
	d = Depth(sbt);
	if(pos<1 || (sbt[(int)(pos/2)-1]==NIL && pos!=1) 
		|| (int)(log(pos)/log(2))+1.01 >= d+2 ||sbt[pos-1]!=NIL){
		cout<<"赋值位置有误"; 
		return 0;
	}
	sbt[pos-1] = data;
	return 1;
} 

//int InsertChild(SeqBinaryTree sbt1,int pos,SeqBinaryTree sbt2){
//	int d;
//	d = Depth(sbt1);
//	int i;
//	for(i = Defualt_Size-1;i>=0;i--){
//		if(sbt1[i]!=NIL){
//			break;
//		}
//	} 
//	if(pos-1>i ||(sbt[1]!=NIL && sbt[2]!=NIL)){
//		return 0;
//	}
//	if(sbt2[2]==NIL){		//要插入的树没有右子树插入，其s1中为左子树 (若没有左右子树也默认为该种情况)
//		int j,k,m,n;
//		m = 3;
//		j = pos*2;
//		k = j*2+1;
//		while(sbt[j-1]==NIL && sbt[j]==NIL){
//			if(j == pos*2){
//				sbt2[m-1] = sbt1[j];
//			}else{
//				sbt2[m-1] = sbt1[j-1];
//				sbt2[n-1] = sbt1[k-1];
//			}
//			n = m*2+1;
//			m = m*2;
//			k = j*2+1;
//			j = j*2;
//		}
//		d = Deth(sbt2);
//		i = 1;
//		j = pos*2;
//		k = j*2+1;
//		while(d>=1){
//			if(d==1){
//				
//			}
//			k = k*2+1;
//			j = j*2;
//			d--;
//		}
//	}
//	if(sbt2[1]==NIL){
//		int x,y,z,w;
//		
//	}
//	
//}

int Parent(SeqBinaryTree sbt,int pos){
	if(sbt[(int)(pos/2)-1]==NIL && pos != 1){
		return NIL;
	}
	return sbt[(int)(pos/2)-1];
}

int LeftChild(SeqBinaryTree sbt,int pos){
	if(sbt[pos*2-1]!=NIL && sbt[pos-1]!=NIL){
		return sbt[pos*2-1];
	}
	return NIL;
}

int RightChild(SeqBinaryTree sbt,int pos){
	if(sbt[pos*2+1-1]!=NIL && sbt[pos-1]!=NIL){
		return sbt[pos*2+1-1];
	}
	return NIL;
}

int LeftSibling(SeqBinaryTree sbt,int pos){
	if(pos%2!=0 && sbt[(int)pos/2-1]!=NIL && pos!=1){
		return sbt[pos-1-1];
	}
	return NIL;
}

int RightSibling(SeqBinaryTree sbt,int pos){
	if(pos%2==0 && sbt[(int)pos/2-1!=NIL]){
		return sbt[pos-1+1];
	}
	return NIL;
}

void PreOrderTranverse(SeqBinaryTree sbt,int pos){
	if(sbt[pos-1] == NIL){
		return;
	}
	cout<<sbt[pos-1]<<"  ";
	PreOrderTranverse(sbt,pos*2);
	PreOrderTranverse(sbt,pos*2+1);
}

void InOrderTranverse(SeqBinaryTree sbt,int pos){
	if(sbt[pos-1] == NIL){
		return;
	}
	InOrderTranverse(sbt,pos*2);
	cout<<sbt[pos-1]<<"  ";
	InOrderTranverse(sbt,pos*2+1);
}

void PostOrderTranverse(SeqBinaryTree sbt,int pos){
	if(sbt[pos-1] == NIL){
		return;
	}
	PostOrderTranverse(sbt,pos*2);
	PostOrderTranverse(sbt,pos*2+1);
	cout<<sbt[pos-1]<<"  ";
}

void ClearTree(SeqBinaryTree sbt){
	int d;
	int i;
	d = Depth(sbt);
	for(i = 0; i<=(int)pow(2,d)-1-1;i++){
		sbt[i] = NIL;
	}
}

void DestroyTree(SeqBinaryTree sbt){
	free(sbt);
}
