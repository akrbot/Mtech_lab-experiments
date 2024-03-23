#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

struct Node{
    char data;
    struct Node* next;
};

struct Stack{
    struct Node* top;
};


struct Node* newNode(char data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL){
        printf("memory alloctaion failure");
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
        printf("Stack isEmptypop");
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
        printf("Stack isEmptypeek");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}


int precedence(char op){
    if((op == '+') || (op == '-')) return 1;
    if((op == '*') || (op == '%') || (op == '/')) return 2;
    if (op == '^') return 3;
    
    return -1;
}

void displayStack(struct Stack* stack){
    struct Node* temp = stack->top;
    while(temp != NULL){
        printf("%c ",temp->data);
        temp = temp->next;
    }
}

void infixToPrefix(char* infix, char* prefix){
    int i,k;
    char ch;
    struct Stack stack;
    initStack(&stack);
    int len = strlen(infix);
    for(i = 0,k=len-1;i<k;i++,k--){
        char temp = infix[i];
        infix[i] = infix[k];
        infix[k] = temp;
    }

    
    for(i=0,k=0; infix[i] != '\0';i++){
        
        if(infix[i] == ' ') continue;
        if(isalnum(infix[i])) prefix[k++] = infix[i];
        else if(infix[i] == ')'){
            while(!isEmpty(&stack) && peek(&stack)!='('){
                prefix[k++] = pop(&stack);
            }
            if(!isEmpty(&stack) && peek(&stack) != '('){
                printf("invalid Expression");
                return;
            }
            //else pop(&stack);
           
        }
        else{
            while(!isEmpty(&stack) && precedence(infix[i]) < precedence(peek(&stack))){
                prefix[k++] = pop(&stack);
            } 
            push(&stack, infix[i]);
        }
    }
    while(!isEmpty(&stack)){
        if(peek(&stack) == '(') pop(&stack);
        else prefix[k++] = pop(&stack);
    }
    prefix[k] = '\0';
}

int checkExp(char* infix){
    int i = 0;
    while(infix[i]!= '\n'){
        if(isalnum(infix[i])) return 1;
        i++;
    }
    return 0;
}


void main(){
    char infix[100], prefix[100];
    fgets(infix,sizeof(infix), stdin);
    if(infix[0] == '\n'){
        printf("No input detected");
        return;
    }
    int res = checkExp(infix);
    if(res == 0){
        printf("Invalid Input");
        return;
    }

    infixToPrefix(infix, prefix);
    int len = strlen(prefix);
    int i,k;
    for(i = 0,k=len-1;i<k;i++,k--){
        char temp = prefix[i];
        prefix[i] = prefix[k];
        prefix[k] = temp;
    }
    i = 0; 
    while(prefix[i]!='\0'){
        printf("%c ",prefix[i++]);
    }
    return;
}
