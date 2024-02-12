#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head;

void create_linked_list();
void delete_elemnt(int ele);
void traverse_linked_list();

void main(){
    
    int ele;
    create_linked_list();
    scanf("%d",&ele);
    delete_elemnt(ele);
}

void create_linked_list(){
    struct node *new_node, *prev_node;
    int data;
    head = (struct node*) malloc(sizeof(struct node));
    if (head == NULL){
        printf("memory allocation error");
        return;
    }
    scanf("%d",&data);
    if (data == -999){
        head = NULL;
        return;
    }

    head->data = data;
    head->next = NULL;
    head->prev = NULL;
    
    prev_node = head;
    while(1){
        scanf("%d",&data);
        if(data == -999) break;
        new_node = (struct node*) malloc(sizeof(struct node));
        if(new_node == NULL){
            printf("memory allocation error");
            return;
        }
        new_node->prev = prev_node;
        new_node->data = data;
        new_node->next = NULL;
        
        prev_node->next = new_node;
        prev_node = new_node;
    }
}

void traverse_linked_list(){
    struct node *temp = head;
    if (head == NULL)printf("underflow");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void delete_elemnt(int ele){
    struct node *curr_node, *prev_node, *del_node;
    if(head == NULL || head->next == NULL){
        printf("underflow");
        return;
    }
    curr_node = head;
    while(curr_node != NULL){
        if(curr_node->data == ele){
            del_node = curr_node;
        }
        curr_node = curr_node->next;
    }
    if(del_node->prev == NULL){
        printf("out of bound");
        return;
    }
    prev_node = del_node->prev;
    prev_node->next = del_node->next;
    traverse_linked_list();
}