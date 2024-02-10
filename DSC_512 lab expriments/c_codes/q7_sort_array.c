#include <stdio.h>

void bubble_sort(int arr[], int n){
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++)
        if(arr[j]>arr[j+1]){
            temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
void main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    bubble_sort(arr,n);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    for(int i=n-1;i>=0;i--) printf("%d ",arr[i]);
}