#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Queue{
    struct Node* front;
    struct Node* rear;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}


void initQueue(struct Queue* queue){
    queue->front = queue->rear = NULL;
}

int isEmpty(struct Queue* queue){
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int data){
    struct Node* node = newNode(data);
    if(isEmpty(queue)){
        queue->front = queue->rear = node;
    }
    else{
        queue->rear->next = node;
        queue->rear = node;
    }
}

int dequeue(struct Queue* queue){
    if(isEmpty(queue)){
        printf("Queue underflow");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    free(temp);
    return data;
}

void displayQueue(struct Queue* queue){
    struct Node* current = queue->front;
    printf("\nContents of the remaining queue: ");
    while(current != NULL){
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}


int main(){
    struct Queue queue;
    initQueue(&queue);
    int data;
    int count = 0;
    while(1){
        scanf("%d",&data);
        if(data == -999) break;
        enqueue(&queue, data);
        count ++;
    }
    if(count < 4){
        printf("Minimum 4 elements must be entered.");
        return 0;
    }
    printf("Element at the front of the queue: %d\n",queue.front->data);
    printf("Remove and display three elements");
    for(int i=0;i<3;i++){
        printf(" %d",dequeue(&queue));
    }
    
    displayQueue(&queue);
    return 0;
}
