#include <iostream>
using namespace std;

int Search_Binary(int arr[],int len,int e);
int Search_Monitor(int arr[],int len,int e);

int main(int argc, char** argv) {
	int arr1[11] = {05,13,19,21,37,56,64,75,80,88,92};
	int var;
	var = Search_Binary(arr1,11,80);
	cout<<"所查找的数的索引："<<var<<endl;
	int arr2[12] = {0,05,13,19,21,37,56,64,75,80,88,92};
	var = Search_Monitor(arr2,21,24);
	cout<<"所查找的数的索引："<<var<<endl;
	return 0;
}

int Search_Binary(int arr[],int len,int e){
	int low = 0;
	int high = len-1;
	int mid = (low+high)/2;
	while(low<=high){
		if(e == arr[mid]){
			return mid;
		}else if(e > arr[mid]){
			low = mid+1;
			mid = (high+low)/2;
		}else{
			high = mid-1;
			mid = (high+low)/2; 
		}
	}
	return -1;
}

int Search_Monitor(int arr[],int len,int e){
	arr[0] = e;
	int i = len-1;
	while(arr[i]!=e){
		i--;
	}
	return i;
}


