#include<stdio.h>

void linear_search(int element, int arr[], int arr_size){
    int found_arr[arr_size];
    int c = 0;
    //itterate through array and store position in arry if target
    //elemrnt found
    for(int i=0;i<arr_size;i++){
        if(arr[i]==element) {
            found_arr[c]=i;
            c++;
        }
    }
    //print results
    //count = 0 no elemt found
    if(c==0) printf("Element not Found");
    //print postion of target element found if only on found
    else if(c==1) printf("Element Found at position %d",found_arr[0]+1);
    else{
        printf("Element Found at positions ");
        for(int i=0;i<c;i++){
            printf("%d",found_arr[i]+1);
            if (i+1<c) printf(",");
        }
    }
}


int main(){
    int n;
    int target;
    //input number of elements n
    scanf("%d",&n);
    int arr[n];
    //input elements
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //input target to find
    scanf("%d",&target);
    //do linear search
    linear_search(target, arr, n);
    return 0;
}