#include <stdio.h>
int main(void){
    int arr[3]={0};
    int i;
    for(i=0;i<3;i++){
        printf("請輸入第%d個整數:",i+1);
        scanf("%d",arr+i);
    }
    int max = arr[0];
    for(i=1;i<3;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    printf("此三數最大為:%d\n",max);
    return 0;
}