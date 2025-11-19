#include <stdio.h>
#include <stdlib.h>
void selectSort(int *arr, int n){
    int *p = arr;
    int i, j;
    int temp;
    for(i=0;i<n-1;i++){
        p = arr+i;        
        for(j=i+1;j<n;j++){
            if(*(arr+j)<*p){
                p = arr + j;
            }
        }
        temp = *(arr+i);
        *(arr+i) = *p;
        *p = temp;
    }
}
int main(void){
    int n;
    printf("請輸入陣列個數:");
    scanf("%d",&n);
    int *arr = malloc(n * sizeof(int));
    int i;
    for(i=0;i<n;i++){
        printf("請輸入第%d個數字:",i+1);
        scanf("%d",arr+i);
    }
    selectSort(arr,n);
    printf("Select_Sort結果為:");
    for(i=0;i<n;i++){
        printf("%d ",*(arr+i));        
    }
    free(arr);
    return 0;
}