#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("memory allocation error");
        return node;
    }
    
    node->data = data;
    node->next = NULL;
    return node;
}


struct Stack{
    struct Node* top;
};

void initStack(struct Stack* stack){
    stack->top = NULL;
}

int isEmpty(struct Stack* stack){
    return stack->top == NULL;
}

void push(struct Stack* stack,int data){
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

int peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("stack is empty\n");
        return 0;
    }
    return stack->top->data;
}

void displayStack(struct Stack* stack){
    struct Node* current = stack->top;
    while(current!= NULL){
        printf("%d ", current->data);
        current = current->next;        
    }

}

int pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("stack underFlow\n");
        return 0;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    return data;
}

void main(){
    struct Stack stack;
    initStack(&stack);
    int data;
    int count = 0;
    while(1){
        scanf("%d",&data);
        if (data == -999) break;
        push(&stack,data);
        count++;
    }
    if (count < 4){
        printf("Minimum 4 elements must be entered.\n");
        return;
    }
    printf("Peek: %d\n", peek(&stack));
    printf("POP operations: ");
    for(int i=0;i<3;i++){
        printf("%d ",pop(&stack));
    }
    printf("\n");
    printf("Contents of the remaining Stack: ");
    displayStack(&stack);
}
