#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = 0,rear = 0;
int isEmpty(){
    return(front == rear);
}
int isFull(){
    return((rear + 1) % MAX == front);
}
void enqueue(int n){
    if(isFull()){
        printf("queue overflow\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = n;
}
int dequeue(){
    if(isEmpty()){
        printf("queue underflow\n");
        return -1;
    }
    front = (front + 1) % MAX;
    return queue[front];
}

int main(void){
    int i,x;
    printf("請先輸入三個數字:");
    for(i=0;i<3;i++){
        scanf("%d",&x);
        enqueue(x);
    }
    printf("輸出:");
    for(i=0;i<2;i++){
        int val=dequeue();
        if(val!=-1){
            printf("%d ",val);
        }
    }
    printf("\n再輸入三個數字:");
    for(i=0;i<3;i++){
        scanf("%d",&x);
        enqueue(x);
    }
    printf("剩下的元素:");
    while(!isEmpty()){
        printf("%d ",dequeue());
    }
    printf("\n");
    return 0;
}