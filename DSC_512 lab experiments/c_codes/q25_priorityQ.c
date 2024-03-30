#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node* next;
};

struct Node* newNode(int data, int priority){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}


void enqueue(struct Node** head, int data, int priority){
    struct Node* start = (*head);
    struct Node* temp = newNode(data, priority);
    
    if((*head)->priority>priority){
        temp->next = *head;
        (*head) = temp;
    }
    else{
        while(start->next != NULL && start->next->priority < priority){
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

struct Node* dequeue(struct Node** head){
    struct Node* temp = *head;
    (*head) = (*head)->next;
    return temp;
}

void display(struct Node* head){
    int flag = 0;
    while(head != NULL){
        if (flag == 0 ){
            printf("%d-->%d",head->data,head->priority);
            flag = 1;
        }
        else printf(", %d-->%d ",head->data,head->priority);
        head = head->next;
    }
    printf("\n");
}


void main(){
    int p,d;
    
    int count = 1;
    scanf("%d",&d);
    if (d == -999){
        exit(EXIT_FAILURE);
    }
    scanf("%d",&p);
    struct Node* pq = newNode(d,p);
    
    while (1){
        scanf("%d",&d);
        if (d == -999) break;
        scanf("%d",&p);
        enqueue(&pq,d,p);
        count ++;
    }
    if(count < 5){
        printf("insert 5 elements");
        return;
    }
    display(pq);
    for (int i = 0;i<2;i++){
        struct Node* removed = dequeue(&pq);
        free(removed);
    }
    printf("After removing two elements: ");
    display(pq);
}