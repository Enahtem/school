#include <stdio.h>


int linear_search(int *a, int sz, int elem){
    for (int i=0;i<sz;i++){
        if (a[i]==elem){
            return i;
        }
    }
    return -1;
}


void reverse_arr(int *arr, int sz){
    for (int i = 0; i < sz / 2; i++){
        int temp = arr[i];
        arr[i] = arr[sz - 1 - i];
        arr[sz - 1 - i] = temp;
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int search_element = 3;
    int result = linear_search(array, size, search_element);

    if (result != -1) {
        printf("Element %d found at index %d\n", search_element, result);
    } else {
        printf("Element %d not found in the array\n", search_element);
    }

    int arr_to_reverse[] = {5, 6, 7, 8};
    int size_to_reverse = sizeof(arr_to_reverse) / sizeof(arr_to_reverse[0]);

    printf("Original array: ");
    for (int i = 0; i < size_to_reverse; i++) {
        printf("%d ", arr_to_reverse[i]);
    }
    printf("\n");

    reverse_arr(arr_to_reverse, size_to_reverse);

    printf("Reversed array: ");
    for (int i = 0; i < size_to_reverse; i++) {
        printf("%d ", arr_to_reverse[i]);
    }
    printf("\n");

    return 1;
}