#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("test.txt", "r");
    char str[100];
    while (fgets(str, 100, fp) != NULL){
        char *tok = strtok(str, " ");
        while (tok != NULL){
            printf("%s", tok);
            tok = strtok(NULL, " ");
        }
    }
    fclose(fp);
    return 0;
}