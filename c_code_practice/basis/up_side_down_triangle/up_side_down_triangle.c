#include <stdio.h>
int main(void){
    int i;
    int j;
    int n;
    printf("請輸入一個整數：");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=n;j>=i;j--){
            printf("*");
        }
        printf("\n");
    }
}