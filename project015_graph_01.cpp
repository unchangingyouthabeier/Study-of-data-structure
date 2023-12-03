#include <iostream>
#include <string.h>
#define ValType int 
#define VerType char*
#define MAX_VER_NUM	20
#define Info int

using namespace std;
typedef enum {DG,UG,DN,UN} Graph; //有向图、无向图、有向网、无线网 

typedef	struct AdjType{
	ValType ArcVal;
	Info* ArcInfo;
}AdjType,AdjMatrix[MAX_VER_NUM][MAX_VER_NUM]; 

typedef struct MGraph{
	Graph kind;
	int vernum;
	int arcnum;
	VerType vers[MAX_VER_NUM];
	AdjMatrix arcs;
}MGraph;

void DisPlay(MGraph mg);
int FirstAdjVer(MGraph mg,int v);
int	NextAdjVer(MGraph mg,int v,int w);
void DFSTranverse(MGraph mg);
void BFSTranverse(MGraph mg);
int Visit1[MAX_VER_NUM];
int main(int argc, char** argv) {
	MGraph mg1;
	mg1.kind = UG;
	mg1.vernum = 8;
	mg1.arcnum = 9;
	mg1.vers[0]=(char*)"v1";	mg1.vers[1]=(char*)"v2";
	mg1.vers[2]=(char*)"v3";	mg1.vers[3]=(char*)"v4";
	mg1.vers[4]=(char*)"v5";	mg1.vers[5]=(char*)"v6";
	mg1.vers[6]=(char*)"v7";	mg1.vers[7]=(char*)"v8";
	int i,j;
	for(i = 0; i < mg1.vernum; i++){
		for(j = 0; j < mg1.vernum; j++){
			mg1.arcs[i][j].ArcVal = 0;
		}
	}
	mg1.arcs[0][1].ArcVal = 1; mg1.arcs[1][0].ArcVal = 1;
	mg1.arcs[0][2].ArcVal = 1; mg1.arcs[2][0].ArcVal = 1;
	mg1.arcs[1][3].ArcVal = 1; mg1.arcs[3][1].ArcVal = 1; 
	mg1.arcs[1][4].ArcVal = 1; mg1.arcs[4][1].ArcVal = 1; 
	mg1.arcs[2][5].ArcVal = 1; mg1.arcs[5][2].ArcVal = 1; 
	mg1.arcs[2][6].ArcVal = 1; mg1.arcs[6][2].ArcVal = 1; 
	mg1.arcs[3][7].ArcVal = 1; mg1.arcs[7][3].ArcVal = 1; 
	mg1.arcs[4][7].ArcVal = 1; mg1.arcs[7][4].ArcVal = 1; 
	mg1.arcs[5][6].ArcVal = 1; mg1.arcs[6][5].ArcVal = 1; 
	DisPlay(mg1);
	int ver = 0;
	ver = FirstAdjVer(mg1,1);
	cout<<"v2的第一个相邻顶点索引："<<ver<<endl; 
	if(ver!=-1){
		ver = NextAdjVer(mg1,1,ver);
		cout<<"v2的第二个相邻顶点索引："<<ver<<endl; 
	}
	cout<<"深度优先遍历：";
	DFSTranverse(mg1);	//深度优先遍历 
	cout<<endl;
	cout<<"广度优先遍历：";
	BFSTranverse(mg1);	//广度优先遍历
	return 0;
}

void DisPlay(MGraph mg){
	cout<<"邻接矩阵："<<endl; 
	int i,j;
	for(i = 0; i < mg.vernum; i++){
		for(j = 0; j < mg.vernum; j++){
			cout<<mg.arcs[i][j].ArcVal<<"   ";
		}
		cout<<endl;
	}
}

int FirstAdjVer(MGraph mg,int v){
	int j;
	for(j = 0;j < mg.vernum;j++){
		if(mg.arcs[v][j].ArcVal != 0){
			return j;
		}
	}
	return -1;
}

int	NextAdjVer(MGraph mg,int v,int w){
	int j;
	for(j = w+1;j<mg.vernum;j++){
		if(mg.arcs[v][j].ArcVal != 0){
			return j;
		}
	}
	return -1; 
}

void DFS(MGraph mg,int i){
	cout<<mg.vers[i]<<"  ";
	Visit1[i] = 1;
	int j;
	for(j = 0; j<mg.vernum; j++){
		if(Visit1[j] == 0 && mg.arcs[i][j].ArcVal == 1){
			DFS(mg,j);
		}
	}
}

void DFSTranverse(MGraph mg){
	int i;
	for(i = 0; i < mg.vernum; i++){
		Visit1[i] = 0;
	}
	for(i = 0; i < mg.vernum; i++){
		if(Visit1[i] == 0 ){
			DFS(mg,i);
		}
	}
}

void BFSTranverse(MGraph mg){
	int i;
	for(i = 0;i < mg.vernum; i++){
		Visit1[i] = 0;
	}
	Visit1[0] = 1;
	cout<<mg.vers[0]<<"  ";
	for(i = 0; i < mg.vernum; i++){
		for(int j = 0; j < mg.vernum; j++){
			if(Visit1[j] == 0 && mg.arcs[i][j].ArcVal == 1){
				cout<<mg.vers[j]<<"  ";
				Visit1[j] = 1;
			}
		}
	}
}

