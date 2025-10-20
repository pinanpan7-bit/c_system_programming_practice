#include <stdio.h>
int main(void){
    int i;
    int j;
    int n;
    printf("要蓋幾層金字塔：");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<i;j++){
            printf(" ");
        }
        for(j=1;j<=2*(n-i)+1;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}