#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "seamcarving.h"
#include "c_img.h"

void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    create_img(grad, im->height, im->width);
    /*
    Compute the dual-gradient energy function then place it in struct rgb_img *grad

    rx, gx, bx are the differnces in the red, green, and blue components
    of pixels surrounding the central pixel along x axis

    "" for y

    rx = (y, x+1)red - (y,x-1)red
    */

    // 1: COMPUTE rx, gx, bx, ry, gy, by

    for (int y = 0; y < im->height; y++){
        for (int x = 0; x < im->width; x++){
            // rx, gx, bx

            // uint8_t get_pixel(struct rgb_img *im, int y, int x, int col){
            //    return im->raster[3 * (y*(im->width) + x) + col];

            // For pixels at the edge of the image, you should "wrap around" the image (if at border, go to the bottom)

            double xi = 0; // x increment
            double xd = 0; // x derement
            double yi = 0; // y increment
            double yd = 0; // y decrement

            // EDGE CASES FOR X:

            if (x == 0) // if column at very left
            {
                xi = x + 1;
                xd = im->width - 1;
            }
            else if (x == im->width - 1) // or column very right
            {
                xi = 0;
                xd = x - 1;
            }
            else
            {
                xi = x + 1;
                xd = x - 1;
            }

            // EDGE CASES FOR Y:

            if (y == 0) // if very top row
            {
                yi = y + 1;
                yd = im->height - 1;
            }
            else if (y == im->height - 1) // or very last row
            {
                yi = 0;
                yd = y - 1;
            }
            else
            {
                yi = y + 1;
                yd = y - 1;
            }

            double rx = get_pixel(im, y, xi, 0) - get_pixel(im, y, xd, 0);
            double gx = get_pixel(im, y, xi, 1) - get_pixel(im, y, xd, 1);
            double bx = get_pixel(im, y, xi, 2) - get_pixel(im, y, xd, 2);

            // ry, gy, by
            double ry = get_pixel(im, yi, x, 0) - get_pixel(im, yd, x, 0);
            double gy = get_pixel(im, yi, x, 1) - get_pixel(im, yd, x, 1);
            double by = get_pixel(im, yi, x, 2) - get_pixel(im, yd, x, 2);

            // 2: COMPUTE dx, dy

            double dx = rx * rx + gx * gx + bx * bx;
            double dy = ry * ry + gy * gy + by * by;

            // 3: COMPUTE energy

            double energy = sqrt(dx + dy);
            uint8_t dgenergy = energy/10; // dual gradient energy

            // 4: SET energy
            
            set_pixel(*grad, y, x, dgenergy, dgenergy, dgenergy);
            // set red green and blue pixel values to dgenergy
        }
    }
}

int min(int a, int b, int c){
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

void dynamic_seam(struct rgb_img *grad, double **best_arr){
    *best_arr = (double *)malloc(sizeof(double) * grad->width * grad->height);
    for (int i = 0; i < grad->height; i++){
        for (int j = 0; j < grad->width; j++){
            if (i==0){
                (*best_arr)[i*grad->width+j]=get_pixel(grad, i,j,0);
            } else {
                int ji = 0;
                int jd = 0;
                if (j == 0){
                    ji = j + 1;
                    jd = j;
                }
                else if (j == grad->width - 1){
                    ji = j;
                    jd = j - 1;
                }
                else{
                    ji = j + 1;
                    jd = j - 1;
                }
                (*best_arr)[i*grad->width+j]=get_pixel(grad, i,j,0)+min((*best_arr)[(i-1)*grad->width+jd], (*best_arr)[(i-1)*grad->width+j], (*best_arr)[(i-1)*grad->width+ji]);
            }
        }
    }
}
void recover_path(double *best, int height, int width, int **path){
    *path = (int *)malloc(sizeof(int) * height);
    int index = 0;
    double min = best[(height-1)*width];
    for (int i = 0;i<width;i++){
        if (best[i+(height-1)*width]<min){
            min = best[i+(height-1)*width];
            index=i;
        }
    }
    (*path)[height-1] = index;
    for (int i = height - 2; i >= 0; i--) {
        int min_index = index;
        if (index == 0) {
            if (best[i * width + index + 1] < best[i * width + index]) {
                min_index = index + 1;
            }
        } else if (index == width - 1) {
            if (best[i * width + index - 1] < best[i * width + index]) {
                min_index = index - 1;
            }
        } else {
            if (best[i * width + index - 1] < best[i * width + index]) {
                min_index = index - 1;
            }
            if (best[i * width + index + 1] < best[i * width + min_index]) {
                min_index = index + 1;
            }
        }
        index = min_index;
        (*path)[i] = index;
    }


}
void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path){
    create_img(dest, src->height, src->width-1);
    
    for (int y = 0; y < src->height; y++) {
        int dest_x = 0;
        for (int x = 0; x < src->width; x++) {
            if (x != path[y]) {
                set_pixel(*dest, y, dest_x, get_pixel(src, y, x, 0), get_pixel(src, y, x, 1), get_pixel(src, y, x, 2));
                dest_x++;
            }
        }
    }
}
