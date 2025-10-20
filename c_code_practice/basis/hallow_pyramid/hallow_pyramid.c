#include <stdio.h>
int main(void){
    int i;
    int j;
    int k;
    int n;
    printf("要蓋幾層金字塔：");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        if(i==1||i==n){
            for(j=1;j<=2*i-1;j++){
                printf("*");
            }
        }
        else{
            printf("*");
            for(k=1;k<=2*i-3;k++){
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    return 0;
}