#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

#ifndef READIMAGE_OFF
BMPImage * readImage(FILE * fp) {

	BMPImage * bmp = malloc (sizeof (BMPImage));	

	if (fread(& (bmp -> header), sizeof(BMPHeader), 1, fp) != 1){
		return NULL; //fread fail
	}

	bmp -> norm_height = abs(bmp -> header.height_px);
	bmp -> pixels = malloc((bmp -> norm_height) * sizeof(Pixel*));
	int i;
	int j;
	for (i = 0;i < (bmp -> norm_height); i++){
		bmp -> pixels[i] = malloc(sizeof(Pixel) * bmp -> header.width_px);
		for(j = 0; j < (bmp -> header.width_px); j++){
			if(fread(&(bmp -> pixels[i][j]),sizeof(Pixel),1,fp) != 1)
			{
				return NULL;
			}
		}
	}
	return bmp;

	}

void freeImage(BMPImage * image) {
	for(int i = 0;i < (image -> norm_height); i++){
		free(image -> pixels[i]);
	}
	free(image -> pixels);
	free(image);
}
#endif

#ifndef WRITEIMAGE_OFF
void writeImage(BMPImage * image, FILE * fp) {

	if(image == NULL || fp == NULL)
	{
		return;
	}

	fwrite(&(image -> header), sizeof (BMPHeader),1,fp);

	for (int i = 0; i < (image -> norm_height); i++){
		for(int j = 0; j < (image -> header.width_px); j++)
		{
			fwrite(&(image -> pixels[i][j]),sizeof(Pixel),1,fp);
		}

	}
}
#endif
