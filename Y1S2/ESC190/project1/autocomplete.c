#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "autocomplete.h"

// gcc -Wall -std=c99 autocomplete.c main.c -o autocomplete ; ./autocomplete


int compare(const void *t1, const void *t2) {
    const term *term1 = (const term *)t1;
    const term *term2 = (const term *)t2;
    return strcmp(term1->term, term2->term);
}

void read_in_terms(struct term **terms, int *pnterms, char *filename){
    FILE *pointer_file=fopen(filename,"r");
    if (pointer_file==NULL){
        exit(1);
    }
    char line[300]; //200 is max term size and weight should not be >100 terms
    *pnterms=atoi(fgets(line, sizeof(line), pointer_file));
    *terms = (term *)malloc(sizeof(term)*(*pnterms));

    int i= 0;
    while (fgets(line, sizeof(line), pointer_file) != NULL){
        int search_mode = 0;
        int weight_start = 0;
        int weight_end = 0;
        int term_start = 0;
        int term_end = 0;
        for (int j =0;j<200;j++){
            if (search_mode==0 && line[j]!=' '){
                search_mode+=1;
                weight_start=j;
            } else if (search_mode==1 && !isdigit(line[j])){
                search_mode+=1;
                weight_end=j;
            } else if (search_mode==2 && line[j]!=' '){
                search_mode+=1;
                term_start=j;
            } else if (search_mode==3 && line[j]=='\n'){
                search_mode+=1;
                term_end=j;
            }
        }
        char line_weight[weight_end-weight_start];
        for (int j = weight_start;j<weight_end;j++){
            line_weight[j-weight_start]=line[j];
        }
        line_weight[weight_end-weight_start]='\0';

        char line_term[term_end-term_start+1];
        for (int j = term_start;j<term_end;j++){
            line_term[j-term_start]=line[j];
        }
        line_term[term_end-term_start]='\0';

        strcpy((*terms)[i].term,line_term);
        (*terms)[i].weight=atoi(line_weight);
        i+=1;
    }
    fclose(pointer_file);

    // Sorting the thing.
    qsort(*terms, *pnterms, sizeof(term), compare);


    // Testing
    // for (int i=0;i<10;i++){
    //     printf("%.0f %s\n", (*terms)[i].weight, (*terms)[i].term);
    // }
}


int lowest_match(struct term *terms, int nterms, char *substr){
    int lower=0;
    int higher=nterms-1;
    int middle;
    int lowest=0;
    while (strncmp(terms[lower].term, terms[higher].term, strlen(substr))<=0){
        middle=(lower+higher)/2;
        // printf("Lower: %d %.0f %s\n", lower, (terms)[lower].weight, (terms)[lower].term);
        // printf("Middle: %d %.0f %s\n", middle, (terms)[middle].weight, (terms)[middle].term);
        // printf("Higher: %d %.0f %s\n", higher, (terms)[higher].weight, (terms)[higher].term);
        if (strncmp(terms[middle].term, substr, strlen(substr))<0){
            lower=middle+1;
        } else{
            higher = middle-1;
            lowest=middle;
        }


    }
    // printf("\n\n%d \n\n", lowest);
    // printf("%.0f %s\n", (terms)[lowest-1].weight, (terms)[lowest-1].term);
    // printf("%.0f %s\n", (terms)[lowest].weight, (terms)[lowest].term);
    // printf("%.0f %s\n", (terms)[lowest+1].weight, (terms)[lowest+1].term);
    return lowest;
}
int highest_match(struct term *terms, int nterms, char *substr){

    int lower=0;
    int higher=nterms-1;
    int middle;
    int highest=0;
    while (strncmp(terms[lower].term, terms[higher].term, strlen(substr))<=0){
        middle=(lower+higher)/2;
        // printf("Lower: %d %.0f %s\n", lower, (terms)[lower].weight, (terms)[lower].term);
        // printf("Middle: %d %.0f %s\n", middle, (terms)[middle].weight, (terms)[middle].term);
        // printf("Higher: %d %.0f %s\n", higher, (terms)[higher].weight, (terms)[higher].term);

        if (strncmp(terms[middle].term, substr, strlen(substr))>0){
            higher = middle-1;
        } else{
            lower=middle+1;
            highest=middle;
        }
    }
    // printf("\n\n%d \n\n", highest);
    // printf("%.0f %s\n", (terms)[highest-1].weight, (terms)[highest-1].term);
    // printf("%.0f %s\n", (terms)[highest].weight, (terms)[highest].term);
    // printf("%.0f %s\n", (terms)[highest+1].weight, (terms)[highest+1].term);
    return highest;
}



int compare2(const void *t1, const void *t2) {
    const term *term1 = (const term *)t1;
    const term *term2 = (const term *)t2;
    return -(term1->weight-term2->weight);
}


void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr){
    int lowest = lowest_match(terms, nterms, substr);
    int highest = highest_match(terms, nterms, substr);
    *n_answer=highest-lowest+1;
    *answer=(term *)malloc(sizeof(term)*(*n_answer));

    for (int i =lowest;i<=highest;i++){
        (*answer)[i-lowest]=terms[i];
    }

    qsort(*answer, *n_answer, sizeof(term), compare2);
    // Testing
    // for (int i=0;i<10;i++){
    //     printf("%.0f %s\n", (*answer)[i].weight, (*answer)[i].term);
    // }
}
