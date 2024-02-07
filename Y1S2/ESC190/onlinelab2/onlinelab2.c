#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Q5 Function
void set_zero(int *p_a){
    *p_a=0;
}

// Q10 Function
void set_46(int **p_p_a){
    **p_p_a=46;
}

// Q11 Function
void set_new_int(int **p_p_a){
    *p_p_a=(int *)malloc(sizeof(int));
}

// Q16 Function
void change_element(int *arr){
    arr[1]=8;
}

// Q21 Structure
typedef struct student{
    char name[1000];
    int age;
}student;


// Q27 Function
void name_change(student *p_s){
    strcpy(p_s->name, "Changed Name");
}

// Q28 Function
void age_change(student *p_s){
    p_s->age = 10000;
}



int main(){
    // Q1 Testing
    int a = 42;
    printf("%d\n", a);
    // Q2 Testing
    int *p_a = &a;
    printf("%d\n", *p_a);
    // Q3 Testing
    *p_a = 43;
    printf("%d\n", a);
    // Q4 Testing
    int b = 100;
    p_a = &b;
    printf("%d\n", a);
    // Q5 Testing
    // Q6 Testing
    set_zero(&a);
    printf("%d\n", a);
    // Q7 Testing
    set_zero(p_a);
    printf("%d\n", b);
    // Q8 Testing
    int **p_p_a;
    // Q9 Testing
    p_p_a=&p_a;
    // Q10 Testing
    // Q11 Testing
    // Q12 Testing
    set_46(&p_a);
    printf("%d\n", b);
    set_46(p_p_a);
    printf("%d\n", b);
    // Q13 Testing
    set_new_int(&p_a);
    // Q14 Testing
    set_new_int(p_p_a);
    // Q15 Testing
    int arr[3] = {5,6,7};
    // Q16 Testing
    // Q17 Testing
    change_element(arr);
    printf("%d\n", arr[1]);
    // Q18 Testing
    int *p_block=(int *)malloc(sizeof(int)*3);
    change_element(p_block);
    printf("%d\n", p_block[1]);
    // Q19 Testing
    set_zero(p_block+1);
    printf("%d\n", p_block[1]);
    // Q20 Testing
    set_new_int(&p_block);
    // Q21 Testing
    student s = {"Name", 0};
    // Q22 Testing
    strcpy(s.name, "Jennifer");
    printf("%s\n", s.name);
    // Q23 Testing
    s.age=21;
    printf("%d\n", s.age);
    // Q24 Testing
    student *p_s=&s;
    // Q25 Testing
    strcpy(p_s->name, "Jenny");
    printf("%s\n", s.name);
    // Q26 Testing
    p_s->age=20;
    printf("%d\n", s.age);
    // Q27 Testing
    // Q28 Testing
    // Q29 Testing
    name_change(&s);
    printf("%s\n", s.name);
    // Q30 Testing
    age_change(&s);
    printf("%d\n", s.age);
    // Q31 Testing
    student arr_s[5];
    // Q32 Testing
    name_change(arr_s+2);
    age_change(arr_s+2);
    printf("%s\n", arr_s[2].name);
    printf("%d\n", arr_s[2].age);


    // Q1: Create an array of size 5. Initialize it to 1, 2, 3, 4, 5
    int num_array[5] = {1,2,3,4,5};
    // Q2: Loop over the array and print it.
    for (int i = 0; i<sizeof(num_array)/sizeof(int);i++){
        printf("%d ",num_array[i]);
    }
    printf("\n");

    return 0;
}