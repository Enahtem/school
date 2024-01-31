#include <stdio.h>
#include <stdlib.h>

// Takes in pointer/size of array
void set_even_to_zero(int *block, int size){
    // Sets every even value to zero
    for (int i = 0;i<size;i+=2){
        block[i]=0;
    }
}


void strcat1(char *str1, char *str2, int size1, int size2){
    for (int i = 0;i<size1;i++){
        if (str1[i]=='\0'){
            for (int j = 0;j<size2;j++){
                str1[i+j]=str2[j];
            }
            break;
        }
    }
}


void strcat2(char *str1, char *str2){
    while (*str1!='\0'){
        str1++;
    }
    while(*str2!='\0'){
        *str1=*str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    
}


int strcmp(char *s1, char *s2){
    if (*s1 == *s2){
        if (*s1=='\0'){
            return 1;
        }else{
            return strcmp(s1+1, s2+1);//Cannot use s1++ because it is post increment?
        }
    } else {
        return 0;
    }
}


int my_atoi(char *num_str){
    int num = 0;
    while (*num_str!='\0'){
        num*=10;
        num+=*num_str-'0';
        num_str++;
    }
    return num;
}

int main(){

    // Question 1

    // Creating int array
    int numbers[] = {5,6,7,8};
    // Finding size
    int size = sizeof(numbers)/sizeof(numbers[0]);
    // Calling Function
    set_even_to_zero(numbers, size);
    // Printing
    printf("Changed Array: ");
    for (int i =0;i<size;i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Question 2
    char str1[100]="Thing ";
    char str2[]="to Concatenate.";
    int size1=sizeof(str1)/sizeof(str1[0]);
    int size2=sizeof(str2)/sizeof(str2[0]);
    strcat1(str1, str2, size1, size2);
    printf("%s\n", str1);
    char str3[]=" Concatenate Again.";
    strcat2(str1, str3);
    printf("%s\n", str1);

    // Question 3
    char *s1 = "asdf";
    char *s2 = "asdf";
    printf("%d\n", strcmp(s1, s2));
    // s1==s2 checks if points to same value (pointers same)
    // *s1==*s2 checks if first value pointed to are the same (first value same)
    // strcmp(s1, s2) checksT if strings contain the same value (strings same)

    // Question 4
    // In lab02.py...


    // Question 5
    char num_string[] = "1234";
    printf("%d\n", my_atoi(num_string)+1);


    return 0;
}