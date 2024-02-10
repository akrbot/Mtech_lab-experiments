#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head,*end;


void create_doubly_ll();
void traverse_bw();
int  insert3_elemnts();

void main(){
    create_doubly_ll();
    int f = insert3_elemnts();
    if(f) traverse_bw();
}

void create_doubly_ll(){
    struct node *curr_node,*new_node;
    int data;
    scanf("%d",&data);
    if(data == -999){
        head = NULL;
        return;
    }
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        printf("memory allocation error");
        return;
    }
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    
    curr_node = head;
    while(1){
        scanf("%d",&data);
        if (data == -999) break;
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data =data;
        new_node->prev = curr_node;
        new_node->next = NULL;
        
        curr_node->next = new_node;
        curr_node = new_node;
    }
    end = curr_node;
}

void traverse_bw(){
    struct node *curr_node;
    if(head == NULL){
        printf("underflow");
        return;
    }
    curr_node = end;
    while(curr_node != NULL){
        printf("%d ",curr_node->data);
        curr_node = curr_node->prev;
    }
}

int insert3_elemnts(){
    int data;
    struct node *new_node,*temp;
    for(int i=0;i<3;i++){
        if(scanf("%d",&data) != 1){
            printf("Error!! Three elements must be inserted\n");
            return 0;
        }
        new_node = new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
        if(head == NULL){
            head=end=new_node;
            continue;
        } 
        temp = head;
        head->prev = new_node;
        head->next = temp;
        head = new_node;

    }
    return 1;
}