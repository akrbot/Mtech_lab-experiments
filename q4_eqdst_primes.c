#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to print the first N prime numbers
void print_eqdst_Primes(int lower_lim,int upper_lim) {
    int num = lower_lim; //start from lower limit
    int array_size = upper_lim-lower_lim;
    int *primes = (int *)malloc(array_size * sizeof(int)); //stores all prime numbers
    for(int i=0;i<array_size;i++) primes[i] = -1; //initialze all elements as -1
    int count = 0; // count number of prime numbers found
    while (num < upper_lim) {
        // check if num is prime
        if (isPrime(num)) {
            //if prime number found store num and increase count
            primes[count] = num;
            count++;
            }
        // to chck for nxt number increment num
        num++;
    }
    printf("\n");
    for(int i=0;i<=count-2;i++){
        for(int j=i+1;j<=count-1;j++){
            for(int k=j+1;k<=count;k++){
                int a = primes[j]-primes[i];
                int b = primes[k]-primes[j];
                if (a==b) printf("%d %d %d %d\n",primes[i],primes[j],primes[k],a);
                else if(b>a) break;
            } 
            
        }
   
    }
    
}

int main() {
    int lower_lim,upper_lim;

    // Get the value of N from the user
    printf("Enter the value of N: ");
    scanf("%d%d", &lower_lim,&upper_lim);
    if(lower_lim<0) lower_lim = 0;
    if(upper_lim<0) upper_lim = 0;
    // Print the eq
    print_eqdst_Primes(lower_lim,upper_lim);

    getchar();
    return 0;
}
