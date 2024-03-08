#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head, *end;

void create_cc_ll();
void delete_element();
void delete_and_display_ll();

void main(){
    create_cc_ll();
    delete_and_display_ll();
}

void create_cc_ll(){
    struct node *new_node, *prev_node;
    int data;
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
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
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL){
            printf("memory allocation error");
            return;
        }
        new_node->prev = prev_node;
        new_node->data = data;
        new_node->next = NULL;
        
        prev_node->next =new_node;
        prev_node = new_node;
    }
    
    end = prev_node;
    head->prev = end;
    end->next = head;
}

void delete_and_display_ll(){
    struct  node *del_node = end, *temp = head;
    if(head == NULL) {
        printf("Underflow !!! Empty Linked list");
        return;
    }
    if (del_node == head){
        printf("Empty Linked List !!!");
        return;
    }
    //delete last node
    end = del_node->prev;
    del_node->next->prev = del_node->prev;
    del_node->prev->next = del_node->next;
    
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp!=head);
}
