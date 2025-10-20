#include <stdio.h>
#include <stdlib.h>
void insertsort(int arr[], int n){
    int i, j;
    int temp;
    for(i=1;i<n;i++){
        int *p = arr+i;                           //p指向新牌
        int key = *p;
        for(j=i-1;j>=0;j--){
            if(*(arr+j)>key){                    //arr+j指向原有的牌
                *(arr+j+1) = *(arr+j);
            }
            else{
                break;
            }
        }
        *(arr+j+1)=key;
    }
}
int main(void){
    int n;
    printf("請輸入陣列個數：");
    scanf("%d",&n);
    int *arr = malloc(n * sizeof(int));
    int i;
    for(i=0;i<n;i++){
        printf("請輸入第%d個數字：",i+1);
        scanf("%d",arr+i);
    }
    insertsort(arr,n);
    printf("Inser Sort後的結果為:");
    for(i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
    free(arr);
    return 0;
}