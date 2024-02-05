#include<stdio.h>
void delete_element(int arr[], int *size, int pos){
    //edge case if postion to delete is 0 or greater than size
    if (pos == 0 || pos>*size) {
        printf("out of bound");
        return;
    }
    //start from postion and left shift element
    for(int i=pos-1;i<*size;i++){
        arr[i]=arr[i+1];
    }
    //reduce size by 1 and print new array after deletion
    (*size)--;
    for(int i=0;i<*size;i++) printf("%d ",arr[i]);

    return;
}

void main(){
    int n,pos;
    //input no of elements
    scanf("%d",&n);
    int arr[n];
    //input ekement
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //input postion to delete
    scanf("%d",&pos);
    //delete_fn call
    delete_element(arr,&n,pos);
}