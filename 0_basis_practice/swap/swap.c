#include <stdio.h>
void int_swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void char_swap(char *a, char *b){
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(void){
    int x, y;
    printf("請輸入兩個整數(用空白鍵分隔):");
    scanf("%d %d",&x,&y);
    int_swap(&x,&y);
    printf("交換後為(%d,%d)\n",x,y);
    char i,j;
    printf("請輸入兩個字元(用空白鍵分隔):");
    scanf(" %c %c",&i,&j);
    char_swap(&i,&j);
    printf("交換後為(%c,%c)\n",i,j);
}