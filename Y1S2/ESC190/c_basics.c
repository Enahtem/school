// Including Header Files
#include <stdio.h> //I/O functions
#include <stdlib.h> //Utility functions (Memory Allocation, Type Conversions, Algorithms)
#include <math.h> //Math functions


int function_name(){
   return 1;
}

struct point{
   int x;
   int y;
};


int main() {
   printf("This is the \'Format String\'.\n");//Print Function
   //Declaring variables: Named memory spaces.
   int a=3;
   char b='a';
   double c= 3.14;
   printf("char: %d, int: %c, double: %f\n", a, b, c);//Print Variables
   // Declaring arrays: Named continuous set of memory spaces.
   int arr[10]; //Array with size 10
   arr[3]=1; //Accessing element of array

   // Pointer: variable that points to a memory location of a certain type
   int i = 1;//Defining variable
   int *p_i = &i;//Pointer to address of variable (&variable)
   *p_i = 2; //Pointer accesses value of variable (*pointer)

// Structures
   struct point p;
   p.x=1;
   p.y=0;

// Memory Management
// Variable memory types: 
// local (created/destroyed in a specific section)
// static (created/retained in specific section)
// malloc (dynamic memory allocation)
   // 
   int *arr2 = (int *)malloc(10*sizeof(int));//Allocating 10 int sizes of memory
   if(arr2==NULL){exit(1);} //Not enough memory
   for (int i = 0; i < 10; ++i) {
        arr2[i] = i; // Initializing elements
    }
   printf("Second element: %d\n", arr2[2]);
   arr2 = (int *)realloc(arr2, 15*sizeof(int));//Changing to 15 int size with realloc
   if(arr2==NULL){exit(1);} //Not enough memory
   for (int i = 10; i < 15; ++i) {
        arr2[i] = i; // Initializing elements
   }
   printf("Twelfth new element: %d", arr2[12]);
   free(arr2);//Free memory
}