#include <iostream>
#include <cstring> 
#define MAX_VER_NUM 20
#define ValType int
#define Info int 
#define NT_EXIST 999
#define adjver int
#define lowcost int 

using namespace std;
typedef enum {DG, NG, DN, UN} GraphKind;
typedef char VerType[9];

typedef struct AdjType{
	ValType ArcVal;
	Info* ArcInfo;
}AdjType,AdjMatrix[MAX_VER_NUM][MAX_VER_NUM];

typedef struct MGraph{
	GraphKind kind;
	VerType vers[MAX_VER_NUM];
	int vernum;
	int arcnum;
	AdjMatrix adj;
}MGraph;

typedef struct Min_Record{
	adjver a;
	lowcost l;
}Min_Record;

typedef struct SaveRank{
	int a;
	int b;
	ValType weight;
}SaveRank;


void Display(MGraph mg);
void Min_Span_Tree_Of_Kruzkal(MGraph mg);
void Min_Span_Tree_Of_Prim(MGraph mg);

int main(int argc, char** argv) {
	MGraph mg1;
	mg1.kind = UN;
	mg1.vernum = 6;
	strcpy(mg1.vers[0], "v1");  strcpy(mg1.vers[1], "v2");
	strcpy(mg1.vers[2], "v3");  strcpy(mg1.vers[3], "v4");
	strcpy(mg1.vers[4], "v5");  strcpy(mg1.vers[5], "v6");
	int i;
	int j;
	for(i = 0;i<mg1.vernum;i++){
		for(j = 0;j<mg1.vernum;j++){
			mg1.adj[i][j].ArcVal = NT_EXIST;
		}
	}
	mg1.adj[0][1].ArcVal = 6;  mg1.adj[1][0].ArcVal = 6;
	mg1.adj[0][2].ArcVal = 1;  mg1.adj[2][0].ArcVal = 1;
	mg1.adj[0][3].ArcVal = 5;  mg1.adj[3][0].ArcVal = 5;
	mg1.adj[1][2].ArcVal = 5;  mg1.adj[2][1].ArcVal = 5;
	mg1.adj[1][4].ArcVal = 3;  mg1.adj[4][1].ArcVal = 3;
	mg1.adj[2][3].ArcVal = 5;  mg1.adj[3][2].ArcVal = 5;
	mg1.adj[2][4].ArcVal = 6;  mg1.adj[4][2].ArcVal = 6;
	mg1.adj[2][5].ArcVal = 4;  mg1.adj[5][2].ArcVal = 4;
	mg1.adj[3][5].ArcVal = 2;  mg1.adj[5][3].ArcVal = 2;
	mg1.adj[4][5].ArcVal = 6;  mg1.adj[5][4].ArcVal = 6;
	mg1.arcnum = 10;
	Display(mg1);
	Min_Span_Tree_Of_Prim(mg1);
	Min_Span_Tree_Of_Kruzkal(mg1);
	return 0;
}

void Display(MGraph mg){
	cout<<"邻接矩阵："<<endl;
	int i;
	int j;
	for(i =  0;i < mg.vernum; i++){
		for(j = 0;j < mg.vernum; j++){
			if(mg.adj[i][j].ArcVal==NT_EXIST){
				cout<<"*"<<"   ";
			}else{
				cout<<mg.adj[i][j].ArcVal<<"   "; 
			}
		}
		cout<<endl;
	}
}

void Min_Span_Tree_Of_Prim(MGraph mg){
	cout<<"普利姆最小生成树：(最小花费树)"<<endl;
	Min_Record record[mg.vernum];
	for(int i = 0;i<mg.vernum;i++){
		record[i].a = 0;
		record[i].l = mg.adj[0][i].ArcVal;
	}	
	record[0].l = 0;
	int cv = 1;
	int index = 0;
	cout<<mg.vers[0]<<"-->";
	while(cv!=6){
		int min = NT_EXIST;
		
		for(int i = 0;i<mg.vernum;i++){
			if(record[i].l != 0){
				min = record[i].l<min?record[i].l:min;
				if(min == record[i].l){
					index = i;
				}
			}
		}
		if(cv!=1){
			cout<<mg.vers[record[index].a]<<"-->";
		}
		record[index].l = 0;
		for(int i = 0;i < mg.vernum;i++){
			if(record[i].l != 0){
				if(mg.adj[index][i].ArcVal<record[i].l){
					record[i].a = index;
					record[i].l = mg.adj[index][i].ArcVal;
				}
			}
		}
		cout<<mg.vers[index]<<"  ";
		cout<<endl;
		for(int i = 0; i<mg.vernum;i++){
			cout<<record[i].a<<"  ";
		}
		cout<<endl;
		for(int i = 0; i<mg.vernum;i++){
			cout<<record[i].l<<"  ";
		}
		cout<<endl;
		cv++;
	}
	cout<<endl;	
}

void Min_Span_Tree_Of_Kruzkal(MGraph mg){
	int i;
	int j;
	int tag[mg.vernum];
	for(int k = 0; k < mg.vernum;k++){
		tag[k] = k;
	}
	SaveRank rank[MAX_VER_NUM];
	int m = 0;
	for(i = 0;i < mg.vernum-1;i++){
		for(j = i+1;j < mg.vernum;j++){
			if(mg.adj[i][j].ArcVal!=NT_EXIST && m==0){
				rank[0].a = i;
				rank[0].b = j;
				rank[0].weight = mg.adj[i][j].ArcVal;
				m++;
			}else if( m != 0 && mg.adj[i][j].ArcVal!=NT_EXIST){
				if(m == 1){
					if(mg.adj[i][j].ArcVal < rank[0].weight){
						rank[1] = rank[0];
						rank[0].a = i;
						rank[0].b = j;
						rank[0].weight = mg.adj[i][j].ArcVal;
					}
				}else{
					int n = 0;
					for(n = m-1; n >= 0;n--){
						if(n == (m-1) && mg.adj[i][j].ArcVal >= rank[n].weight){
							rank[m].a = i;
							rank[m].b = j;
							rank[m].weight = mg.adj[i][j].ArcVal;
							break;
						}else if(mg.adj[i][j].ArcVal > rank[n].weight){
							break;
						}
					}
					if(n != m-1){
						int t;
						for(t = m-1;t>n;t--){
							rank[t+1] = rank[t];
 						}
						rank[n+1].a = i;
						rank[n+1].b = j;
						rank[n+1].weight = mg.adj[i][j].ArcVal;
					}
				}
				m++;
			}
		}
    }
    cout<<"排序后的边："<<endl; 
	for(i = 0;i < mg.arcnum; i++){
		cout<<mg.vers[rank[i].a]<<"-->"<<mg.vers[rank[i].b]<<"  "<<rank[i].weight<<endl;
	}
	cout<<"克鲁斯卡尔最小生成树（最小花费树）："<<endl;
	cout<<mg.vers[rank[0].a]<<"-->"<<mg.vers[rank[0].b]<<"   ";
	tag[rank[0].b] = tag[rank[0].a];
	for(i = 1;i < mg.arcnum; i++){
		if(tag[rank[i].b] != tag[rank[i].a]){
			cout<<mg.vers[rank[i].a]<<"-->"<<mg.vers[rank[i].b]<<"   ";
			for(int k = i-1;k >= 0; k--){
				if(tag[rank[k].a] == (tag[rank[i].b]>tag[rank[i].a]?tag[rank[i].b]:tag[rank[i].a])||tag[rank[k].b] == (tag[rank[i].b]>tag[rank[i].a]?tag[rank[i].b]:tag[rank[i].a])){
					tag[rank[k].a] = tag[rank[i].a]<tag[rank[i].b]?tag[rank[i].a]:tag[rank[i].b];
					tag[rank[k].b] =  tag[rank[i].a]<tag[rank[i].b]?tag[rank[i].a]:tag[rank[i].b];
				}
			}
			tag[rank[i].b] = tag[rank[i].a]<tag[rank[i].b]?tag[rank[i].a]:tag[rank[i].b];
			tag[rank[i].a] = tag[rank[i].a]<tag[rank[i].b]?tag[rank[i].a]:tag[rank[i].b];
		}
	}
	cout<<endl;
}
	
	


