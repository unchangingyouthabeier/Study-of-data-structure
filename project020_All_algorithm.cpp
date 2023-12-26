#include <iostream>

using namespace std;
//十大排序：
void Bubbling_Sorting(int arr[],int len); 			//冒泡排序
void Quick_Sort(int arr[],int low,int high);
void Insert_Sort(int arr[],int len);



void Tranverse(int arr[],int len);

int main(int argc, char** argv) {
	int arr1[] = {19,7,10,24,9,8,5,4,2};
	Bubbling_Sorting(arr1,sizeof(arr1)/sizeof(int));
	cout<<"冒泡排序：";	
	Tranverse(arr1,sizeof(arr1)/sizeof(int));
	int arr2[] = {19,7,10,24,9,8,5,4,2};
	Quick_Sort(arr2,0,8);
	cout<<"快速排序：";
	Tranverse(arr2,sizeof(arr2)/sizeof(int));
	int arr3[] = {19,7,10,24,9,8,5,4,2};
	Insert_Sort(arr3,sizeof(arr3)/sizeof(int));
	cout<<"插入排序："; 
	Tranverse(arr3,sizeof(arr3)/sizeof(int));
	return 0;
}

//三种交换 

//void Swap(int arr[], int i, int j) {			 
//    int temp = arr[i];
//    arr[i] = arr[j];
//    arr[j] = temp;
//}

//void Swap(int arr[], int i, int j) {
//    if (i != j) {
//        arr[i] = arr[i] ^ arr[j];
//        arr[j] = arr[i] ^ arr[j];
//        arr[i] = arr[i] ^ arr[j];
//    }
//}

void Swap(int arr[],int i,int j){			//该种方法似乎存在某种问题（在快排式有错）
	if(i != j){								//问题解决考虑溢出问题 （此处不是这个原因），我多加了条件他就正常了 
		arr[i] = arr[i] + arr[j];
		arr[j] = arr[i] -arr[j];
		arr[i] = arr[i] - arr[j];
	}
}

void Bubbling_Sorting(int arr[],int len){
	for(int i = 0;i < len - 1; i++){				//一共要有n-1趟	 
//		for(int j = 0;j < len-1;j++){				//每次比较相邻两个数的大小，满足条件进行交换 
//			if(arr[j] > arr[j+1]){					//此处的比较的循环可以优化 
//				arr[j] = arr[j+1] + arr[j];
//				arr[j+1] = arr[j] - arr[j+1];
//				arr[j] = arr[j] - arr[j+1];
//			}
//		}
		for(int j = 0;j < len-1-i; j++){
			if(arr[j] > arr[j+1]){
				Swap(arr,j,j+1);
			}
		}
	}
}

void Quick_Sort(int arr[], int low, int high) {
    if (low < high) {
        int i = low;
        int j = high;
        int benchmark = arr[i];  // 设立基准
        while (i < j) {
            // 快排主要逻辑：
            // 循环直到找到比基准小的数后进行交换
            while (i < j && arr[j] >= benchmark) {
                j--;
            }
            Swap(arr, i, j);
            while (i < j && arr[i] <= benchmark) {
                i++;
            }
            Swap(arr, i, j);
        }
        // 递归调用分别处理左右两部分：
        if (low < i - 1) {
            Quick_Sort(arr, low, i - 1);
        }
        if (i + 1 < high) {
            Quick_Sort(arr, i + 1, high);
        }
    }
}

//void Insert_Sort(int arr[], int len) {
//    for (int i = 1; i < len; i++) {
//        if (arr[i] < arr[i - 1]) {
//            int j = i - 1;
//            int temp = arr[i];
//            while (j >= 0 && arr[j] > temp) {
//                arr[j + 1] = arr[j];
//                j--;
//            }
//            arr[j + 1] = temp;
//        }
//    }
//}

void Insert_Sort(int arr[],int len){
	for(int i = 1;i<len;i++){
		if(arr[i]<arr[i-1]){
			int j = i-1;
			int temp = arr[i];
			while(arr[j]>temp && j>=0){
				j--;
			}
			for(int k = i-1;k>j;k--){
				arr[k+1]=arr[k];
			}
			arr[j+1] = temp;
		}
	}
} 

void Tranverse(int arr[],int len){
	for(int i = 0; i < len;i++){
		cout<<arr[i]<<"   ";
	}
	cout<<endl;
}

