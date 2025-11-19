#include <stdio.h>
int main(void){
    int n;
    int i;
    int sum=0;
    printf("請輸入一個整數：");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum+=i;
    }
    printf("從1加到此整數的和為%d\n",sum);
    return 0;
}