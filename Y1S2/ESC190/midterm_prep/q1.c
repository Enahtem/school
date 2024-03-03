#include <stdio.h>
#include <stdlib.h>

double my_atof(char *string){
    return 1.0;
}


int main(){
    char *filename = "text.txt";
    FILE *fp = fopen(filename, "r");

    int size;
    fscanf(fp, "%d\n", &size);

    double *numbers = (double *)malloc(sizeof(double)*size);
    for (int i = 0;i<size;i++){
        char *before_decimal=(char *)malloc(sizeof(char)*10);
        char *after_decimal=(char *)malloc(sizeof(char)*10);
        fscanf(fp, "%[^.].%[^\n]\n", before_decimal, after_decimal);
        int j = 0;
        double num = 0;
        while (before_decimal[j]!='\0'){
            num*=10;
            num+=(double)(before_decimal[j]-'0');
            j++;
        }
        j=0;
        double decimal = 0;
        while (after_decimal[j]!='\0'){
            decimal*=10;
            decimal+=(double)(after_decimal[j]-'0');
            j++;
        }
        for (int k = 0;k<j;k++){
            decimal/=10;
        }
        numbers[i]=num+decimal;
        printf("%.4f\n", numbers[i]);
        free(before_decimal);
        free(after_decimal);
    }



    free(numbers);



    fclose(fp);
    return 0;
}