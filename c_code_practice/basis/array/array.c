#include <stdio.h>
int findMax(int arr[],int n){
    int max=arr[0];
    int i;
    for(i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int findMin(int arr[],int n){
    int min=arr[0];
    int i;
    for(i=1;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}

float getAverage(int arr[],int n){
    int sum=0;
    float avg=0;
    int i;
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    avg=(float)sum/n;
    return avg;
}
int counter(int arr[],int n,int key){
    int count=0;
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==key){
            count+=1;
        }
    }
    return count;
}
void reverse(int arr[],int n){
    int temp;
    int i;
    for(i=0;i<n/2;i++){
        temp=*(arr+i);
        *(arr+i)=*(arr+(n-i-1));
        *(arr+(n-i-1))=temp;
    }
}
void bubbleSort(int arr[],int n){
    int i;
    int j;
    int temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(void){
    int n;
    int i;
    int key;
    printf("輸入幾個整數：");
    scanf("%d",&n);
    printf("要計算個數的數字是：");
    scanf("%d",&key);
    int arr[n];
    for(i=0;i<n;i++){
        printf("請輸入第%d個數字：",i+1);
        scanf("%d",arr+i);
    }
    printf("最大值是：%d\n",findMax(arr,n));
    printf("最小值是：%d\n",findMin(arr,n));
    printf("平均值是：%f\n",getAverage(arr,n));
    printf("%d出現%d次\n",key,counter(arr,n,key));
    printf("顛倒陣列：\n");
    reverse(arr,n);
    for(i=0;i<n;i++){
        printf("%d\n",*(arr+i));
    }
    printf("由大到小：\n");
    bubbleSort(arr,n);
    for(i=0;i<n;i++){
        printf("%d\n",*(arr+i));
    }
    return 0;
}