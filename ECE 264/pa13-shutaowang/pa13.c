#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "bmp.h"
#include "filter.h"

int main(int argc, char **argv){
       // if(argc != 3){
         //       fprintf(stderr, "Invalide Input!");
         //       return EXIT_FAILURE;
       // }
 
       // FILE * input = fopen(argv[1],"r");
       // FILE * output = fopen(argv[2], "w");
 
       // if(!input){
       //         fprintf(stderr, "Cannot read file!");
        //        return EXIT_FAILURE;
       // }
 FILE * fp = fopen("test.bmp", "rb");
FILE * fp1 = fopen("sharpen.filter","r");
BoxFilter *a = readFilter(fp1);
        BMPImage * image = readImage(fp);
       // BMPImage * new = blur(image);
 BMPImage * new = apply(image, &a);
        //writeImage(new, output);
 
       // fclose(input);
       // fclose(output);
       // freeImage(image);
       // freeImage(new);
        return EXIT_SUCCESS;
}

