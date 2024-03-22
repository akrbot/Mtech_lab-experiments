#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    int marks;
    char name[50];
    struct student* marknext;
    struct student* namenext;
};
           
           struct student * namehead;
        
            struct student * markhead;
            
    struct student * createstudent(char name[50],int marks)
    {
    struct student * newstudent;
    newstudent=(struct student*)(malloc(sizeof(struct student)));
    strcpy(newstudent->name,name);
     newstudent->marks=marks;
     newstudent->marknext =NULL;
     newstudent->namenext =NULL;
     
     return newstudent;
    
        }
        
     void insertbyname(struct student**head, struct student * newstudent)
        {
            if(*head==NULL|| strcmp((*head)->name,newstudent->name)>0)
            {
               newstudent->namenext=*head;
               *head=newstudent;
               
            }
            else
            {
                struct student* temp;
                temp=*head;
                while(temp->namenext != NULL && strcmp(temp->namenext->name,newstudent->name)<0)
                {
                    temp= temp->namenext;
                }
                newstudent->namenext =temp->namenext;
                temp->namenext =newstudent;
            }
            
             
        }
        
        
    void insertbymarks(struct student**head, struct student * newstudent)
        {
           if (*head==NULL|| ((*head)->marks < newstudent->marks))
           {
               newstudent->marknext =*head;
              *head =newstudent;
           }
           else if((*head)->marks==newstudent->marks && (strcmp((*head)->name,newstudent->name)<=0))
           
           {    newstudent->marknext =*head;
                *head =newstudent;
               
           }
           
           else
           { struct student* temp;
                temp =*head;
                
              while(temp->marknext!=NULL && (temp->marknext->marks > newstudent->marks || (temp->marknext->marks ==newstudent->marks &&strcmp(temp->marknext->name,newstudent->name)>0)))
              {
                  temp =temp->marknext;
              }
              newstudent->marknext =temp->marknext;
              temp->marknext=newstudent;
           }
               
        }
        
        void displaybyname(struct student * head){
        
         struct student* temp;
            temp=head;
            printf("\nAlphabetical Order: ");
            while(temp!=NULL)
            {printf("%s %d, ",temp->name,temp->marks);
            temp=temp->namenext;
                
            }
        }
        
        
        void display(struct student * head1){
        
         struct student* temp;
            temp=head1;
           printf("\nDecending order of Marks: ") ;
            while(temp!=NULL)
            {printf("%s %d, ",temp->name,temp->marks);
            temp=temp->marknext;
                
            }
            
            }
        
        int main()
        {
            struct student * newstudent;
            char name[50];
            int marks;
            printf("enter name: ");
            scanf("%49[^\n]",name);
            getchar();
            while(strcmp(name,"-999")!=0){
                printf("enter marks: ");
                scanf("%d",&marks);
                getchar();
             if(marks>=0)
             {
                
                newstudent = createstudent(name,marks);
                 insertbyname(&namehead,newstudent);
                 insertbymarks(&markhead,newstudent);
            }
            printf("enter name: ");
            scanf("%49[^\n]",name);
            getchar();
            }
            display(markhead);
            displaybyname(namehead);
            return 0;
        }
            


