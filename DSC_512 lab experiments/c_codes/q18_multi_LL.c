#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 50

//struct for student
struct student{
    char name[MAX_LEN];
    int marks;
    
    struct student* next_by_names;
    struct student* next_by_marks;
};


void insert_student(struct student** head_by_marks, struct student** head_by_names, char* name, int marks);
void display_by_marks(struct student* head_by_marks);
void display_by_names(struct student* head_by_names);
int  contains_only_apha(const char* str);

void main(){
    struct student* head_by_marks = NULL;
    struct student* head_by_names = NULL;
    int count = 0;
    char name[MAX_LEN];
    int marks;    
    while(1){
        if(scanf("%49[^\n]",name)!=1) break;
        getchar();
        if(strcmp(name,"-999") == 0) break;
        if(contains_only_apha(name) == 0) {
            printf("Input Error!!! Name of a student should only have alphabets.");
            return;
        }
        int val = scanf("%d",&marks);
        if (val == 0){
            printf("Input Error!!! Marks Missing");
            return;
        }
        if(marks<0){
            printf("Marks cannot be negative.");
            return;
        }
        getchar();
        insert_student(&head_by_marks, &head_by_names, name, marks);
        count ++ ;  
    }
    if(count == 0){
        printf("You must enter atleast one student");
        return;
    }
    printf("Descending order of Marks: ");
    display_by_marks(head_by_marks);
    printf("\nAlphabetical Order: ");
    display_by_names(head_by_names);


}

void insert_student(struct student** head_by_marks, struct student** head_by_names, char* name, int marks){
    //create new student node
    struct student* new_student = (struct student*)malloc(sizeof(struct student));
    
    strcpy(new_student->name, name);
    new_student->marks = marks;
    new_student->next_by_marks = NULL;
    new_student->next_by_names = NULL;
    
    struct student* prev_by_marks = NULL;
    struct student* curr_by_marks = *head_by_marks;
    while(curr_by_marks  != NULL && curr_by_marks->marks > marks){
        prev_by_marks = curr_by_marks;
        curr_by_marks = curr_by_marks->next_by_marks;
    }
    if(prev_by_marks == NULL){
        new_student->next_by_marks = *head_by_marks;
        *head_by_marks = new_student;
    }
    else{
        new_student->next_by_marks = prev_by_marks->next_by_marks;
        prev_by_marks->next_by_marks = new_student;
    }
    
    struct student* prev_by_names = NULL;
    struct student* curr_by_names = *head_by_names;
    while(curr_by_names != NULL && (strcmp(curr_by_names->name,name)<0 || (strcmp(curr_by_names->name,name) == 0 && curr_by_names->marks >= marks) )){
        prev_by_names = curr_by_names;
        curr_by_names = curr_by_names->next_by_names;
    }
    if(prev_by_names == NULL){
        new_student->next_by_names = *head_by_names;
        *head_by_names = new_student;
    }
    else{
        new_student->next_by_names = prev_by_names->next_by_names;
        prev_by_names->next_by_names = new_student;
    }
}


void display_by_marks(struct student* head_by_marks){
    struct student* current = head_by_marks;
    while(current != NULL){
        printf("%s %d, ",current->name,current->marks);
        current = current->next_by_marks;
    }
}

void display_by_names(struct student* head_by_names){
    struct student* current = head_by_names;
    while(current != NULL){
        printf("%s %d, ",current->name,current->marks);
        current = current->next_by_names;
    }
}

int contains_only_apha(const char* str){
    while(*str){
        if(!isalpha(*str) && *str != ' ') return 0;
        str++;
    }
    return 1;
}