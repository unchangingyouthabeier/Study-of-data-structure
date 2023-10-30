#include <iostream>
#define Default_Size 225
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef unsigned char String[Default_Size+1];
int StrAssign(String s,char c[]);
void TranverseStr(String s);
int StrLength(String s);
int StrEmpty(String s);
void StrCopy(String s2,String s1);						//将s1复制给s2 
int StrCompare(String s1,String s2);					//将s1与s2内容进行对比
int SubString(String s2,String s1,int pos,int len);		//截取字符串，将字符串s1截取存储到s2中 
void ClearString(String s);								//清空字符串 
int Concat(String s3,String s1,String s2);				//将字符串s1与s2连接存储到s3中 
int StrInsert(String s1,int pos,String s2);				//向s1的pos位置处插入s2 
int DeleteStr(String s,int pos,int len);				//删除指定位置指定长度的字符串 
int Index(String s1,String s2,int &pos);				//查找子串 
void Replace(String s1,String s2,String s3);			//将s1中的s2子串全部替换为s3
void DestroyStr(String &s);								//将字符串销毁 
int* Arrnext(String s);									//传入需要查找的数组
int KMP_Index(String s1,String s2,int &pos);			//使用KMP算法查找子串（是在下无敌啦）
void printArr(int arr[]); 

int main(int argc, char** argv) {
	String s1,s2,s3;
	int flag;
	int length;
	flag = StrAssign(s1,"xiechy");
	cout<<"初始化赋值成功："<<flag<<endl;
	cout<<"初始赋值后的字符串为：";
	TranverseStr(s1);
	length = StrLength(s1);
	cout<<"当前字符串长度为："<<length<<endl;
	flag = StrEmpty(s1);
	cout<<"当前字符串为空："<<flag<<endl;
	StrCopy(s2,s1);
	cout<<"将s1复制给s2后s2为：";
	TranverseStr(s2);
	flag = StrCompare(s1,s2);
	cout<<"s1>s2:"<<flag<<endl;
	SubString(s3,s1,1,4);
	cout<<"s1截取部分：";
	TranverseStr(s3);
	ClearString(s1);
	ClearString(s2);
	ClearString(s3);
	cout<<"清空s1后遍历：";
	TranverseStr(s1); 
	StrAssign(s1,"万物速朽，");
	StrAssign(s2,"唯有公式永恒"); 
	Concat(s3,s1,s2);
	cout<<"将s1与s2连接到s3中：";
	TranverseStr(s3);
	ClearString(s1);
	ClearString(s2);
	StrAssign(s1,"xjl");
	StrAssign(s2,"chyhsxh");
	StrInsert(s1,1,s2);
	cout<<"s1插入s2后遍历："; 
	TranverseStr(s1);
	DeleteStr(s1,1,3);
	cout<<"对s1进行删除后遍历："; 
	TranverseStr(s1);
	ClearString(s1);
	ClearString(s2);
	int pos;
	StrAssign(s1,"chenhongyuhaishixihuanxiejinlinchenhongyu");
	StrAssign(s2,"chenhongyu");
	ClearString(s3);
	Index(s1,s2,pos);
	cout<<"在s1查找子串s2,其第一元素位置为："<<pos<<endl;
	Replace(s1,s2,s3);
	cout<<"对s1进行子串替换后的结果：";
	TranverseStr(s1);
	StrAssign(s1,"ACBBABACABABAB");
	StrAssign(s2,"ABACABAB");
	KMP_Index(s1,s2,pos);
	cout<<"使用超级kmp算法查找的结果："<<pos<<endl; 
	DestroyStr(s1);
	DestroyStr(s2);
	DestroyStr(s3);
	return 0;
}

int StrAssign(String s,char c[]){
	if(strlen(c)>Default_Size){
		return 0;
	}
	int i=0;
	while(c[i]!='\0'){
		s[i+1] = c[i];
		i++;
	}
	s[0] = strlen(c);
	return 1;
}

void TranverseStr(String s){
	int i;
	for(i=1; i<=s[0];i++){
		cout<<s[i];
	}
	cout<<endl;
}

int StrLength(String s){
	return s[0];
}

int StrEmpty(String s){
	if(s[0]==0){
		return 1;
	}
	return 0;
}

void StrCopy(String s2,String s1){
	int i;
	for(i = 1; i<=s1[0];i++){
		s2[i] = s1[i];
	}
	s2[0] = s1[0];
}

int StrCompare(String s1,String s2){
	int i;
	i = 1;
	while(s1[i]!='\0' && s2[i]!='\0'){
		if(s1[i]>s2[i]||s1[i]<s2[i]){
			return s1[i] - s2[i];
		}
		i++;
	}
	if(s1[0]!=s2[0]){
		return s1[0]>s2[0]?s1[0]-'\0':'\0'-s2[0];
	}
	return s2[0]-s1[0];
}

int SubString(String s2,String s1,int pos,int len){
	if(pos>s1[0] || pos<=0 || (len+pos)>s1[0]){
		return 0;
	}
	int i;
	i = 1;
	while(i!=len+1){
		s2[pos] = s1[i];
		pos++;
		i++;
	}
	s2[0] = len;
	return 1;
}

void ClearString(String s){
	int i;
	for(i = 1; i<=s[0];i++){
		s[i] = '\0';
	}
	s[0] = 0;
}

int Concat(String s3,String s1,String s2){
	if(s1[0]+s2[0]>Default_Size){
		cout<<"提示：连接的长度超过存储长度，无法连接"<<endl;
		return 0;
	}
	int i,j;
	i = 1;
	j = 1;
	while(s2[j]!='\0'){
		if(s1[i] != '\0' && i<=s1[0]){			//此处s1[10]似乎不是等于'\0'所以多加了条件限制 
			s3[i] = s1[i];
			i++;
		}else{
			s3[i] = s2[j];
			j++;
			i++;
		}
	}
//	while(s1[i]!='\0'){
//		s3[i] = s1[i];
//		i++;
//	}
//	while(s1[j]!='\0'){
//		s3[i+j-1] = s2[j];
//		j++;
//	}
	s3[0] = s1[0]+s2[0];
	return 1;
}

int StrInsert(String s1,int pos,String s2){
	if(s1[0]+s2[0]>Default_Size || pos>s1[0]+1 ||pos < 1){
		cout<<"提示：插入位置有误或长度过长，无法插入"<<endl; 
		return 0;
	}
	int i;
	i = 0;
	if(pos!=(s1[0]+1)){
		while(i != s2[0]){
			s1[s1[0]+s2[0]-i]= s1[s1[0]-i]; 
			i++; 
		}
		for(i = 1; i<=s2[0]; i++){
			s1[pos+i-1] = s2[i];
		}
		s1[0] = s2[0]+s1[0];
	}else{
		for(i = 1; i<=s2[0]; i++){
			s1[s1[0]+i] = s2[i];
		}
		s1[0] = s2[0]+s1[0];
	}
	return 1;
}

int DeleteStr(String s,int pos, int len){
	if(pos<1 || pos > s[0] || len>(s[0]-pos+1)){
		cout<<"提示：删除位置有误或是删除长度过长"<<endl; 
		return 0;
	}
	if(pos==1 && len==s[0]){
		ClearString(s);
	}else{
		int i;
		i = 0;
		while(i!=s[0]-pos){
			s[pos+i] = s[pos+len+i];
			i++; 
		}
		i = 0;
		while(i!=len){
			s[s[0]-i] = '\0';
			i++;
		}
	}
	s[0] = s[0]-len;
}

int Index(String s1,String s2,int &pos){
	if(s1[0] == 0 || s2[0] == 0 || s2[0]>s1[0]){
		pos = -1;
		return 0;
	}
	int i,j;
	j = 1;
	i = 1;
	int count;
	count = 0;
	while(s1[j]!='\0'){
		if(s2[i] != s1[j] && i<=s2[0]){
			count++;
			j = count;
			i = 1;
		}else if(i >= s2[0] && s2[i] == s1[j]){
			pos = j-s2[0]+1;
			return 1;	
		}else{
			i++;
			j++;	
		}	
	}
	pos = -1;
	return 0;
}

void Replace(String s1,String s2,String s3){
	int pos;
	while(pos != -1){
		Index(s1,s2,pos);
		if(pos ==-1){
			break;
		}
		if(s3[0] == 0 ){
			DeleteStr(s1,pos,s2[0]);
		}else{
			int i;
			for(i = 1; i<=s2[0]; i++){
				s1[pos+i-1] = s2[i];
			}
		}
	}
}

void DestroyStr(String &s){
	free(s);
}

int* Arrnext(String s){									//递推法求next数组，我愿称你为最强 
	int next[s[0]+1]={0,0};
	int Sub_len = 0;									//真子串长度 
	int i = 2;
	while(i < s[0]){
		if(s[Sub_len+1] == s[i]){
			Sub_len+=1;
			next[i] = Sub_len;
			i++;
		}else{
			if(Sub_len == 0){
				next[i] = 0;
				i++;
			}else{
				Sub_len = next[Sub_len];
			}
		}
	}
	return next;
}

int KMP_Index(String s1,String s2,int &pos){						//天上天下，唯kmp独尊 
	if(s1[0] == 0 || s2[0] == 0 || s2[0]>s1[0]){
		pos = -1;
		return 0;
	}
	int *next;
	next = Arrnext(s2);
	int i;
	int j;
	i = 1;
	j = 1;
	while(i<=s1[0] && j<=s2[0]){			//i不回溯（特点） 
		if(s1[i] == s2[j]){					//当前匹配成功继续匹配下一个 
			i++;
			j++;				
		}else if(j>1){
			j = next[j-1]+1;					//非第一个字符不匹配就根据next数组跳过一些字符 
		}else{
			i++;							//第一个字符就不匹配 
		}
		if(j == s2[0]+1){
			pos = i-s2[0];
			return 1;
		}
	}
	pos = -1;
	return 0;
}













