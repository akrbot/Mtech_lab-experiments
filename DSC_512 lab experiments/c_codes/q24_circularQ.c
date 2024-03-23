#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 6

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull(){
    return((rear+1)%MAX_SIZE == front);
}

int isEmpty(){
    return(front == -1 && rear == -1);
}


void enqueue(int value){
    if(isFull()){
        printf("Out of Bound");
        exit(EXIT_FAILURE);
    }
    else if (isEmpty()){
        front = rear = 0;
    }
    else rear = (rear + 1)%MAX_SIZE;
    queue[rear] = value;
}

int dequeue(){
    int dqVal;
    if(isEmpty()){
        printf("Three elements should be deleted\n");
        exit(EXIT_FAILURE);
    }
    else if(front == rear){
        dqVal = queue[front];
        front = rear = -1;
    }
    else{
        dqVal =queue[front];
        front = (front + 1)%MAX_SIZE;
    }
    return dqVal;
}

void displayQueue(){
    int i = front;
    do{
        printf("%d ",queue[i]);
        i = (i+1)%MAX_SIZE;
    }while(i != (rear + 1)%MAX_SIZE);
    printf("\n");
}

void main(){
    int val;
    //enqueue element untill -999 is got error if more than 6 element (queue is full)
    while(1){
        scanf("%d",&val);
        if(val == -999) break;
        enqueue(val);
    }

    if (isEmpty()){
        printf("Empty Queue, Three elements should be deleted");
        return;
    }
    
    for(int i=0; i<3; i++){
        val = dequeue();
    }
    printf("Circular Queue: ");
    displayQueue();
    printf("FRONT = %d, REAR = %d\n",front,rear);
    printf("Contents of the remaining queue: ");
    displayQueue();
    for (int i=0;i<2;i++){
        scanf("%d",&val);
        enqueue(val);
    }
    displayQueue();
    printf("FRONT = %d, REAR = %d\n",front,rear);
}