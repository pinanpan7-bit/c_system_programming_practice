#include <stdio.h>
void printTriangle(int n){
    int i;
    if(n>0){
        printTriangle(n-1);
        for(i=0;i<n;i++){
            printf("*");
        }
        printf("\n");
    }
}
int main(void){
    int n;
    printf("要幾層：");
    scanf("%d",&n);
    printTriangle(n);
    return 0;
}