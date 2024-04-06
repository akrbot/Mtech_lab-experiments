#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_LEN 100
#define MAX_TOKEN_LEN 20
struct BTnode{
    char data;
    struct BTnode *leftNode;
    struct BTnode *rightNode;
};
struct BTnode *getNode(char value){
    struct BTnode *newNode = malloc(sizeof(struct BTnode));
    newNode->data = value;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;
    return newNode;
}

struct BTnode *initTree(struct BTnode *rootNode, char value){
    if(rootNode == NULL)
        return getNode(value);
}



// Function to print the preorder traversal
void preorder(struct BTnode* rootNode) {
    if (rootNode == NULL) return;
    printf("%c, ", rootNode->data);
    preorder(rootNode->leftNode);
    preorder(rootNode->rightNode);
}

// Function to search for a node with given data value
struct BTnode* searchNode(struct BTnode* root, char data) {
    // If the root is NULL or the root node's data matches the target data, return the root
    if (root == NULL || root->data == data)
        return root;

    // Recursively search in the left and right subtrees
    struct BTnode* leftSearch = searchNode(root->leftNode, data);
    struct BTnode* rightSearch = searchNode(root->rightNode, data);

    // If the target node is found in the left subtree, return it
    if (leftSearch != NULL)
        return leftSearch;

    // If the target node is found in the right subtree, return it
    if (rightSearch != NULL)
        return rightSearch;

    // If the target node is not found in either subtree, return NULL
    return NULL;
}

struct BTnode *insert(struct BTnode *rootNode, char value, char left, char right){
    // struct BTnode* result = searchNode(rootNode, value);
    struct BTnode* result = searchNode(rootNode, value);
    printf("Found: %c\n", result->data);
    if(left != '0')
        result->leftNode = initTree(result->leftNode, left);
    if(right != '0')
        result->rightNode = initTree(result->rightNode, right);
    return rootNode;
}

int splitString(char* input,char* tokens[]){
    int token_count = 0;
    char* token = strtok(input, " ");
    while(token != NULL && token_count < MAX_TOKEN_LEN){
        tokens[token_count++] = token;
        token = strtok(NULL, " ");
    }
    return token_count; 
}

int main(){
    char input[MAX_INPUT_LEN];
    char* tokens[MAX_TOKEN_LEN];
    struct BTnode *rootNode = NULL;
    while(1){
        fgets(input, sizeof(input), stdin);
        if(input[strlen(input)-1] == '\n') 
            input[strlen(input)-1] = '\0';
 
        int token_count = splitString(input, tokens);
        if (strcmp(tokens[0], "-999") == 0) break; 

        if (token_count == 2){
            rootNode = initTree(rootNode, tokens[0][0]);
            continue;
        }
        char value = tokens[0][0];
        char left;
        char right;
        if (strcmp(tokens[1], "NULL") == 0) left = '0';
        else left = tokens[1][0];
        if (strcmp(tokens[2], "NULL") == 0) right = '0';
        else right = tokens[2][0];

        rootNode = insert(rootNode, value, left, right);
        
    }
    if(rootNode == NULL) {
        printf("Empty Tree\n");
        return 0;
    }
    printf("Pre-order Traversal:");
    preorder(rootNode);
    return 0;
}