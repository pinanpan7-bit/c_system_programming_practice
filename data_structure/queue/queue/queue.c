#include <stdio.h>
#define MAX 200
int queue[MAX];
int front=0;
int rear=-1;
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
int main(void){
    int i,n,x;
    printf("請輸入陣列長度:");
    scanf("%d",&n);
    printf("請輸入一陣列:\n");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }
    printf("輸出為:\n");
    for(i=0;i<n;i++){
        int val=dequeue();
        if(val!=-1){
            printf("%d\n",val);
        }
    }
    return 0;
}