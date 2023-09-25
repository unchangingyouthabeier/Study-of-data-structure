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
int InitList(sqlist &L);							//初始化 
void CreateList(sqlist &L, int n);					//创建一个线性表 
int ListLength(sqlist L);							//获取线性表的长度 
void GetElem(sqlist L,int &m,int &e);				//获取线性表中的指定元素  
int LocateElem(sqlist L);							//查找指定元素的位序（按索引） 
void PriorElem(sqlist L, int &pre_e);       		//查找元素是否重复出现，并返回重复出现的该元素的前驱（可能返回重复的其中一次的前驱）		
void NextElem(sqlist L);							//查找元素是否重复出现，并返回重复的元素且非最后一个重复元素的后继 
string ListInsert(sqlist &L);						//插入元素 
int ListDelete(sqlist &L);							//删除元素 
void ListTraverse(sqlist L);						//遍历线性表 
void UnionList(sqlist L1, sqlist &L2);				//合并两个线性表并去除重复项 
void MergeList(sqlist L1, sqlist L2, sqlist &L3);	//将L1与L2合在L3中并实现升序排列(不去重) 
string ListEmpty(sqlist L);							//判断线性表是否有元素
void ClearList(sqlist &L);							//将线性表重置 
void DestroyList(sqlist &L);						//销毁线性表 
 
int main(int argc, char** argv) {
	int i;
	string a;
	sqlist L1;
	i = InitList(L1);										//L1初始化 
	CreateList(L1,4);										//创建长度为4的线性表 
	ListTraverse(L1);
	int b = ListLength(L1);									//获取线性表的长度 
	cout<<"L1的长度："<<b<<endl; 
	int e,m;
	cout<<"请输入想要获取线性表的第几个元素：" ;
	cin>>m;
	cout<<endl;
	GetElem(L1,m,e); 										//获取指定的线性表的第几个元素 
	cout<<"获取的线性表的第"<<m<<"个元素为："<<e<<endl; 
	int d = LocateElem(L1);									//获取查找元素在线性表中的位序 
	if(d == -1){
		cout<<"";
	}else{
		cout<<"所找元素在线性表中的位序为："<<d<<endl;
	}
	int pre_e;
	PriorElem(L1,pre_e);									//获取重复元素（非第一个）的前驱 
	NextElem(L1);											//获取重复元素（非最后一个）的后继 
	ListInsert(L1);											//向线性表L1中插入元素 
	ListTraverse(L1);										//遍历线性表L1
	ListDelete(L1);											//对L1指定位置元素进行删除 
	ListTraverse(L1);										//遍历经过删除的L1 
	a = ListEmpty(L1);										//判断线性表L1中是否存有元素 
	cout<<"L1为空："<<a<<endl;								
	ClearList(L1);											//清空L1中所存的元素并重置（为初始化） 
	cout<<"L1未重置："<<L1. length<<endl;						
	DestroyList(L1);										//销毁线性表L1（将电脑分配给我们的空间释放） 
	cout<<"分配空间成功："<<i<<endl;
	sqlist L2, L3, L4, L5, L6;								//定义线性表L2, L3, L4
	InitList(L2);											//初始化L2 
	InitList(L3);											//初始化L3 
	CreateList(L2, 4); 										//创建L2 
	CreateList(L3, 7);										//创建L3 
	ListTraverse(L2);										//遍历L2 
	ListTraverse(L3);										//遍历L3 
	UnionList(L2, L3); 										//合并线性表L2,L3(并将L2,L3共有元素删除)存于L3 
	ListTraverse(L3);										//遍历L3
	cout<<"以下请输入非递减有序数据！"<<endl; 
	InitList(L4);											//初始化L4
	CreateList(L4,4);										//创建线性表L4 
	InitList(L5);											//初始化L5
	CreateList(L5,7);										//创建线性表L5 
	ListTraverse(L4);										//遍历L4 
	ListTraverse(L5);										//遍历L5 
	InitList(L6);											//初始化L6
	MergeList(L4, L5, L6); 									//将L4,L5中的元素合在L6中并实现升序排列（不去重） 
	ListTraverse(L6);										//遍历L6 
	DestroyList(L4);										//销毁L4 
	DestroyList(L5);										//销毁L5	 
	DestroyList(L6); 										//销毁L6 
	DestroyList(L2);										//销毁L2 
	DestroyList(L3);										//销毁L3 
											
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
		cout<<"请输入存入线性表的"<<"第"<<i+1<<"个数据："; 
		cin>>L.elem[i];
		cout<<endl;
	}
	L.length = n;
}

int LocateElem(sqlist L){
	int i;
	cout<<"请输入需要查找到的元素：";
	cin>>i;
	cout<<endl;
	int j;
	for(j = 0; j < L.length; j++){
		if(i == L.elem[j]){
			return j;
		}
	}
	cout<<"所查找的元素在此线性表中不存在"<<endl; 
	return -1;
} 

void PriorElem(sqlist L, int &pre_e){
	int i, j;
	int cur_e;
	cout<<"请输入查找重复的元素：";
	cin>>cur_e;
	cout<<endl; 
	for(i = 0; i < L.length; i++){
		if(cur_e==L.elem[i]){
			for(j = L.length-1; j >= 0; j--){
				if(cur_e == L.elem[j] && j != i){
					pre_e = L.elem[j-1];
					cout<<"所查找元素有重复且前驱为："<<pre_e<<endl;
					break;
				}else if(cur_e == L.elem[j] && j==i ){
					cout<<"所查找的元素无重复"<<endl;
					break; 
				}
			}
			break;
		}else if(i == L.length - 1){
			cout<<"该元素不存在"<<endl; 
			break;
		}
	}
	
}



void NextElem(sqlist L){
	int cur_e;
	int i, j;
	cout<<"请输入需要查找重复的元素其后继的元素："; 
	cin>>cur_e;
	cout<<endl;
	for(j = L.length; j >= 0; j--){
		if(cur_e == L.elem[j]){
			for(i = 0; i < L.length; i++){
				if(cur_e == L.elem[i] && i!= j){
					cout<<"该重复元素（且非最后一个）的后继为："<<L.elem[i + 1]<<endl;
					break; 
				}else if(cur_e == L.elem[i] && i==j){
					cout<<"所查找的元素无重复"<<endl;
					break;
				}
			}
			break;
		}else if(j == 0){
			cout<<"该元素不存在"<<endl;
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
			cout<<"插入位置有误，请重新确定插入位置：";
			cin>>i;
			cout<<endl; 
		}else{
			break;
		}
	}
	if((NeedQuantity + L.length) > L.listsize){
		L.elem = (int*)realloc(L.elem,(L.length+NeedQuantity)*sizeof(int));
		if(L.elem == NULL){
			return "插入失败（内存分配失败）"; 
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
			cout<<"请输入插入的第"<<q<<"个元素：";
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
				cout<<"请输入插入的第"<<k<<"个元素:"; 
				cin>>m;
				L.elem[i-1+k-1] =m;
				cout<<endl;
				k++;
			}			
		}
	}
	L.length = L.length + NeedQuantity;
	return "插入成功" ;
}

int ListDelete(sqlist &L){
	int a;
	int i;
	cout<<"请输入想要删除哪个位置上的元素：";
	cin>>a;
	cout<<endl;
	if(L.elem == NULL || L.length == 0 ){
		return -1;
	}
	while(1){
		if(a<1 || a > L.length){
			cout<<"所输入的删除位置无效，请重新输入：";
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
				cout<<"内存的重新分配未成功，请停止程序"<<endl; 
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
		cout<<"所给线性表参数有空线性表或存放所用线性表不为空请重新调用！"<<endl; 
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
	cout<<"线性表的遍历：";
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
			cout<<"想要获取的线性表的索引超出范围请重新输入：";
			cin>>m;
			cout<<endl;
		}else{
			e = L.elem[m-1];
			break;
		}
	}
}


