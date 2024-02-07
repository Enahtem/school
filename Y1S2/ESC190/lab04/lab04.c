#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>


void segmentation_fault() {
    int *crashing_pointer=NULL;
    printf("%d\n", *crashing_pointer);
}

void segmentation_fault2(){
    FILE *pointer_file=fopen("a.txt","r");
    // If file doesn't exist
    if (pointer_file==NULL){
        printf("ERROR: File Cannot be Opened");
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), pointer_file) != NULL){
        printf("%s", line);
    }
    // Closing file to prevent memory leaks
    fclose(pointer_file);

}





void adding_constants(){
    FILE *fp=fopen("constants.txt","r");
    char line[200];
    double sum = 0.0;
    int max_decimal_count = 0;
    while (fgets(line, sizeof(line), fp) != NULL){
        char * number = strstr(line, " = ")+strlen(" = ");

        double whole_num = 0.0;
        double decimal_num = 0.0;
        double decimal_pow = 1.0;
        int decimal_count = 0;
        double sign = 1.0;
        if (*number=='-'){
            sign=-1.0;
            number++;
        }


        while (*number >= '0' && *number <= '9'){
            whole_num = whole_num*10.0 + (*number - '0');
            number++;
        }

        if (*number == '.') {
            number++;
            while (*number >= '0' && *number <= '9') {
                decimal_num = decimal_num * 10.0 + (*number - '0');
                decimal_pow*=10.0;
                decimal_count++;
                number++;
            }
        }
        double final_num = (whole_num+decimal_num/decimal_pow)*sign;
        if (decimal_count>max_decimal_count){
            max_decimal_count=decimal_count;
        }
        printf("%f\n\n", final_num);

        sum+=final_num;
    }
    fclose(fp);
    printf("%.*f\n", max_decimal_count,sum);
}


typedef struct student{
    char name[100];
    int age;

}student;

void changename(student *s){
    strcpy(s->name, "newthing");
}


void q4(){

    student s = {"ab", 20};
    printf("%s\n", s.name);
    changename(&s);
    printf("%s\n", s.name);

}

int main() {
    // Run Valgrind in WSL
    // gcc -g -o lab04 lab04.c
    // valgrind --leak-check=full ./lab04

    // segmentation_fault();
    // segmentation_fault2();
    // adding_constants();
    q4();
    // Python cannot change individual characters in string. They are immutable.


    printf("\n\n\n\n\n\n\n");
    return 0;
}
