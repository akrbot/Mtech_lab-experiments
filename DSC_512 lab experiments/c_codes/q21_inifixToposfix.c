#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>


struct Node{
    char data;
    struct Node* next;
};

struct Stack{
    struct Node* top;
};


struct Node* newNode(char data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if(node == NULL){
        printf("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void initStack(struct Stack* stack){
    stack->top = NULL;
}

bool isEmpty(struct Stack* stack){
    return stack->top == NULL;
}

void push(struct Stack* stack,char data){
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}


char pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

char peek(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack isEmpty");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

int precedence(char op){
    if((op == '+') || (op == '-')) return 1;
    if((op == '*') || (op == '%') || (op == '/')) return 2;
    if(op == '^') return 3;

    
    return 0;
}

void displayStack(struct Stack* stack){
    struct Node* temp = stack->top;
    while(temp != NULL){
        printf("%c ",temp->data);
        temp = temp->next;
    }
    printf("printed stack\n");
    
}

void infixToPostfix(char* infix, char* postfix){
    struct Stack stack;
    initStack(&stack);
    
    int i=0, j=0;
    while(infix[i] != '\n'){
        if(infix[i] == ' '){
            i++;
            continue;
        }
        
        if(isalnum(infix[i])){
            postfix[j++] = infix[i++];
   
        }
        
        else if(infix[i] == '('){
            push(&stack, infix[i++]);

        }
        
        else if(infix[i] == ')'){

            while(!isEmpty(&stack) && peek(&stack) != '('){
                postfix[j++] = pop(&stack);
    
            }
            
            if(!isEmpty(&stack) && peek(&stack) != '('){
                printf("Invalid Expression\n");
                exit(EXIT_FAILURE);
            }
            else pop(&stack);
            i++;
        }
        
        else{

            while(!isEmpty(&stack) && precedence(infix[i]) <= precedence(peek(&stack))){
                postfix[j++] = pop(&stack);

            }
            push(&stack,infix[i++]);
        }
        //displayStack(&stack);
    }
    
    while(!isEmpty(&stack)){
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
    
}

int checkExp(char* infix){
    int i = 0 ;
    while(infix[i] != '\n'){
        if(isalnum(infix[i])) return 1;
        i++;
    }
    return 0;
}

void main(){
    char infix[100],postfix[100];
    fgets(infix,sizeof(infix) , stdin);
    if (infix[0] == '\n'){
        printf("No input detected");
        exit(EXIT_FAILURE);
    }
    int res = checkExp(infix);
    if(res == 0){
        printf("Invalid Input");
        exit(EXIT_FAILURE);
    }
    infixToPostfix(infix, postfix);
    int i = 0;
    while(postfix[i]!='\0'){
        printf("%c ",postfix[i++]);
    }
    return;
}