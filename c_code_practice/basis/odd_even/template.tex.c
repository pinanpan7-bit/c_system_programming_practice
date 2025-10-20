#include <stdio.h>
int main(void){
    int x;
    printf("請輸入一個整數:");
    scanf("%d",&x);
    if(x%2==0){
        printf("此數為偶數\n");
    }
    else{
        printf("此數為奇數\n");
    }
    return 0;
} 