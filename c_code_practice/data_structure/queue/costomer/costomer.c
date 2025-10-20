#include <stdio.h>
#define MAX 200
int queue[MAX];
int front=0, rear=-1;
void enqueue(int n){
    if(rear==MAX-1){
        printf("queue overflow");
        return;
    }
    queue[++rear]=n;
}
int dequeue(){
    if(front>rear){
        printf("queue underflow");
        return -1;
    }
    return queue[front++];
}
int isEmpty(){
    return (front>rear);
}
int main(void){
    int i,x;
    printf("請輸入五位顧客編號:");
    for(i=0;i<5;i++){
        scanf("%d",&x);
        enqueue(x);
    }
    printf("已結帳顧客:\n");
    for(i=0;i<2;i++){
        int val=dequeue();
        if(val!=-1){
            printf("%d ",val);
        }
    }
    printf("\n請再輸入兩位顧客編號:");
    for(i=0;i<2;i++){
        scanf("%d",&x);
        enqueue(x);
    }
    printf("剩下顧客為:\n");
    while(!isEmpty()){
        printf("%d ",dequeue());
    }
    return 0;
}