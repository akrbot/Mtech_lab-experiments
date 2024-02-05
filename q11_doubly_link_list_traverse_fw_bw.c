#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head,*end;

void create_doubly_ll();
void traverse_fw();
void traverse_bw();

void main(){
    create_doubly_ll();
    traverse_fw();
    printf("\n");
    traverse_bw();
}

void create_doubly_ll(){
    struct node *prev_node,*new_node;
    int data;
    end = NULL;
    scanf("%d",&data);
    if(data == -999){
        head = NULL;
        return;
    }
    head = (struct node*) malloc(sizeof(struct node));
    if(head == NULL){
        printf("memory allocation error");
        return;
    }
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    
    prev_node = head;
    while(1){
        scanf("%d",&data);
        if(data == -999) break;
        new_node = (struct node*) malloc(sizeof(struct node));
        if(new_node == NULL){
            printf("memory allocation error");
            return;
        }
        new_node->data = data;
        new_node->prev = prev_node;
        new_node->next = NULL;
        
        prev_node->next = new_node;
        prev_node = new_node;
    }
    end = prev_node;
}

void traverse_fw(){
    struct node *temp = head;
    if(head == NULL) printf("underflow");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void traverse_bw(){
    struct node *temp = end;
    if(end == NULL) printf("underflow");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
}