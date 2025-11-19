#include<stdio.h>
#include<stdlib.h>
float myAvg(int *arr,int size){
    int i, sum=0;
    float avg=0;
    for(i=0;i<size;i++){
        sum+=*(arr+i);
    }
    avg = (float) sum/size;
    return avg;
}
int main(void){
    int n, i;
    printf("請輸入陣列長度：");
    scanf("%d",&n);
    int *arr = malloc(n * sizeof(int));
    for(i=0;i<n;i++){
        printf("請輸入第%d個值：",(i+1));
        scanf("%d",arr+i);
    }
    printf("平均值是:%.2f\n",myAvg(arr,n));
    free(arr);
    return 0;
}