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
    if(*head == NULL){
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void freeList(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        temp = head->next;
        free(head);
        head = temp;
    }
    return;
}

struct Node *reverse(struct Node *prev, struct Node *curr, struct Node *next){
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* reverseBetween(struct Node **head, int m, int n){
    struct Node *dummy = malloc(sizeof(struct Node));
    struct Node *prevstart = dummy, *end = *head, *temp = NULL;
    dummy->data = 0;
    dummy->next = *head; 
    int i;
    for(i=1;i<m;i++){
        prevstart = prevstart->next;
    }
    for(i=1;i<n;i++){
        end = end->next;
    }
    //反轉起點和反轉起點下一個反轉
    struct Node *prev = prevstart->next;
    struct Node *start = prevstart->next;
    struct Node *curr = prevstart->next->next;
    struct Node *next = NULL, *afterend = end->next;
    while(curr != afterend){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    prevstart->next = end;
    start->next = afterend;
    if(m ==1){
        *head = end;
    }
    return *head;
}

int isPalindrome(struct Node *head){
    struct Node *fast = head, *slow = head;
    struct Node *ptr1 = head, *ptr2 = NULL, *temp = NULL;
    //只有一節點
    if(head->next == NULL || head == NULL){
        return 1;
    }
    while(fast != NULL && fast->next != NULL){
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    //even length
    if(fast == NULL){       
        temp->next = NULL;
    }
    //odd length
    else{
        temp = slow;
        slow = slow->next;
        temp->next = NULL;        
    }
    //反轉
    struct Node *prev = NULL, *curr = slow, *next = NULL;
    ptr2 = reverse(prev, curr, next);
    struct Node *ptr2Head = ptr2;
    //判斷回文
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data != ptr2->data){
            //再反轉接回
            prev = NULL, curr = ptr2Head, next = NULL;
            temp->next = reverse(prev, curr, next);
            return 0;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    prev = NULL, curr = ptr2Head, next = NULL;
    temp->next = reverse(prev, curr, next);
    return 1;
}

struct Node* oddEvenList(struct Node *head){
    struct Node *oddHead = head;
    struct Node *evenHead = head->next;
    struct Node *odd = oddHead;
    struct Node *even = evenHead;
    while(even != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next; 
    }
    odd->next = evenHead;
    return oddHead;
}

struct Node *reverseKgroup(struct Node **head, int k){
    struct Node *groupPrev = NULL;
    struct Node *groupStart = *head;
    struct Node *groupEnd = *head;
    struct Node *nextGroupStart = NULL;
    int i;

    while(groupEnd != NULL)
    {
        for(i=0; i < k - 1 && groupEnd != NULL; i++){
            groupEnd = groupEnd->next;
        }
        if (groupEnd == NULL){
            break;
        }
        nextGroupStart = groupEnd->next;
        groupEnd->next = NULL;
        struct Node *prev = nextGroupStart, *curr = groupStart, *next = NULL;
        struct Node *newHead = reverse(prev,curr,next);
        if(groupPrev == NULL){
            *head = newHead;
        }        
        else{
            groupPrev->next = newHead;
        }
        groupPrev = groupStart;
        groupStart = nextGroupStart;
        groupEnd = nextGroupStart;
    }
    return *head;
}

int main(void){
    struct Node *head = NULL;
    int val, m ,n, k;
    printf("請輸入一陣列: ");
    while(1){
        scanf("%d", &val);
        if(val == -1){
            break;
        }   
        append(&head, val);
    }
    printf("%s", isPalindrome(head) ? "這是迴文\n" : "這不是迴文\n");
    printf("輸入陣列為: ");
    printList(head);
    printf("請輸入以幾個為一組反轉: ");
    scanf("%d", &k);
    printf("翻轉後的結果為: ");
    printList(reverseKgroup(&head,k));
    printf("odd even list: ");
    printList(oddEvenList(head));
    printf("請輸入反轉起點: ");
    scanf("%d",&m);
    printf("請輸入反轉終點: ");
    scanf("%d",&n);
    reverseBetween(&head,m,n);
    printf("陣列反轉後: ");
    printList(head);
    freeList(head);
    printf("已釋放陣列\n");
    return 0;
}