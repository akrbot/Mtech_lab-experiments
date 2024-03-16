#include<stdio.h>
#include<stdlib.h>
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
    if(node == NULL){
        printf("Memory allocation failed");
        return node;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

bool isEmpty(struct Stack* stack){
    return stack->top == NULL;
}


void push(struct Stack* stack, char data){
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

void initStack(struct Stack* stack){
    stack->top = NULL;
}

char pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("stack underflow\n");
        return '0';
    }
    struct Node* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

bool isParenthesisMatched(char exp[]){
    struct Stack stack;
    initStack(&stack);
    int flag = 0;
    for(int i=0;exp[i] != '\n';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(&stack, exp[i]);
            flag = 1;
        }
        
        else if (exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            flag = 1;
            if (isEmpty(&stack))
                return false;
            
            char popped = pop(&stack);
            if ((exp[i] == ')' && popped != '(')||
                (exp[i] == ']' && popped != '[')||
                (exp[i] == '}' && popped != '{')) return false;
            
        }

    }
    if (flag == 0){
        printf("No Parenthesis found.");
        exit(EXIT_FAILURE);
    }
    return isEmpty(&stack);
}

int main(){
    char input[100];
    fgets(input,sizeof(input),stdin);
    if(isParenthesisMatched(input)) printf("Parenthesis Matched.");
    else printf("Parenthesis Mismatched.");
}
