#include <iostream>

using namespace std;
//ʮ������
void Bubbling_Sorting(int arr[],int len); 			//ð������
void Quick_Sort(int arr[],int low,int high);
void Insert_Sort(int arr[],int len);



void Tranverse(int arr[],int len);

int main(int argc, char** argv) {
	int arr1[] = {19,7,10,24,9,8,5,4,2};
	Bubbling_Sorting(arr1,sizeof(arr1)/sizeof(int));
	cout<<"ð������";	
	Tranverse(arr1,sizeof(arr1)/sizeof(int));
	int arr2[] = {19,7,10,24,9,8,5,4,2};
	Quick_Sort(arr2,0,8);
	cout<<"��������";
	Tranverse(arr2,sizeof(arr2)/sizeof(int));
	int arr3[] = {19,7,10,24,9,8,5,4,2};
	Insert_Sort(arr3,sizeof(arr3)/sizeof(int));
	cout<<"��������"; 
	Tranverse(arr3,sizeof(arr3)/sizeof(int));
	return 0;
}

//���ֽ��� 

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

void Swap(int arr[],int i,int j){			//���ַ����ƺ�����ĳ�����⣨�ڿ���ʽ�д�
	if(i != j){								//����������������� ���˴��������ԭ�򣩣��Ҷ������������������ 
		arr[i] = arr[i] + arr[j];
		arr[j] = arr[i] -arr[j];
		arr[i] = arr[i] - arr[j];
	}
}

void Bubbling_Sorting(int arr[],int len){
	for(int i = 0;i < len - 1; i++){				//һ��Ҫ��n-1��	 
//		for(int j = 0;j < len-1;j++){				//ÿ�αȽ������������Ĵ�С�������������н��� 
//			if(arr[j] > arr[j+1]){					//�˴��ıȽϵ�ѭ�������Ż� 
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
        int benchmark = arr[i];  // ������׼
        while (i < j) {
            // ������Ҫ�߼���
            // ѭ��ֱ���ҵ��Ȼ�׼С��������н���
            while (i < j && arr[j] >= benchmark) {
                j--;
            }
            Swap(arr, i, j);
            while (i < j && arr[i] <= benchmark) {
                i++;
            }
            Swap(arr, i, j);
        }
        // �ݹ���÷ֱ������������֣�
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

