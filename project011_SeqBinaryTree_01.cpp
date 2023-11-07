#include <iostream>
#include <math.h>
#include <stdlib.h>
#define Default_Size 100
#define NIL 999


using namespace std;
typedef int SeqBinaryTree[Default_Size];				//�����洢�������ݽṹ ����˳��ṹ�洢�� 
void InitTree(SeqBinaryTree sbt);						//��ʼ�������洢�����ݸ�ΪĬ��Ϊ�յ����� 
int Depth(SeqBinaryTree sbt);							//��ȡ������� 
int EmptyTree(SeqBinaryTree sbt);						//�ж��Ƿ�Ϊ���� 
void PrintTree(SeqBinaryTree sbt);						//�ò�������ķ�ʽ������ 
void CreateTree(SeqBinaryTree sbt);						//����һ�������Ӽ���¼�����ݣ� 
int Root(SeqBinaryTree sbt);							//��ȡ���ڵ����� 
int Value(SeqBinaryTree sbt,int pos);					//��ȡָ���ڵ����ֵ 
int Assign(SeqBinaryTree sbt,int pos,int data);			//������Ϊ�յ�ָ���ڵ㸳ֵ 
//int InsertChild(SeqBinaryTree sbt1,int pos,SeqBinaryTree sbt2);
int Parent(SeqBinaryTree sbt,int pos);					//��ȡָ���ڵ��˫�׽ڵ� 
int LeftChild(SeqBinaryTree sbt,int pos);				//��ȡָ���ڵ�����ӽڵ� 
int RightChild(SeqBinaryTree sbt,int pos);				//��ȡָ���ڵ���Һ��ӽڵ� 
int LeftSibling(SeqBinaryTree sbt,int pos);				//��ȡָ���ҽڵ�����ֵܽڵ� 
int RightSibling(SeqBinaryTree sbt,int pos);			//��ȡָ����ڵ�����ֵܽڵ� 
void PreOrderTranverse(SeqBinaryTree sbt,int pos);		//����ǰ����� �������ң� 
void InOrderTranverse(SeqBinaryTree sbt,int pos);		//����������� �������ң� 
void PostOrderTranverse(SeqBinaryTree sbt,int pos);		//���к�������������У� 
void ClearTree(SeqBinaryTree sbt);						//����� 
void DestroyTree(SeqBinaryTree sbt);					//������ 

int main(int argc, char** argv) {
	SeqBinaryTree sbt1;
	InitTree(sbt1);
	cout<<"��ʼ����Ϊ������"<<EmptyTree(sbt1)<<endl;
	cout<<"��ǰ���Ϊ��"<<Depth(sbt1)<<endl;
	CreateTree(sbt1);
	cout<<"����������б�����"<<endl;
	PrintTree(sbt1);
	cout<<"��ǰ���ĸ��ڵ�Ϊ��"<<Root(sbt1)<<endl;
	cout<<"�������еĵ�1���ڵ�ֵΪ��"<<Value(sbt1,1)<<endl;
	Assign(sbt1,5,11);
	cout<<"����ڵ㸳ֵ�������"<<endl;
	PrintTree(sbt1);
//	cout<<"�봴���ڶ�������"<<endl; 
//	CreateSeqBinary(sbt2);
//	InsertChild(sbt1,2,sbt2);
	cout<<"�������ڵ��˫�׽ڵ�ֵ��"<<Parent(sbt1,3)<<endl;
	cout<<"��2���ڵ�����ӵ�ֵ��"<<LeftChild(sbt1,2)<<endl;
	cout<<"��2���ڵ���Һ��ӵ�ֵ��"<<RightChild(sbt1,2)<<endl;
	cout<<"��һ���ڵ�����ֵܽڵ㣺"<<LeftSibling(sbt1,1)<<endl;
	cout<<"��һ���ڵ�����ֵܽڵ㣺"<<RightSibling(sbt1,1)<<endl;
	cout<<"ǰ�������" ; 
	PreOrderTranverse(sbt1,1);
	cout<<endl;
	cout<<"���������";
	InOrderTranverse(sbt1,1);
	cout<<endl;
	cout<<"���������";
	PostOrderTranverse(sbt1,1);
	cout<<endl;
//	InsertChild(sbt1,stb2,);
	ClearTree(sbt1);
	cout<<"����������պ������";
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
		cout<<"��ǰ����λ������";
		return 999; 
	}
	return sbt[pos-1];
}

int Assign(SeqBinaryTree sbt,int pos,int data){
	int d;
	d = Depth(sbt);
	if(pos<1 || (sbt[(int)(pos/2)-1]==NIL && pos!=1) 
		|| (int)(log(pos)/log(2))+1.01 >= d+2 ||sbt[pos-1]!=NIL){
		cout<<"��ֵλ������"; 
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
//	if(sbt2[2]==NIL){		//Ҫ�������û�����������룬��s1��Ϊ������ (��û����������ҲĬ��Ϊ�������)
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
