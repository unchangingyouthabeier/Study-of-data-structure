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
void StrCopy(String s2,String s1);						//��s1���Ƹ�s2 
int StrCompare(String s1,String s2);					//��s1��s2���ݽ��жԱ�
int SubString(String s2,String s1,int pos,int len);		//��ȡ�ַ��������ַ���s1��ȡ�洢��s2�� 
void ClearString(String s);								//����ַ��� 
int Concat(String s3,String s1,String s2);				//���ַ���s1��s2���Ӵ洢��s3�� 
int StrInsert(String s1,int pos,String s2);				//��s1��posλ�ô�����s2 
int DeleteStr(String s,int pos,int len);				//ɾ��ָ��λ��ָ�����ȵ��ַ��� 
int Index(String s1,String s2,int &pos);				//�����Ӵ� 
void Replace(String s1,String s2,String s3);			//��s1�е�s2�Ӵ�ȫ���滻Ϊs3
void DestroyStr(String &s);								//���ַ������� 
int* Arrnext(String s);									//������Ҫ���ҵ�����
int KMP_Index(String s1,String s2,int &pos);			//ʹ��KMP�㷨�����Ӵ����������޵�����
void printArr(int arr[]); 

int main(int argc, char** argv) {
	String s1,s2,s3;
	int flag;
	int length;
	flag = StrAssign(s1,"xiechy");
	cout<<"��ʼ����ֵ�ɹ���"<<flag<<endl;
	cout<<"��ʼ��ֵ����ַ���Ϊ��";
	TranverseStr(s1);
	length = StrLength(s1);
	cout<<"��ǰ�ַ�������Ϊ��"<<length<<endl;
	flag = StrEmpty(s1);
	cout<<"��ǰ�ַ���Ϊ�գ�"<<flag<<endl;
	StrCopy(s2,s1);
	cout<<"��s1���Ƹ�s2��s2Ϊ��";
	TranverseStr(s2);
	flag = StrCompare(s1,s2);
	cout<<"s1>s2:"<<flag<<endl;
	SubString(s3,s1,1,4);
	cout<<"s1��ȡ���֣�";
	TranverseStr(s3);
	ClearString(s1);
	ClearString(s2);
	ClearString(s3);
	cout<<"���s1�������";
	TranverseStr(s1); 
	StrAssign(s1,"�������࣬");
	StrAssign(s2,"Ψ�й�ʽ����"); 
	Concat(s3,s1,s2);
	cout<<"��s1��s2���ӵ�s3�У�";
	TranverseStr(s3);
	ClearString(s1);
	ClearString(s2);
	StrAssign(s1,"xjl");
	StrAssign(s2,"chyhsxh");
	StrInsert(s1,1,s2);
	cout<<"s1����s2�������"; 
	TranverseStr(s1);
	DeleteStr(s1,1,3);
	cout<<"��s1����ɾ���������"; 
	TranverseStr(s1);
	ClearString(s1);
	ClearString(s2);
	int pos;
	StrAssign(s1,"chenhongyuhaishixihuanxiejinlinchenhongyu");
	StrAssign(s2,"chenhongyu");
	ClearString(s3);
	Index(s1,s2,pos);
	cout<<"��s1�����Ӵ�s2,���һԪ��λ��Ϊ��"<<pos<<endl;
	Replace(s1,s2,s3);
	cout<<"��s1�����Ӵ��滻��Ľ����";
	TranverseStr(s1);
	StrAssign(s1,"ACBBABACABABAB");
	StrAssign(s2,"ABACABAB");
	KMP_Index(s1,s2,pos);
	cout<<"ʹ�ó���kmp�㷨���ҵĽ����"<<pos<<endl; 
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
		cout<<"��ʾ�����ӵĳ��ȳ����洢���ȣ��޷�����"<<endl;
		return 0;
	}
	int i,j;
	i = 1;
	j = 1;
	while(s2[j]!='\0'){
		if(s1[i] != '\0' && i<=s1[0]){			//�˴�s1[10]�ƺ����ǵ���'\0'���Զ������������ 
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
		cout<<"��ʾ������λ������򳤶ȹ������޷�����"<<endl; 
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
		cout<<"��ʾ��ɾ��λ���������ɾ�����ȹ���"<<endl; 
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

int* Arrnext(String s){									//���Ʒ���next���飬��Ը����Ϊ��ǿ 
	int next[s[0]+1]={0,0};
	int Sub_len = 0;									//���Ӵ����� 
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

int KMP_Index(String s1,String s2,int &pos){						//�������£�Ψkmp���� 
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
	while(i<=s1[0] && j<=s2[0]){			//i�����ݣ��ص㣩 
		if(s1[i] == s2[j]){					//��ǰƥ��ɹ�����ƥ����һ�� 
			i++;
			j++;				
		}else if(j>1){
			j = next[j-1]+1;					//�ǵ�һ���ַ���ƥ��͸���next��������һЩ�ַ� 
		}else{
			i++;							//��һ���ַ��Ͳ�ƥ�� 
		}
		if(j == s2[0]+1){
			pos = i-s2[0];
			return 1;
		}
	}
	pos = -1;
	return 0;
}













