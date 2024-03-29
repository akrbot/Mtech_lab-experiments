#include<stdio.h>
#include<stdlib.h>
//create structure for linked list node 
//consist of data and next
//next itself is a structure node (acts like kind of recurssion)
struct node{
    int data; 
    struct node *next;// next node 
}*head;

void create_linked_list();
void insert_elemnt(int n,int ele);
void traverse_linked_list();

void main(){
    create_linked_list();
    int n,ele;
    printf("ele n \n");
    scanf("%d%d",&n,&ele);
    insert_elemnt(n,ele);
    traverse_linked_list();
}
void create_linked_list(){
    struct node *new_node, *prev_node;
    int data;
    head =(struct node*) malloc(sizeof(struct node));
    if (head == NULL){
        printf("unable to locate memory");
        return;
    }
    printf("list\n");
    scanf("%d",&data);
    if(data == -999) {
        head = NULL;
        return;
    }
    head->data = data;
    head->next = NULL;
    
    prev_node = head;
    while(1){
        scanf("%d",&data);
        if(data == -999) break;
        new_node = (struct node*) malloc(sizeof(struct node)); 
        if(new_node == NULL){
            printf("unable to allocate memory");
            break;
        }
        new_node->data = data; //store data in data field of new node
        new_node->next = NULL; //new nodes nxt ptr points to NULL
        
        prev_node->next = new_node; //prev nodes nxt ptr points to new node
        prev_node = new_node; //make prev node as new node for the nxt iteration
    }
}

void insert_elemnt(int n,int ele)
{
    struct node *currnode = head;
    while(currnode!=NULL){
        if(currnode->data == n){
            struct node *newnode;
            newnode = (struct node*) malloc(sizeof(struct node));
            struct node *temp;
            temp = currnode->next;  //temporarily store next node ptr
            newnode->data = ele;   //create newnode put data
            newnode->next = temp; //and nxt node ptr as temp  
            currnode->next = newnode;
        }
        currnode = currnode->next;
    }
}

void traverse_linked_list(){
    struct node *temp = head;
    if(head == NULL) printf("underflow");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}