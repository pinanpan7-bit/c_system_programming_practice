#include <stdio.h>
int fib(int n){
    if(n==1||n==0){
        return n;
    }
    return fib(n-1)+fib(n-2);   
}
int main(void){
    int n;
    printf("請輸入一個整數:");
    scanf("%d",&n);
    printf("fib(%d)=%d\n",n,fib(n));
    return 0;
}