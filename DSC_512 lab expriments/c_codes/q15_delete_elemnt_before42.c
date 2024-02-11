#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
}*head,*end;

int create_doubly_ll();
void traverse_fw();
int delete_after_42(int size);

void main(){
    int count = create_doubly_ll();
    int flag = delete_after_42(count);
    if(flag) traverse_fw();
}

void traverse_fw(){
    struct node *temp = head;
    if(head == NULL) printf("underflow");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int create_doubly_ll(){
    struct node *prev_node, *new_node;
    int data;
    int count = 0;// for storing number of nodes
    end = NULL;
    scanf("%d",&data);
    if(data == -999){
        head = NULL;
        return 0;
    }
    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL){
        printf("memory allocation error");
        return 0;
    }
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    
    prev_node = head;
    while(1){
        scanf("%d",&data);
        if(data == -999) break;
        new_node = (struct node*)malloc(sizeof(struct node));
        if (new_node == NULL){
            printf("memory allocation error");
            return 0;
        }
        new_node->data =data;
        new_node->prev = prev_node;
        new_node->next = NULL;
        
        prev_node->next = new_node;
        prev_node = new_node;
        count ++;
    }
    end = prev_node;
    return count;
}

int delete_after_42(int size){
    //find nodes with data 42 and store it in an array;
    struct node *node_arr[size];
    struct node *temp = head;
    int i = 0;
    while(temp != NULL){
        if(temp->data == 42){
            node_arr[i] = temp;
            i++;
        }
        temp = temp->next;
    }
    //if 42 is not found i == 0 so do nothin just return
    if(i == 0){
        printf("At least one element must be 42");
        return 0;
    }
    //if i>=2 means more than 1 occurence of 42
    //so ask for user input to delete before given index;
    else if (i>=2){
        printf("%d occurrence of 42 found. Where should the deletion occur?\n",i);
        int input;
        scanf("%d",&input);
        i = input;
    }
    i = i-1;
    //delete node before 42
    temp = node_arr[i]->prev;
    if(temp == NULL){
        printf("No element before 42");
        return 0;
    }
    //if node to be deleted is head then make head point to next node
    //delete node and free memory
    if (temp == head){
        head = temp->next;
        head->prev = NULL;
        free(temp);
        return 1;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
    return 1;
}