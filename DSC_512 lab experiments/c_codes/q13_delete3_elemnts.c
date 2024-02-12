#include<stdio.h>
#include<stdlib.h>

//doubly linked list with prev an next pointers
struct node{
    int data;
    struct node *prev;
    struct node *next;
//declare global variable for head and end of node
}*head, *end;


// 3 functions declarations
//one to create linked list thn to 
//delete 3 elements and display it backwards
void create_doubly_ll();
int delete3_elemnts();
void traverse_bw();

//main fn 
void main(){
    create_doubly_ll();
    //delete fn return a 0 or 1 value based on successful deletions or not
    int f = delete3_elemnts();
    //only if f = 1 that is successfully deleted 3 elemnts then
    //(few cases for unsuccessful  deletion eg:- if only less than 3 elements in linked list)
    //print the display list backwards
    if(f) traverse_bw();
}

//fn to create a linked list
void create_doubly_ll(){
    struct node *curr_node,*new_node;
    int data;
    scanf("%d",&data);
    //receive the first input and checks if its -999
    //if -999 means stop adding elements to link list
    //but here first input is -999 so make head = NULL and return
    //no need to execute rest of the function
    //so that we can do underflow
    if(data == -999){
        head == NULL;
        return;
    }
    //if some other values in data other than -999
    //allocate memory for head node start of link list
    head = (struct node*)malloc(sizeof(struct node));
    //if head == NULL means could not allocate memory due to some error
    // and return since no need to execute  rest of the function 
    if (head == NULL){
        printf("memory allocation error");
        return;
    }
    //after allocation make
    //head node's data as data
    //head node's prev ptr as NULL
    //head node's next ptr as NULL
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    
    //here is loop starts for adding nodes
    //first step is to make current node as head
    //and run a while 1 loop
    curr_node = head;
    while(1){
        //check if input data is -999
        //if yes the break no need to execute rest of loop
        //because -999 means stop adding any more nodes
        scanf("%d",&data);
        if (data == -999) break;
        
        //input data is not -999
        //then create a new-node allocate memory
        //print error if unable to allocate memory
        new_node = (struct node*)malloc(sizeof(struct node));
        if (new_node == NULL){
            printf("memory allocation error");
            return;
        }
        //make new_node's data as data(now got as input)
        //new_node's prev pointer as curr_node (since new_node will be added after curr_node)
        //new_node's next pointer as NULL (since we dont know the next node yet)
        new_node->data = data;
        new_node->prev = curr_node;
        new_node->next = NULL;
        
        //make curr_node's next pointer as new_node (since new nodes is added after curr_node)
        curr_node->next = new_node;
        //make curr_node as new_node for next iteration
        curr_node = new_node;
    }
    //when the loop is finished executing
    //last node will be curr_node so store it in end since its the end of linked list;
    end = curr_node;
}

//function traverse linked list backwards and display data
void traverse_bw(){
    //declare a curr_node variable
    struct node *curr_node;
    //check if head or end == NULL this means user hav entered less than 3 elements
    if(head == NULL || end == NULL){
        printf("Error!! Underflow, Minimum 3 elements are required.");
        return;
    }
    //if not head or end is null
    //then make curr_node as end
    curr_node = end;
    //till current_node is not NULL execute loop
    while(curr_node != NULL){
        // print the current nodes data
        printf("%d ",curr_node->data);
        //make curr_node as curr_nodes previous therfore 
        //we can access previous node in next iteration of loop
        curr_node = curr_node->prev;
    }
    
}

//function for deleting 3 elemnts from back of linked list
// fn returns 1 for successful deletion and 0 for unsuccessful deletion
int delete3_elemnts(){
    //declare variables for nodes
    struct node *curr_node, *temp;
    //is Flag variable for return 0 or 1 
    int res = 1;
    //if head == NULL that means we cant delete any elements since no elements are entered 
    //this happens if first input is -999
    if (head == NULL){
        printf("Error!! Underflow, Minimum 3 elements are required.");
        return 0;
    }
    //make curr node as end for loop to start
    curr_node = end;
    for(int i=0;i<3;i++){
        //before i becomes 3 if curr_node is NULL the that means 
        //1 or 2 elements is only added in this case
        if (curr_node == NULL){
            printf("Error!! Underflow, Minimum 3 elements are required.");
            return 0;
        }
        //temp storing curr_node value
        temp = curr_node;
        //jump to previous node and continue loop 
        //here it does 3 times
        //before doing 3 times if curr node becomes NULL that means there is no prev node to jump
        //that means only 1 or 2 elemnts is input by user thts why we check for if curr_node is NULL
        curr_node = curr_node->prev;
    }
    //this is for checking a edge case condition
    //if exactly 3 elements are entered by user curr_node will be NULL but the loops breaks before that because i will be 3
    //so we check again here curr_node ==NULL then print NULL as per test case
    // and make res as 0 since deletion is unsuccessful
    if(curr_node == NULL) {
        res = 0;
        printf("NULL");
    }
    //if not then make the curren_node as  end
    else{
        end = curr_node;
        end->next = NULL;
    }
    //here look at line 144 where we temporarily store curr_node in temp
    //after the loop execution completes temp will be having the node after current node
    //whatever after current_node is deleted
    while(temp != NULL){
        struct node *next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    return res;
}


