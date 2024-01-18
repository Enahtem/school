#include <stdio.h>
#include <stdlib.h>
// ???????
void print(char **address, int *string_size){
    printf("Enter string length: ");
    scanf("%d", string_size);
    *address = (char *)malloc(*string_size * (sizeof(char)+1));

    printf("Enter string char by char: ");
    for (int i =0;i<*string_size;i++){
        scanf("%s", &(*address)[i]);
    }
}

int main(){
    char *string;
    int a;
    print(&string, &a);
    printf("STUFF HERE: %s", string);
    free(string);
    return 0;
}