#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab03student1.h"

void set_int1(int x){
    x = 42;
}
void set_int2(int *p_x){
    *p_x = 42;
}

void print_info(student1 *student){
    printf("Name: %s\nNumber: %s\nYear: %d\n\n", student->name, student->student_number, student->year);
}

void set_default_name(student1 *student){
    strcpy(student->name, "Default Name");
    strcpy(student->student_number, "");
    student->year = 0;
}

void create_block1(student1 **p_p_s, int n_students){
    *p_p_s=(student1 *)malloc(sizeof(student1)*n_students);
}

void set_name(student1 *student, char *new_name){
    strncpy(student->name, new_name, sizeof(student->name)-1);
    student->name[sizeof(student->name)-1]='\0';
}

void destroy_block1(student1 **p_p_s){
    free(*p_p_s);
}

typedef struct student2{
char *name;
char *student_number;
int year;
} student2;

void create_block2(student2 **p_p_s, int num_students){
    *p_p_s=(student2 *)malloc(sizeof(student2)*num_students);
    for (int i = 0; i<num_students;i++){
        (*p_p_s)[i].name=(char *)malloc(sizeof(char)*2);
        (*p_p_s)[i].student_number=(char *)malloc(sizeof(char)*2);
        strcpy((*p_p_s)[i].name, "0");
        strcpy((*p_p_s)[i].student_number, "0");
        (*p_p_s)[i].year=0;
    }
}

void set_name2(student2 *student, char *new_name){
    (*student).name=(char *)realloc(student->name, sizeof(char)*(strlen(new_name)+1));
    strcpy((*student).name, new_name);
}

void destroy_block2(student2 **p_p_s, int num_students) {
    for (int i = 0; i < num_students; i++) {
        free((*p_p_s)[i].name);
        free((*p_p_s)[i].student_number);
    }
    free(*p_p_s);
}

void set_name1_test(student1 student, char *new_name){
    strcpy(student.name, new_name);
}

void print_file_contents(char *file_path){
    char line[200];
    FILE *fp = fopen(file_path, "r");
    while (fgets(line, sizeof(line), fp) != NULL){
        printf("%s", line);
    }
    fclose(fp);
}

int average_file_contents(char *file_path){
    char line[200];
    FILE *fp = fopen(file_path, "r");
    int count = 0;
    int sum = 0;
    while (fgets(line, sizeof(line), fp) != NULL){
        count++;
        sum+=atoi(line);
    }
    fclose(fp);
    return sum/count;
}

int main(){
    // Question 1
    int num = 1;
    set_int1(num);
    printf("%d\n", num);
    set_int2(&num);
    printf("%d\n", num);
    // Question 2
    student1 student;
    strcpy(student.name, "Hector Chen");
    strcpy(student.student_number, "1010080500");
    student.year=2027;
    print_info(&student);
    // Question 3
    // Passing the structure directly copies it.
    set_default_name(&student);
    print_info(&student);
    // Question 4
    student1 *studentgroup;
    int num_students=5;
    create_block1(&studentgroup, num_students);
    studentgroup[3]=student;
    print_info(&studentgroup[3]);
    // Question 5
    char *new_name = "Changed Name";
    set_name(&studentgroup[3], new_name);
    print_info(&studentgroup[3]);
    // Question 6
    destroy_block1(&studentgroup);
    // Question 7
    student2 *studentgroup2;
    int num_students2=3;
    create_block2(&studentgroup2, num_students2);
    // Question 8
    set_name2(&studentgroup2[1], "Changed Name");
    printf("Changed Name for studentgroup2: %s\n\n", (studentgroup2)[1].name);
    // Question 9
    destroy_block2(&studentgroup2, num_students2);
    // Question 10
    // Creates copy of structure. Modifies copy, but not original
    student1 student_test_1;
    student2 *student_test_2;
    create_block2(&student_test_2, 1);

    set_name1_test(student_test_1, "Test");
    set_name2(&student_test_2[0], "Test");
    printf("Changed Name Test 1: %s\n", student_test_1.name);
    printf("Changed Name Test 2: %s\n", student_test_2[0].name);

    // Question 11
    // gcc -Wall -std=c99 lab03.c -o a.exe
    // ./a.exe

    // Question 12
    // Moved student1 to header file.

    // Question 13
    print_file_contents("lab03file.txt");

    // Question 14
    printf("%d",average_file_contents("lab03numbers.txt"));

    return 0;
}