#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head,*end;

int create_doubly_ll();
void traverse_fw();
int insert_after_24(int size, int element);

void main(){
    int count = create_doubly_ll();
    int element;
    scanf("%d",&element);
    insert_after_24(count,element);
    traverse_fw();
}



void traverse_fw(){
    struct node *temp = head;
    if(head == NULL) printf("underflow");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


int create_doubly_ll(){
    struct node *prev_node,*new_node;
    int data;
    int count = 0;//variable to store number of total nodes
    end = NULL;
    scanf("%d",&data);
    if(data == -999){
        head = NULL;
        return 0;
    }
    head = (struct node*) malloc(sizeof(struct node));
    if(head == NULL){
        printf("memory allocation error");
        return 0;
    }
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    count++;
    prev_node = head;
    while(1){
        scanf("%d",&data);
        if(data == -999) break;
        new_node = (struct node*) malloc(sizeof(struct node));
        if(new_node == NULL){
            printf("memory allocation error");
            return 0;
        }
        new_node->data = data;
        new_node->prev = prev_node;
        new_node->next = NULL;
        
        prev_node->next = new_node;
        prev_node = new_node;
        count++;
    }
    end = prev_node;
    return count;
}

int insert_after_24(int size,int element){
    //find nodes with data 24 and store it in an array;
    struct node *node_arr[size];
    struct node *temp = head,*new_node;
    int i = 0;
    while(temp != NULL){
        if(temp->data == 24) {
            node_arr[i] = temp;
            i++;
        }
        temp = temp->next;
    }
    //if 24 is not found i == 0 so do nothin just return
    if(i == 0) {
        printf("24 not found");
        return 0;
    }
    //if i>=2 means more than 1 occurrence of 24
    //so ask for input to insert after the given index
    else if(i >= 2){
        printf("%d occurrence of 24 found. Where should the insertion occur?",i);
        int input;
        scanf("%d",&input);
        i = input;
    }
    i = i-1;
    //create new node and insert after 24
    new_node = (struct node*) malloc(sizeof(struct node));
    temp = node_arr[i]->next;
    new_node->data = element;
    new_node->next = temp;
    new_node->prev = node_arr[i];
    node_arr[i]->next = new_node;

}

