#include <stdio.h>
#include <string.h>
#define MAX 200
char stack[MAX];
int top=-1;
void push(char n){
    if(top==MAX-1){
        printf("stack overflow");
    }
    stack[++top]=n;
}
char pop(){
    if(top==-1){
        return '#';
    }
    return stack[top--];
}
int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
int main(void){
    char p[MAX];
    printf("請輸入一串括號:");
    scanf("%s",p);
    int i,n=strlen(p);
    for(i=0;i<n;i++){
        if(*(p+i)=='('){
            push('(');
        }
        else if(*(p+i)==')'){
            if(pop()=='#'){
                printf("不正確\n");
                return 0;
            }
        }
    }
    if(isEmpty()){
        printf("正確配對\n");
    }
    else{
        printf("不正確\n");
    }
    return 0;
}