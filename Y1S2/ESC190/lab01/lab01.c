#include <stdio.h>

void set_ten(int *num){
    *num=10;
}

void change_string(char *arr_pointer){
    arr_pointer[0]='s';
    arr_pointer[1]='s';
    arr_pointer[2]='s';
    arr_pointer[3]='s';

}

void insertion_sort(int *arr, int arr_size){
    for (int i = 1; i<arr_size;i++){
        int val=arr[i];
        for (int j=i-1;j>=0;j--){
            if (arr[j]>=val){
                arr[j+1]=arr[j];
                if (j==0){
                    arr[0]=val;
                    break;
                } 
            } else {
                arr[j+1]=val;
                break;
            }
        }
    }
}

int string_length(char *str){
    char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

void seq_replace(int *arr1, int arr1_sz, int *arr2, int arr2_sz){
    for (int i =0;i<arr1_sz-arr2_sz+1;i++){
        int arr2_found = 1;
        for (int j = 0; j<arr2_sz;j++){
            if (arr1[i+j]!=arr2[j]){
                arr2_found=0;
                break;
            }
        }
        if (arr2_found==1){
            for (int j = 0; j<arr2_sz;j++){
                arr1[i+j]=0;
            }
            i+=arr2_sz;
        }


    }
}

int main(){
// Question 1
// Question 2
    int a = 5;
    set_ten(&a);
    printf("Modified Integer: %d\n", a);

// Question 3
    char arr[100]="initial string";
    change_string(arr);
    printf("Modified String: %s", arr);
    printf("\n");


// Question 4
    int arr2[] = {5,6,1,2,9};
    int arr_size = sizeof(arr2)/sizeof(arr2[0]);
    insertion_sort(arr2, arr_size);
    printf("Sorted Array: ");
    for (int i =0;i<arr_size;i+=1){
        printf("%d ", arr2[i]);
    }
    printf("\n");

// Question 5
    char str2[] = "asdf";
    printf("String contents: %s", str2);
    printf(", String length: %d", string_length(str2));
    printf("\n");

// Question 6
    int arr_a[] = {5, 6, 7, 8, 6, 7};
    int a_size = sizeof(arr_a)/sizeof(arr_a[0]);
    int arr_b[] = {6, 7};
    int b_size = sizeof(arr_b)/sizeof(arr_b[0]);
    seq_replace(arr_a, a_size, arr_b, b_size);
    printf("Replaced Array: ");
    for (int i =0;i<a_size;i+=1){
        printf("%d ", arr_a[i]);
    }


    return 0;
}