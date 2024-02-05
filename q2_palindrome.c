#include <stdio.h>

int main(){
    //init variables
    int num;
    int rev = 0;
    int r;
    int isneg = 1;
    int offset = 0;
    int digits = 0;
    
    //read value
    scanf("%d",&num);
    
    //check if num is already negative then remove negative and set flag
    if (num<0){
        num = num*-1;
        isneg = -1;
        offset = 1;
    }
    
    //reverse the number and also count no of digits
    int temp = num;
    while (num>0){
        r = num%10;
        rev = (rev*10) + r;
        num = num/10;
        digits++;
        //printf("%d %d \n",num,rev);
    }
    
    // if reverse and orginal num is same (if same its palindrome)
    if(temp == rev){
        printf("Palindrome");
    }
    else{
        printf("Not Palindrome");
    }
    //print the reversed number with same digits as input number
    //if number is negative make reversed number negative by multiplying by -1
    //also digits should be +1 since -ve sign also considered as digit
    printf("\n%0*d",digits+offset,rev*isneg);
}