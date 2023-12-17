#include <iostream>
#include <cstring>
#define MAX_VER_NUM 20
#define NT_EXIST 999
#define VerTxt int
#define Info int
using namespace std;
typedef enum{DG,UG,DN,UN}GraphKind;
typedef char VerType[9];

typedef struct AdjType{
	VerTxt adj;
	Info* info;
}AdjType,AdjMatrix[MAX_VER_NUM][MAX_VER_NUM];

typedef struct MGraph{
	GraphKind kind;
	VerType vers[MAX_VER_NUM];
	int vernum;
	int arcsnum;
	AdjMatrix arc;
}MGraph;

typedef struct OccurrenceTime{
	int Earliest;
	int Latest;
}OccurrenceTime; 

void Display(MGraph mg);
void TopologicalSort(MGraph mg,int Save[]);
void Critical_Path(MGraph mg,int Save[]);

int main(int argc, char** argv) {
	MGraph mg1;
	mg1.kind = DN;
	mg1.vernum = 9;
	strcpy(mg1.vers[0],"v1");	strcpy(mg1.vers[1],"v2");
	strcpy(mg1.vers[2],"v3");	strcpy(mg1.vers[3],"v4");
	strcpy(mg1.vers[4],"v5"); 	strcpy(mg1.vers[5],"v6");
	strcpy(mg1.vers[6],"v7");	strcpy(mg1.vers[7],"v8");
	strcpy(mg1.vers[8],"v9");	
	mg1.arcsnum = 11;
	for(int i = 0;i<mg1.vernum;i++){
		for(int j = 0;j<mg1.vernum;j++){
			mg1.arc[i][j].adj = NT_EXIST;
		}
	}
	mg1.arc[0][1].adj = 6;  mg1.arc[0][2].adj = 4;
	mg1.arc[0][3].adj = 5;  mg1.arc[1][4].adj = 1;
	mg1.arc[2][4].adj = 1;	mg1.arc[3][5].adj = 2;
	mg1.arc[5][7].adj = 4;	mg1.arc[4][7].adj = 7;
	mg1.arc[4][6].adj = 9;	mg1.arc[6][8].adj = 2;
	mg1.arc[7][8].adj = 4;
	Display(mg1);
	int Save[mg1.vernum];
	TopologicalSort(mg1,Save);
	Critical_Path(mg1,Save);
	return 0;
}

void Display(MGraph mg){
	cout<<"邻接矩阵："<<endl;
	int i;
	int j;
	for(i =  0;i < mg.vernum; i++){
		for(j = 0;j < mg.vernum; j++){
			if(mg.arc[i][j].adj==NT_EXIST){
				cout<<"*"<<"   ";
			}else{
				cout<<mg.arc[i][j].adj<<"   "; 
			}
		}
		cout<<endl;
	}
}

void TopologicalSort(MGraph mg,int Save[]){
	int tag[mg.vernum];
	int arr[mg.vernum][mg.vernum];
	for(int i = 0;i < mg.vernum;i++){
		tag[i] = 0;
	}
	for(int i = 0;i < mg.vernum;i++){
		Save[i] = -1;
	}
	for(int i = 0;i < mg.vernum;i++){
		for(int j = 0;j < mg.vernum;j++){
			arr[i][j] = mg.arc[i][j].adj;
		}
	}
	int k = 0;
	for(int i = 0;i < mg.vernum;i++){
		for(int j = 0; j < mg.vernum;j++){
			if(j == i){
				continue;
			}else{
				if(arr[j][i] != NT_EXIST ){
					break;
				}else if(j == mg.vernum-1 && tag[i] != 1 && i!=mg.vernum-1){
					Save[k] = i;
					tag[i] = 1;
					for(int m = 0; m < mg.vernum;m++){
						arr[i][m] = NT_EXIST;
					}
					k++;
				}else if(i == mg.vernum-1 && j == i-1 && tag[i] != 1){
					Save[k] = i;
					tag[i] = 1;
					for(int m = 0; m < mg.vernum;m++){
						arr[i][m] = NT_EXIST;
					}
					k++;
				}
			}
		}
	}
	for(int i = 0;i <mg.vernum;i++){
		cout<<mg.vers[Save[i]]<<"  ";
	}
	cout<<endl;
}

void Critical_Path(MGraph mg,int Save[]){
	OccurrenceTime time[mg.vernum];
	for(int i = 0; i < mg.vernum;i++){
		time[i].Earliest = 0;
		time[i].Latest = 999;//方便后面比较 
	}
	int i = 0;
	for(int k = Save[i];i<mg.vernum;k = Save[++i]){
		int MAX = 0;
		for(int j = 0;j < mg.vernum;j++){
			if(k == j){											//只查找入边的权值,则排除出边的查找 
				continue;
			}else{
				if(k == Save[0]){
					time[0].Earliest = 0;
				}else{
					if(mg.arc[j][k].adj != NT_EXIST){
						MAX = mg.arc[j][k].adj>MAX?mg.arc[j][k].adj:MAX;
						time[i].Earliest = time[i].Earliest>(time[j].Earliest+MAX)?time[i].Earliest:(time[j].Earliest+MAX);
						
					}
				}
			}
		}
	}
	cout<<"最早发生时间：" ; 
	for(int m = 0;m<mg.vernum;m++){
		cout<<time[m].Earliest<<"  ";
	}
	cout<<endl;
	int n = mg.vernum-1; 
	for(int k = Save[n];n>=0;k = Save[--n]){
		for(int j = 0;j < mg.vernum;j++){
			if(k == Save[mg.vernum-1]){
				time[mg.vernum-1].Latest = time[mg.vernum-1].Earliest;
			}else{
				if(mg.arc[k][j].adj!=NT_EXIST){
					time[n].Latest = time[n].Latest<(time[j].Latest-mg.arc[k][j].adj)?time[n].Latest:(time[j].Latest-mg.arc[k][j].adj);
				}		
			}
		}
	}
	cout<<"最迟发生时间：" ; 
	for(int m = 0;m<mg.vernum;m++){
		cout<<time[m].Latest<<"  ";
	}
	cout<<endl;
	cout<<"关键事件：";
	for(int m = 0;m<mg.vernum;m++){
		if(time[m].Earliest==time[m].Latest){
			cout<<mg.vers[m]<<"  ";
		}
	}
}











