#include <stdio.h>
int sumdigits(int n){
    if(n>0){
        return n%10+sumdigits(n/10);
    }
    return 0;
}
int main(void){
    int n;
    printf("請輸入一個整數:");
    scanf("%d",&n);
    printf("數字總和為%d\n",sumdigits(n));
    return 0;
}