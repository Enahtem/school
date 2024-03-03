#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *string = (char *)malloc(sizeof(char)*100);
    char *string2 = (char *)malloc(sizeof(char)*100);

    strcpy(string,"asdf");
    strcpy(string2,"qwer");
    memmove(string+4, string, sizeof(char)*100);
    printf("%s, %s", string, string2);
    free(string);
    free(string2);
    return 0;
}