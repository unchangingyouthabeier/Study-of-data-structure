#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef struct HuffmanNode{
	unsigned int weight;
	unsigned int parent,lchild,rchild;		
}HuffmanNode,*HuffmanTree;


void CreateHuffmanTree(HuffmanTree &HT,int *w,int n);
int Get_MinWIndex(HuffmanTree HT,int n);
char* HuffmanTreeCoding(HuffmanTree HT,int n,int m);

int main(int argc, char** argv) {
	int w[8] = {5,29,7,8,14,23,3,11};
	HuffmanTree HT1;
	CreateHuffmanTree(HT1,w,8);
	int i;
	for(i = 1;i <= 15;i++){
		cout<<HT1[i].weight<<"\t"<<HT1[i].parent<<"\t"<<HT1[i].lchild<<"\t"<<HT1[i].rchild<<endl;
	}
	cout<<endl;
	cout<<HuffmanTreeCoding(HT1,1,8)<<endl;
	cout<<HuffmanTreeCoding(HT1,2,8)<<endl;
	cout<<HuffmanTreeCoding(HT1,3,8)<<endl;
	cout<<HuffmanTreeCoding(HT1,4,8)<<endl;
	cout<<HuffmanTreeCoding(HT1,5,8)<<endl;
	cout<<HuffmanTreeCoding(HT1,6,8)<<endl;
	cout<<HuffmanTreeCoding(HT1,7,8)<<endl;
	cout<<HuffmanTreeCoding(HT1,8,8)<<endl;
	return 0;
}

int Get_MinWIndex(HuffmanTree HT,int n){
	int i;
	int m;
	m  = 2*n-1;
	int temp = 999;
	for(i = 1;i <= m;i++){
		if(HT[i].parent == 20){
			continue;
		}
		if(HT[i].weight < temp){
			temp = HT[i].weight;
		}
	}
	for(i = 1; i <= m;i++){
		if(HT[i].parent == 20){
			continue;
		}
		if(HT[i].weight == temp){
			break;
		}
	}
	HT[i].parent = 20;
	return i;
}

void CreateHuffmanTree(HuffmanTree &HT,int *w,int n){
	if(n<1){
		return;
	}
	int m = 0;
	m = 2*n-1;
	HT = (HuffmanTree)malloc((m+1)*sizeof(HuffmanNode));
	int i;
	for(i = 0;i < n;i++){
		HT[i+1].weight = w[i];
		HT[i+1].parent = 0;
		HT[i+1].lchild = 0;
		HT[i+1].rchild = 0;
	}
	for(i = n;i < m;i++){
		HT[i+1].weight = 999;
		HT[i+1].parent = 0;
		HT[i+1].lchild = 0;
		HT[i+1].rchild = 0;
	}
	for(i = n;i < m;i++){
		HT[i+1].lchild = Get_MinWIndex(HT,n);
		HT[i+1].rchild = Get_MinWIndex(HT,n);
		HT[i+1].weight = HT[HT[i+1].lchild].weight + HT[HT[i+1].rchild].weight;
		if(i == m-1){
			HT[i+1].parent = 0;
		}
	}
	for(i = n+1; i <= m;i++){
		HT[HT[i].lchild].parent = i;
		HT[HT[i].rchild].parent = i;
	}
}


char* HuffmanTreeCoding(HuffmanTree HT, int n, int m) {
    char* ch = (char*)malloc(m * sizeof(char));
    int i = 0;
    while (HT[n].parent != 0) {
        ch[i++] = (HT[HT[n].parent].lchild == n) ? '0' : '1';  
        n = HT[n].parent;
    }
    char* ch1 = (char*)malloc(i * sizeof(char));  
    for (int j = i - 1; j >= 0; j--) {
        ch1[i - 1 - j] = ch[j];  				
    }
//    ch1[i] = '\0';  // 添加字符串结束符
    free(ch);       // 释放动态分配的内存
    return ch1;
}



