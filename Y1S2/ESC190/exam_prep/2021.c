#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_hash(char *str){
    int num = 0;
    for (int i = 0;i<strlen(str);i++){
        num += (str[i]-'0');
    }
    return num%100;
}

int repeats(char **strs, int strs_sz){
    int *hashCounts = calloc(100, sizeof(int));
    char ***s = malloc(100*sizeof(char **));
    for (int i =0;i<100;i++){
        s[i] = malloc(strs_sz*sizeof(char *));
    }

    for (int i =0;i<strs_sz;i++){
        int index = get_hash(strs[i]);
        s[index][hashCounts[index]] = strs[i];
        hashCounts[index]+=1;
    }

    for (int i = 0;i<100;i++){
        if (hashCounts[i]>=2){
            for (int j = 0;j<hashCounts[i];j++){
                for (int k = 0;k<hashCounts[i];k++){
                    if (strcmp(s[i][j], s[i][k])==0 && k!=j){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;

}

int main(){
  char *strs[] = {"ESC", "PHY", "MSE", "CIV"};
  printf("%d\n", repeats(strs, 4)); // 0

  char *strs1[] = {"ESC", "PHY", "MSE", "CIV", "CVI"};
  printf("%d\n", repeats(strs1, 5)); // 0

  char *strs2[] = {"ESC", "PHY", "MSE", "CIV", "ESC"};
  printf("%d\n", repeats(strs2, 5)); // 1
}
