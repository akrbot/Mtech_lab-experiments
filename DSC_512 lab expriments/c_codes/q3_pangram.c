#include<stdio.h>
#include<stdbool.h>


void isPangram(char *str){
    int charCount[26] = {0};
    char missingChar[50];
    bool flag = true;
    int count = 0;
    while(*str != '\0'){
        // if upppercase convert to lower
        if(*str >= 'A' && *str <= 'Z') *str+= 'a' - 'A';
        //if character lowercase upadte count
        if (*str >= 'a' && *str <= 'z') charCount[*str - 'a'] = 1; 
        str++;
    }
    for (int i=0;i<26;i++){
        if (charCount[i] == 0){
            missingChar[count] = 'a'+i;
            flag = false;
            count++;
            missingChar[count] = ' ';
            count++;
        }
    missingChar[count] = '\0';

    }
    if (flag) printf("Pangram");
    else{
    printf("Not Pangram\n");   
    printf("%s",missingChar);
    }
}

int main(){
    char input[1000];
    fgets(input, sizeof(input), stdin);
    isPangram(input);
    
}