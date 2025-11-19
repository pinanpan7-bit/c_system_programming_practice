#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void append(struct Node **head, int val){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    struct Node *temp = *head;
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
        printf("%d ", temp->data);
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

void reverseList(struct Node **head){
    struct Node *curr = *head, *prev = NULL, *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void deleteALL(struct Node **head, int target){
    struct Node *prev = NULL, *curr = *head;
    while(curr != NULL){
        if(curr->data == target){
            if(prev == NULL){
                *head = curr->next;
                free(curr);
                prev = NULL;
                curr = *head;
            }
            else{
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}

struct Node* findMiddle(struct Node *head){
    struct Node *fast = head, *slow = head;
    if(head == NULL){
        return NULL;
    }
    else{
        while(fast != NULL && fast->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
        }
        return slow;
    } 
}

void reversePrint(struct Node *head){
    if(head == NULL){
        return;
    }
    else{
        reversePrint(head->next);
        printf("%d ", head->data);
        return;
    }
}

int getLength_recursive(struct Node *head){
    int count;
    if(head == NULL){
        return 0;
    }
    else{
        return 1 + getLength_recursive(head->next);
    }
}

struct Node* mergeLists(struct Node *list1, struct Node *list2){
    struct Node *head = NULL;
    if(list1 == NULL){
        return list2;
    }
    else if(list2 == NULL){
        return list1;
    }
    else{
        if(list1->data <= list2->data){
            head = list1;
            head->next = mergeLists(list1->next, list2);
        }
        else if(list1->data >= list2->data){
            head = list2;
            head->next = mergeLists(list1, list2->next); 
        }
    }
    return head;
}

struct Node* intersection(struct Node *head1, struct Node *head2){
    struct Node *dummy = malloc(sizeof(struct Node));
    dummy->next = NULL;
    dummy->data = 0;
    struct Node *tail = dummy;
    while(head1 != NULL && head2 != NULL){
        if(head1->data == head2->data){
            struct Node *temp = malloc(sizeof(struct Node));
            temp->next = NULL;
            temp->data = head1->data;
            tail->next = temp;
            tail = temp;
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->data < head2->data){
            head1 = head1->next;
        }
        else if(head1->data > head2->data){
            head2 = head2->next;
        }
    }
    struct Node *inter = dummy->next;
    free(dummy);
    return inter;
}

void insertSorted(struct Node **sorted, struct Node *newNode){
    struct Node *prev = NULL, *curr = *sorted;

    if((*sorted == NULL) || (newNode->data < (*sorted)->data)){
        newNode->next = *sorted;
        *sorted = newNode;
    }
    else{
        prev = *sorted;
        curr = (*sorted)->next;
        while(curr != NULL){
            if(newNode->data < curr->data){
                newNode->next = curr;
                prev->next = newNode;
                return;
            }
            else if((curr->next == NULL) && (newNode->data > curr->data)){
                curr->next = newNode;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
}

struct Node* mergeAndSort(struct Node *list1, struct Node *list2){
    struct Node *head;
    struct Node *sorted = NULL;
    if(list1 == NULL){
        head = list2;
    }
    else if(list2 == NULL){
        head = list1;
    }
    else{
        head = list1;
        while(list1->next != NULL){
            list1 = list1->next;
        }
        list1->next = list2;
    }
    struct Node *curr = head, *next;
    while(curr != NULL){
        next = curr->next;
        insertSorted(&sorted,curr);
        curr = next;
    }
    return sorted;
}

int main(void){
    struct Node *head = NULL;
    int val = 0;
    printf("請輸入陣列(輸入-1為停止): ");
    while(1){
        scanf("%d", &val);
        if(val == -1){
            break;           
        }
        append(&head, val);
    }
    printf("輸入的陣列為: ");
    printList(head);
    printf("陣列長度為: %d\n",getLength_recursive(head));
    printf("中間元素為: %d\n", findMiddle(head)->data);
    reverseList(&head);
    printf("反轉後為: ");
    printList(head);
    printf("請輸入要刪除的數字: ");
    scanf("%d", &val);
    deleteALL(&head, val);
    printf("刪除後陣列為: ");
    printList(head);
    printf("反轉後: ");
    reversePrint(head);
    printf("\n");
    freeList(head);
    printf("已釋放陣列空間\n");

    struct Node *head1 = NULL;
    printf("請輸入陣列一(輸入-1為停止): ");
    while(1){
        scanf("%d", &val);
        if(val == -1){
            break;           
        }
        append(&head1, val);
    }

    struct Node *head2 = NULL;
    printf("請輸入陣列二(輸入-1為停止): ");
    while(1){
        scanf("%d", &val);
        if(val == -1){
            break;           
        }
        append(&head2, val);
    }
    printf("輸入的陣列是否有排序: ");
    scanf("%d",&val);
    struct Node *inter = intersection(head1,head2);
    struct Node *merge;
    if(val){
        printf("兩陣列交集為: ");
        printList(inter);
        if(inter ==NULL){
            printf("無交集\n");
        }
        printf("兩陣列串接後: ");
        merge = mergeLists(head1,head2);
        printList(merge);
    }
    else{
        printf("兩陣列串接後: ");
        merge = mergeAndSort(head1,head2);
        printList(merge);
    }
    freeList(merge);
    freeList(inter);
    printf("已釋放所有陣列空間\n");
    return 0;
}