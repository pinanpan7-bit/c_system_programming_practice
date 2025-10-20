#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void append(struct Node **head, int val){
    struct Node *temp = *head;
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL; 
    if(temp == NULL){
        *head = newNode;
        return;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        return;
    }
}

void printList(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void freeList(struct Node *head){
    struct Node *temp;
    while(head != NULL){
        temp = head->next;
        free(head);
        head = temp;
    }
}

struct Node* hasCycle(struct Node *head){
    struct Node *fast = head, *slow = head;
    struct Node *ptr1 = NULL, *ptr2 = head;
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            ptr1 = slow;
            while(ptr1 != ptr2){
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1;
        }
    }
    return NULL;
}

struct Node* getIntersectionNode(struct Node *headA, struct Node *headB){
    int lenA = 0, lenB = 0, sub = 0, i;
    struct Node *tempA = headA;
    struct Node *tempB = headB;
    while(tempA !=NULL){
        lenA++;
        tempA = tempA->next;
    }
    while(tempB != NULL){
        lenB++;
        tempB = tempB->next;
    }
    if(lenA>lenB){
        sub = lenA -lenB;
        for(i=0;i<sub;i++){
            headA = headA->next;
        }
    }
    else{
        sub = lenB - lenA;
        for(i=0;i<sub;i++){
            headB = headB->next;
        }
    }
    while(headA != NULL && headB != NULL){
        if(headA == headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;        
    }
    return NULL;
}

int main(void){
    int val;
    struct Node *head = NULL;
    printf("請輸入一個陣列 (輸入 -1 停止): ");
    while(1){
        scanf("%d", &val);
        if(val == -1){
            break;
        }
            append(&head, val);
    }

    //make_cycle 
    printf("...製作列表環...\n");
    struct Node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    struct Node *cycle_start = head->next->next->next;
    tail->next = cycle_start;
    
    
    //has_cycle
    struct Node *temp = hasCycle(head);
    if(temp){
        printf("有環且環起點為: %d\n", temp->data);
    }
    else{
        printf("無環\n");
    }

    printf("...斷開列表環...\n");
    //destroy cycle
    tail->next = NULL; 
    printf("斷開列表環後，印出列表資料: ");
    printList(head);

    //make intersection
    struct Node *headA = NULL;
    struct Node *headB = NULL;
    printf("請輸入陣列一 (輸入 -1 停止): ");
    while(1){
        scanf("%d", &val);
        if(val == -1){
            break;
        }
            append(&headA, val);
    }
    printf("請輸入陣列二 (輸入 -1 停止): ");
    while(1){
        scanf("%d", &val);
        if(val == -1){
            break;
        }
            append(&headB, val);
    }
    
    struct Node *intersection = headA->next->next->next->next->next;
    struct Node *tailB = NULL;
    tailB = headB;
    while(tailB->next != NULL){
        tailB = tailB->next;
    }
    tailB->next = intersection;
    temp = getIntersectionNode(headA,headB);
    printf("陣列交會點位址為: %p\n", temp ? temp : NULL); 

    //destory interstion
    printf("...斷開intersection...\n");
    tailB->next = NULL;
    temp = getIntersectionNode(headA,headB);
    printf("陣列交會點位址為: %p\n", temp ? temp : NULL); 

    //free list
    freeList(head);
    printf("陣列已清除\n");    
    return 0;
}