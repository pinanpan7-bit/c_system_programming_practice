#include<stdio.h>
int main(void){
    int x;
    printf("請輸入一個整數:");
    scanf("%d",&x);
    if(x>=90 && x<= 100){
        printf("A\n");
    }
    else if(80<=x && x<90){
        printf("B\n");
    }
    else if(70<=x && x<80){
        printf("C\n");
    }
    else if(60<=x && x<70){
        printf("D\n");
    }
    else if(0<=x && x<60){
        printf("F\n");
    }
    else{
        printf("請輸入0-100整數");
    }
    return 0;
}