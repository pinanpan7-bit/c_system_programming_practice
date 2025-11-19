#include <stdio.h>
void countdown(int n){
    if(n>0){
        printf("%d ",n);
        countdown(n-1);
    }
    else if(n<0){
        printf("error\n");
    }
    else{
        printf("0\n");
    }
}
int main(void){
    int n;
    printf("請輸入一個整數:");
    scanf("%d",&n);
    countdown(n);
    return 0;
}