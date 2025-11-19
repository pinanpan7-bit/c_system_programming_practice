#include <stdio.h>
#include <stdlib.h>
int binary_search(int arr[],int n,int key){
    int *left=arr, *right=arr+n-1;
    int *mid;
    int id=-1;
    while(left<=right){
        mid=left+(right-left)/2;
        if(key<*mid){
            right=mid-1;
        }
        else if(key>*mid){
            left=mid+1;
        }
        else{
            id=mid-arr;
            break;
        }
    }
    return id;
}
int main(void){
    int n;
    printf("請輸入陣列個數：");
    scanf("%d",&n);
    int i;
    int *arr=malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        printf("請輸入第%d個數字(由小到大輸入)：",i+1);
        scanf("%d",arr+i);
    }
    int key;
    printf("要搜尋的數字:");
    scanf("%d",&key);
    printf("%d在陣列中的索引為%d (若索引為-1代表%d不存在陣列中)",key,binary_search(arr,n,key),key);
    free(arr);
    return 0;
}