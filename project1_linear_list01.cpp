#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#define DefaultValue 100
using namespace std; 
typedef struct sqlist{
	int * elem;
	int length;
	int listsize;
}sqlist;
int InitList(sqlist &L);							//��ʼ�� 
void CreateList(sqlist &L, int n);					//����һ�����Ա� 
int ListLength(sqlist L);							//��ȡ���Ա�ĳ��� 
void GetElem(sqlist L,int &m,int &e);				//��ȡ���Ա��е�ָ��Ԫ��  
int LocateElem(sqlist L);							//����ָ��Ԫ�ص�λ�򣨰������� 
void PriorElem(sqlist L, int &pre_e);       		//����Ԫ���Ƿ��ظ����֣��������ظ����ֵĸ�Ԫ�ص�ǰ�������ܷ����ظ�������һ�ε�ǰ����		
void NextElem(sqlist L);							//����Ԫ���Ƿ��ظ����֣��������ظ���Ԫ���ҷ����һ���ظ�Ԫ�صĺ�� 
string ListInsert(sqlist &L);						//����Ԫ�� 
int ListDelete(sqlist &L);							//ɾ��Ԫ�� 
void ListTraverse(sqlist L);						//�������Ա� 
void UnionList(sqlist L1, sqlist &L2);				//�ϲ��������Ա�ȥ���ظ��� 
void MergeList(sqlist L1, sqlist L2, sqlist &L3);	//��L1��L2����L3�в�ʵ����������(��ȥ��) 
string ListEmpty(sqlist L);							//�ж����Ա��Ƿ���Ԫ��
void ClearList(sqlist &L);							//�����Ա����� 
void DestroyList(sqlist &L);						//�������Ա� 
 
int main(int argc, char** argv) {
	int i;
	string a;
	sqlist L1;
	i = InitList(L1);										//L1��ʼ�� 
	CreateList(L1,4);										//��������Ϊ4�����Ա� 
	ListTraverse(L1);
	int b = ListLength(L1);									//��ȡ���Ա�ĳ��� 
	cout<<"L1�ĳ��ȣ�"<<b<<endl; 
	int e,m;
	cout<<"��������Ҫ��ȡ���Ա�ĵڼ���Ԫ�أ�" ;
	cin>>m;
	cout<<endl;
	GetElem(L1,m,e); 										//��ȡָ�������Ա�ĵڼ���Ԫ�� 
	cout<<"��ȡ�����Ա�ĵ�"<<m<<"��Ԫ��Ϊ��"<<e<<endl; 
	int d = LocateElem(L1);									//��ȡ����Ԫ�������Ա��е�λ�� 
	if(d == -1){
		cout<<"";
	}else{
		cout<<"����Ԫ�������Ա��е�λ��Ϊ��"<<d<<endl;
	}
	int pre_e;
	PriorElem(L1,pre_e);									//��ȡ�ظ�Ԫ�أ��ǵ�һ������ǰ�� 
	NextElem(L1);											//��ȡ�ظ�Ԫ�أ������һ�����ĺ�� 
	ListInsert(L1);											//�����Ա�L1�в���Ԫ�� 
	ListTraverse(L1);										//�������Ա�L1
	ListDelete(L1);											//��L1ָ��λ��Ԫ�ؽ���ɾ�� 
	ListTraverse(L1);										//��������ɾ����L1 
	a = ListEmpty(L1);										//�ж����Ա�L1���Ƿ����Ԫ�� 
	cout<<"L1Ϊ�գ�"<<a<<endl;								
	ClearList(L1);											//���L1�������Ԫ�ز����ã�Ϊ��ʼ���� 
	cout<<"L1δ���ã�"<<L1. length<<endl;						
	DestroyList(L1);										//�������Ա�L1�������Է�������ǵĿռ��ͷţ� 
	cout<<"����ռ�ɹ���"<<i<<endl;
	sqlist L2, L3, L4, L5, L6;								//�������Ա�L2, L3, L4
	InitList(L2);											//��ʼ��L2 
	InitList(L3);											//��ʼ��L3 
	CreateList(L2, 4); 										//����L2 
	CreateList(L3, 7);										//����L3 
	ListTraverse(L2);										//����L2 
	ListTraverse(L3);										//����L3 
	UnionList(L2, L3); 										//�ϲ����Ա�L2,L3(����L2,L3����Ԫ��ɾ��)����L3 
	ListTraverse(L3);										//����L3
	cout<<"����������ǵݼ��������ݣ�"<<endl; 
	InitList(L4);											//��ʼ��L4
	CreateList(L4,4);										//�������Ա�L4 
	InitList(L5);											//��ʼ��L5
	CreateList(L5,7);										//�������Ա�L5 
	ListTraverse(L4);										//����L4 
	ListTraverse(L5);										//����L5 
	InitList(L6);											//��ʼ��L6
	MergeList(L4, L5, L6); 									//��L4,L5�е�Ԫ�غ���L6�в�ʵ���������У���ȥ�أ� 
	ListTraverse(L6);										//����L6 
	DestroyList(L4);										//����L4 
	DestroyList(L5);										//����L5	 
	DestroyList(L6); 										//����L6 
	DestroyList(L2);										//����L2 
	DestroyList(L3);										//����L3 
											
	return 0;
}

int InitList(sqlist &L){
	L.elem = (int*)malloc(DefaultValue*sizeof(int));
	if (L.elem == NULL){
		return 0;
	}
	L.length = 0;
	L.listsize = DefaultValue;
	return 1;
}

void CreateList(sqlist &L, int n){
	int i;
	for(i = 0; i < n; i++){
		cout<<"������������Ա��"<<"��"<<i+1<<"�����ݣ�"; 
		cin>>L.elem[i];
		cout<<endl;
	}
	L.length = n;
}

int LocateElem(sqlist L){
	int i;
	cout<<"��������Ҫ���ҵ���Ԫ�أ�";
	cin>>i;
	cout<<endl;
	int j;
	for(j = 0; j < L.length; j++){
		if(i == L.elem[j]){
			return j;
		}
	}
	cout<<"�����ҵ�Ԫ���ڴ����Ա��в�����"<<endl; 
	return -1;
} 

void PriorElem(sqlist L, int &pre_e){
	int i, j;
	int cur_e;
	cout<<"����������ظ���Ԫ�أ�";
	cin>>cur_e;
	cout<<endl; 
	for(i = 0; i < L.length; i++){
		if(cur_e==L.elem[i]){
			for(j = L.length-1; j >= 0; j--){
				if(cur_e == L.elem[j] && j != i){
					pre_e = L.elem[j-1];
					cout<<"������Ԫ�����ظ���ǰ��Ϊ��"<<pre_e<<endl;
					break;
				}else if(cur_e == L.elem[j] && j==i ){
					cout<<"�����ҵ�Ԫ�����ظ�"<<endl;
					break; 
				}
			}
			break;
		}else if(i == L.length - 1){
			cout<<"��Ԫ�ز�����"<<endl; 
			break;
		}
	}
	
}



void NextElem(sqlist L){
	int cur_e;
	int i, j;
	cout<<"��������Ҫ�����ظ���Ԫ�����̵�Ԫ�أ�"; 
	cin>>cur_e;
	cout<<endl;
	for(j = L.length; j >= 0; j--){
		if(cur_e == L.elem[j]){
			for(i = 0; i < L.length; i++){
				if(cur_e == L.elem[i] && i!= j){
					cout<<"���ظ�Ԫ�أ��ҷ����һ�����ĺ��Ϊ��"<<L.elem[i + 1]<<endl;
					break; 
				}else if(cur_e == L.elem[i] && i==j){
					cout<<"�����ҵ�Ԫ�����ظ�"<<endl;
					break;
				}
			}
			break;
		}else if(j == 0){
			cout<<"��Ԫ�ز�����"<<endl;
			break; 
		}
	}
	
} 

string ListInsert(sqlist &L){
	int NeedQuantity;
	int i;
	cout<<"Please input the insert position:";
	cin>>i;
	cout<<endl;
	cout<<"Please input the quantity to be inserted:";
	cin>>NeedQuantity;
	cout<<endl;
	while(1){
		if(i>L.length + 1 || i < 1){
			cout<<"����λ������������ȷ������λ�ã�";
			cin>>i;
			cout<<endl; 
		}else{
			break;
		}
	}
	if((NeedQuantity + L.length) > L.listsize){
		L.elem = (int*)realloc(L.elem,(L.length+NeedQuantity)*sizeof(int));
		if(L.elem == NULL){
			return "����ʧ�ܣ��ڴ����ʧ�ܣ�"; 
		}
		L.length+=NeedQuantity;
		L.listsize = L.length;
	}
	int j;
	int k = 1;
	int m;
	if(i == L.length+1){
		int q = 1;
		while(q == NeedQuantity){
			cout<<"���������ĵ�"<<q<<"��Ԫ�أ�";
			cin>>m;
			L.elem[L.length] = m;
			cout<<endl; 
			q++;
		}
	}
	for(j = L.length-1; j >= i-1; j--){
		L.elem[j + NeedQuantity] = L.elem[j]; 
		if( j == (i-1)){
			int num;
			for(num = 1 ; num <= NeedQuantity; num++){
				cout<<"���������ĵ�"<<k<<"��Ԫ��:"; 
				cin>>m;
				L.elem[i-1+k-1] =m;
				cout<<endl;
				k++;
			}			
		}
	}
	L.length = L.length + NeedQuantity;
	return "����ɹ�" ;
}

int ListDelete(sqlist &L){
	int a;
	int i;
	cout<<"��������Ҫɾ���ĸ�λ���ϵ�Ԫ�أ�";
	cin>>a;
	cout<<endl;
	if(L.elem == NULL || L.length == 0 ){
		return -1;
	}
	while(1){
		if(a<1 || a > L.length){
			cout<<"�������ɾ��λ����Ч�����������룺";
			cin>>a;
			cout<<endl;
		}else{
			break;
		}
	}
	for(i = a ; i < L.length; i++ ){
		L.elem[i-1] = L.elem[i];
	}
	L.length-=1;
	return 1;
} 

void UnionList(sqlist L1, sqlist &L2){
	int i;
	while(1){
		if((L1.length + L2.length) > L2.listsize){
			L2.elem = (int *)realloc(L2.elem,(L1.length + L2.length)*sizeof(int));
			if(L2.elem == NULL){
				cout<<"�ڴ�����·���δ�ɹ�����ֹͣ����"<<endl; 
			}else{
				L2.listsize = L1.length + L2.length;
				L2.length = L1.length + L2.length;
				break;
			}
		}else{
			break;
		}
	}
	int k;
	int l = L2.length;
	for(i = 0; i < L1.length; i++){
		k = 0;
		while(k<l){
			if(L1.elem[i] != L2.elem[k] && k == (l-1)){
				L2.elem[L2.length] = L1.elem[i];
				L2.length+=1;
			}else if(L1.elem[i] == L2.elem[k]){
				break;
			}
			k++;
		}
	}
}

void MergeList(sqlist L1, sqlist L2, sqlist &L3){
	if(L1.length == 0 || L2.length == 0 || L3.length != 0){
		cout<<"�������Ա�����п����Ա�����������Ա�Ϊ�������µ��ã�"<<endl; 
	}else{
		L3.length = L1.length + L2.length;
		int i = 0;
		int j = L2.length - 1;
		while(i < L1.length){
			L3.elem[i] = L1.elem[i];
			i++;
		} 
		int p,m;
		while(j >= 0){
			if(L2.elem[j] >= L3.elem[L1.length - 1] && L2.elem[j-1] < L3.elem[L1.length-1]){
				p = L2.length - j;
				m=p;
				i = 0;
				while(p>=1){
					L3.elem[L3.length-1-i] = L2.elem[L2.length-1-i];
					p--;
					i++;
				} 
			}	
			j--;
		}
		int k;
		int q;
		int count = 0;
		for(k = 0;k<=L2.length-1-m;k++){
			for(q = 0; q <= L1.length-1+count;q++){
				if(L2.elem[k] <= L3.elem[q]){
					if(q==0){
						for(i=L1.length-1;i>=0;i--){
							L3.elem[i+1] = L3.elem[i];
						}
						L3.elem[q] = L2.elem[q];
						count++;
						break;
					}else{
						for(i=L1.length-1+count;i>=q;i--){
							L3.elem[i+1]=L3.elem[i];
						}
						L3.elem[q] = L2.elem[k];
						count++;
						break;
					}
				}
			}
		}				
	}
}

void ListTraverse(sqlist L){
	int i; 
	cout<<"���Ա�ı�����";
	for(i = 0; i < L.length; i++){
		cout<<L.elem[i]<<"  "; 
	}
	cout<<endl;
}

void DestroyList(sqlist &L){
	free(L.elem);
	L.length = 0;
	L.listsize = 0;
}

string ListEmpty(sqlist L){
	if(L.length == 0){
		return "TRUE";
	}else{
		return "FALSE";
	} 
}

int ListLength(sqlist L){
	return L.length;
} 
void ClearList(sqlist &L){
	L.length = 0;
}

void GetElem(sqlist L, int &m, int &e){
	while(1){
		if(m < 0 || m > L.length){
			cout<<"��Ҫ��ȡ�����Ա������������Χ���������룺";
			cin>>m;
			cout<<endl;
		}else{
			e = L.elem[m-1];
			break;
		}
	}
}


