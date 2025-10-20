#include <stdio.h>
int main(void){
    int i;
    int j;
    int n;
    printf("請輸入行數：");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}