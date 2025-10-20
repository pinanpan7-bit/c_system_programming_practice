#include <stdio.h>
#include <stdlib.h>
int linear_search(int arr[], int n, int key){
    int id=-1;
    int i;
    for(i=0;i<n;i++){
        if(arr[i]==key){
            id=i;
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
        printf("請輸入第%d個數字：",i+1);
        scanf("%d",arr+i);
    }
    int key;
    printf("要搜尋的數字:");
    scanf("%d",&key);
    printf("%d在陣列中的索引為%d (索引為-1代表%d不存在陣列中)",key,linear_search(arr,n,key),key);
    free(arr);
    return 0;
}