// gcc -o lab09 lab09.c c_img.c
// ./lab09.exe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_img.h"

int main(){

    double multiplier[5] = {0.5,0.75,1.0,1.25,1.50};
    char *filename_new[5] = {"image1.bin", "image2.bin", "image3.bin", "image4.bin", "image5.bin"};
    for (int num = 0;num<5;num++){
        char *filename = "image.bin";
        struct rgb_img **im;
        read_in_img(im, filename);
        for (int i =0;i<(*im)->height;i++){
            for (int j =0;j<(*im)->width;j++){
                int r = get_pixel(*im, i, j, 0)*multiplier[num];
                int g = get_pixel(*im, i, j, 1)*multiplier[num];
                int b = get_pixel(*im, i, j, 2)*multiplier[num];
                set_pixel(*im, i, j, r, g, b);
            }
        }
        write_img(*im, filename_new[num]);
        destroy_image(*im);
    }

    return 0;
}