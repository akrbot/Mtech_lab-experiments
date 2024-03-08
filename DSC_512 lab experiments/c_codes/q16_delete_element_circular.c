#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head,*end;

void create_cc_ll();
void delete_element();
void display_ll();

void main(){
    create_cc_ll();
    // display_ll();
    delete_element();
}

void create_cc_ll(){
    struct node *new_node, *prev_node;
    int data;
    head = (struct node*) malloc(sizeof(struct node));
    if (head == NULL){
        printf("memory allocation error");
        return;
    }
    scanf("%d",&data);
    if(data == -999){
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
    
    end = prev_node;
    head->prev = end;
    end->next = head;
}

void display_ll(){
    struct node *temp = end;
    if(head == NULL) printf("underflow");
    do{
        printf("%d ",temp->data);
        temp = temp->prev;
    }while(temp!=end);
}
    
    
void delete_element(){
    struct node *curr_node, *del_node = NULL, *temp;
    if(head == NULL){
        printf("Underflow !!! Minimum 3 elements must be entered.");
        return;
    }
    curr_node = head;
    int count = 0;
    do{
       if(count+1 == 3) del_node = curr_node;
       curr_node = curr_node->next;
       count ++;
    }while(curr_node != head);
    
    if(del_node == NULL) {
        printf("Underflow !!! Minimum 3 elements must be entered.");
        return;
    }
    if(end == del_node) end = del_node->prev;
    del_node->next->prev = del_node->prev;
    del_node->prev->next = del_node->next;
    display_ll();
}
