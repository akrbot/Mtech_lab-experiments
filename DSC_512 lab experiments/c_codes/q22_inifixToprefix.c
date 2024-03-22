#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for the stack node
struct StackNode {
    char data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createNode(char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return !root;
}

// Function to push an element onto the stack
void push(struct StackNode** root, char data) {
    struct StackNode* newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
}

// Function to pop an element from the stack
char pop(struct StackNode** root) {
    if (isEmpty(*root))
        return '$'; // Return a special character indicating empty stack
    struct StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Function to get the top element of the stack without popping
char peek(struct StackNode* root) {
    if (isEmpty(root))
        return '$'; // Return a special character indicating empty stack
    return root->data;
}

// Function to check if a character is an operand
int isOperand(char ch) {
    return isalnum(ch);
}

// Function to check precedence of operators
int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char* infix, char* prefix) {
    int i, k;
    char ch;
    struct StackNode* stack = NULL;

    // Reverse the infix expression
    int len = strlen(infix);
    for (i = 0, k = len - 1; i < k; i++, k--) {
        char temp = infix[i];
        infix[i] = infix[k];
        infix[k] = temp;
    }

    for (i = 0, k = 0; infix[i] != '\0'; i++) {
        // If operand, add it to the prefix expression
        if (isOperand(infix[i]))
            prefix[k++] = infix[i];
        // If ')' pop and add to prefix until '(' is encountered
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                prefix[k++] = pop(&stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(&stack);
        }
        // If operator, pop and add to prefix until precedence is higher or stack is empty
        else {
            while (!isEmpty(stack) && precedence(infix[i]) < precedence(peek(stack)))
                prefix[k++] = pop(&stack);
            push(&stack, infix[i]);
        }
    }

    // Pop remaining operators from the stack and add to prefix
    while (!isEmpty(stack))
        prefix[k++] = pop(&stack);

    prefix[k] = '\0'; // Null terminate the prefix expression
}

int main() {
    char infix[100], prefix[100];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    // Reverse the prefix expression
    int len = strlen(prefix);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
