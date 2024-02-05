#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head,*temp,*newnode,*ptr,*preptr;
    int key_element,i=1;
    int position = 0;
    int pos = 0;
    head=temp=preptr=ptr=newnode=0;
    while(1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        //while createing a new node add data and next ptr as NULL
        scanf("%d",&newnode->data);
        //new_nodes nxt ptr is NULL
        newnode->next = NULL;
        if(newnode->data==-999)
        {   
            free(newnode);
            break;
        }
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
    }

    //insert the element before which an element needs to be deleted
    scanf("%d",&key_element);
    int flag =0;
    ptr=head;
    preptr=NULL;
    //find the position of node to be deleted and its stored in pos
    while(ptr!=NULL){
        if(ptr->data==key_element){
           //whem ever match found store the position value
           pos = position;
           flag =1; 
           // no breaking is done coz we need to find multiple occurence
        } 
        //position is actually position count
        position++;
        preptr=ptr;
        ptr=ptr->next;
    }
    // pos == 0 ptr is NULL or first element is key elemnt
    if(pos == 0){
        printf("Out of bound");
        return 0;
    }
    //what if no element if found flag is used for checking
    if (flag == 0){
        printf("Not found");
        return 0;
    }

    temp=head;
    ptr=head;
    //this logic only work if key element is 3rd that is pos>=2
    if (pos>=2){
        while(i< pos-1){  
            temp=temp->next;
            i++;     
        }
        ptr=temp->next;
        temp->next=ptr->next;
        free(ptr);
    }
    if (pos == 1){
        //second element is key
        head = ptr->next;
        free(ptr);
    }
    // traversing and printing
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    return 0;
}