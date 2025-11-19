#include <stdio.h>
#include <string.h>
void stu_avg(int stu_num,int sub_num,int arr[stu_num][sub_num]){
    int i, j;
    int sum[stu_num];
    memset(sum,0,sizeof(sum));
    for(i=0;i<stu_num;i++){
        for(j=0;j<sub_num;j++){
            sum[i]+=arr[i][j];
        }
    }
    printf("各學生總平均:\n");
    for(i=0;i<stu_num;i++){
        printf("%f\n",(double)sum[i]/sub_num);
    }
}
void sub_avg(int stu_num,int sub_num,int arr[stu_num][sub_num]){
    int i, j;
    int sum[sub_num];
    memset(sum,0,sizeof(sum));
    for(i=0;i<sub_num;i++){
        for(j=0;j<stu_num;j++){
            sum[i]+=arr[j][i];
        }
    }
    printf("各科平均為:\n");
    for(i=0;i<sub_num;i++){
        printf("%f\n",(double)sum[i]/stu_num);
    }
}
void printMaxMin(int stu_num,int sub_num,int arr[stu_num][sub_num]){
    int max=arr[0][0],min=arr[0][0];
    int i,j;
    for(i=0;i<stu_num;i++){
        for(j=0;j<sub_num;j++){
            if(arr[i][j]>max){
                max=arr[i][j];
            }
            else if(arr[i][j]<min){
                min=arr[i][j];
            }
        }
    }
    printf("最大值為:%d\n最小值為:%d",max,min);
}
int main(void){
    int stu_num;
    int sub_num;
    printf("請輸入學生數,科目數:");
    scanf("%d,%d",&stu_num,&sub_num);
    int arr[stu_num][sub_num];
    int i, j;
    printf("請輸入學生各科分數(一學生一列):\n");
    for(i=0;i<stu_num;i++){
        for(j=0;j<sub_num;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    stu_avg(stu_num,sub_num,arr);
    sub_avg(stu_num,sub_num,arr);
    printMaxMin(stu_num,sub_num,arr);
    return 0;
}