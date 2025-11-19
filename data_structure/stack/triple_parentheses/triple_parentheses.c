#include <stdio.h>
#include <string.h>
#define MAX 200
char stack[MAX];
int top=-1;
char pop(){
    if(top==-1){
        return '#';
    }
    return stack[top--];
}
void push(char c){
    if(top==MAX-1){
        printf("stack overflow");
    }
    stack[++top]=c;
}
int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
int match(char left,char right){
    return (left=='('&&right==')')||(left=='['&&right==']')||(left=='{'&&right=='}');
}
int main(void){
    char p[MAX];
    printf("請輸入一串括號:");
    scanf("%s",p);
    int i,n=strlen(p);
    char c;
    for(i=0;i<n;i++){
        c=*(p+i);
        if(c=='('||c=='['||c=='{'){
            push(c);
        }
        else if(c==')'||c==']'||c=='}'){
            char left=pop();
            if(!match(left,c)||left=='#'){
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