#include <stdio.h>
#include <string.h>
#define MAX 200
char stack[MAX];
int top=-1;
int pop(){
    if(top==-1){
        printf("stack underflow");
        return -1;
    }
    return stack[top--];
}
void push(char c){
    if(top==MAX-1){
        printf("stack overflow");
        return;
    }
    stack[++top]=c;
}
int main(void){
    char input[MAX];
    printf("請輸入一個字串:");
    fgets(input,MAX,stdin);
    input[strcspn(input,"\n")]='\0';
    int i,n=strlen(input);
    for(i=0;i<n;i++){
        push(input[i]);
    }
    printf("反轉後:");
    while(top!=-1){
        printf("%c",pop());
    }
    printf("\n");
    return 0;
}