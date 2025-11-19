#include <stdio.h>
#include <stdlib.h>
int factorial(int n){
    if(n==0){
        return 1;
    }
    else if(n>0){
        return n*factorial(n-1);
    }
    else{
        return -1;
    }
}
int main(void){
    int n;
    printf("請輸入一個整數:");
    scanf("%d",&n);
    if(factorial(n)==-1){
        printf("請輸入正整數\n");
    }
    else{
        printf("%d!=%d\n",n,factorial(n));
    }    
    return 0;
}