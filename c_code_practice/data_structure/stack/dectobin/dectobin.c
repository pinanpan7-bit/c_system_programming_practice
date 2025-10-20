#include <stdio.h>
#define MAX 200
int stack[MAX];
int top=-1;
int pop(){
    if(top==-1){
        printf("stack underflow");
        return -1;
    }
    return stack[top--];
}
void push(int n){
    if(top==MAX-1){
        printf("stack overflow");
        return;
    }
    stack[++top]=n;
}
int main(void){
    int num;
    printf("請輸入一整數:");
    scanf("%d",&num);
    while(num>0){
        push(num%2);
        num=num/2;
    }
    printf("轉成二進制:");
    int i;
    while(top!=-1){
        printf("%d",pop());
    }
    printf("\n");
    return 0;
}