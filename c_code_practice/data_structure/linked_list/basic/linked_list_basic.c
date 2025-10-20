#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void append(struct Node **head, int val){
    struct Node *newNode = malloc(sizeof(struct Node));
    struct Node *temp = *head;
    newNode->next = NULL;
    newNode->data = val;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node *head){
    struct Node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteNode(struct Node **head, int val){
    struct Node *curr = *head, *prev = NULL;
    while(curr != NULL){
        if(curr->data == val){
            if(curr == *head){
                *head = (*head)->next;
            }
            else{
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("節點不存在\n");
}

int main(void){
    int val;
    struct Node *head = NULL;
    printf("請輸入陣列(輸入-1結束): ");
    while(1){
        scanf("%d",&val);
        if(val == -1){
            break;
        }
        append(&head,val);
    }
    printf("存入內容為: ");
    printList(head);
    printf("要刪除的節點是: ");
    scanf("%d", &val);
    deleteNode(&head,val);
    printf("刪除後陣列為: ");
    printList(head);
    freeList(head);
    printf("已釋放記憶體空間\n");
    return 0;
}