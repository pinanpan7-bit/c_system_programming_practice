#include <stdio.h>
void matrixSum(int row1,int col1,int row2,int col2,int arr1[row1][col1],int arr2[row2][col2]){
        int i, j;
        int arrsum[row1][col1];
        if(row1!=row2||col1!=col2){
            printf("矩陣大小不一樣無法相加\n");
        }
        else{
            printf("兩矩陣和:\n");
            for(i=0;i<row1;i++){
            for(j=0;j<col1;j++){
                arrsum[i][j]=arr1[i][j]+arr2[i][j];
                printf("%4d ",arrsum[i][j]);
            }
            printf("\n");
            }
        }
}

void transpose(int row1,int col1,int arr[row1][col1]){
    int i, j;
    int transpose[col1][row1];
    printf("矩陣一轉置後:\n");
    for(i=0;i<col1;i++){
        for(j=0;j<row1;j++){
            transpose[i][j]=arr[j][i];
            printf("%d ",transpose[i][j]);
        }
        printf("\n");
    }
}
int main(void){
    int row1, col1;
    int row2, col2;
    int i, j;
    printf("請輸入矩陣一的列行(以逗號間隔):");
    scanf("%d,%d",&row1,&col1);
    int arr1[row1][col1];
    printf("請輸入矩陣一:\n");
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("請輸入矩陣二的列行(以逗號間隔):");
    scanf("%d,%d",&row2,&col2);
    int arr2[row2][col2];
    printf("請輸入矩陣二:\n");
    for(i=0;i<row2;i++){
        for(j=0;j<col2;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    matrixSum(row1,col1,row2,col2,arr1,arr2);
    transpose(row1,col1,arr1);
    return 0;    
}