#include <stdlib.h>
#include <stdio.h>
#include "filter.h"

#ifndef BLUR_OFF
BMPImage * blur(BMPImage * image) {
	int i = 0;
	int j = 0;

	int red = 0;
	int blue = 0;
	int green = 0;	
	int alpha = 0;

	//allocate the memory for new image
	BMPImage * bur = malloc(sizeof(BMPImage));
	bur -> header = image -> header;
	bur -> norm_height = image -> norm_height;
	bur -> pixels = malloc((bur -> norm_height) * sizeof(Pixel*));
	for (i = 0;i < (bur -> norm_height); i++){
		bur -> pixels[i] = malloc(sizeof(Pixel) * bur -> header.width_px);
		for(j = 0; j < (bur -> header.width_px); j++){

			Pixel p1 = getPixel(image,i - 1 ,j - 1);
			Pixel p2 = getPixel(image,i - 1,j);
			Pixel p3 = getPixel(image,i - 1,j + 1);
			Pixel p4 = getPixel(image,i,j - 1);
			Pixel p5 = getPixel(image,i,j);
			Pixel p6 = getPixel(image,i,j + 1);
			Pixel p7 = getPixel(image,i + 1,j - 1);
			Pixel p8 = getPixel(image,i + 1,j);
			Pixel p9 = getPixel(image,i + 1,j + 1);
			
			red = (p1.red + p2.red + p3.red + p4.red + p5.red + p6.red + p7.red + p8.red + p9.red) / 9;
			alpha = (p1.alpha + p2.alpha + p3.alpha + p4.alpha + p5.alpha + p6.alpha + p7.alpha + p8.alpha + p9.alpha)/9;
			green = (p1.green + p2.green + p3.green + p4.green + p5.green + p6.green + p7.green + p8.green + p9.green)/9;
			blue = (p1.blue + p2.blue + p3.blue + p4.blue + p5.blue + p6.blue + p7.blue + p8.blue + p9.blue)/9;

			//if the output channel is >255 or < 0
			if(blue > 255){
				blue = 255;
			}
			if(red > 255){
				red = 255;
			}
			if(green > 255){
				green = 255;
			}
			if(alpha > 255){
				alpha = 255;
			}


			if(blue < 0){
				blue = 0;
			}
			if(red < 0){
				red = 0;
			}
			if(green < 0){
				green = 0;
			}
			if(alpha < 0){
				alpha = 0;
			}
			
			bur -> pixels[i][j].blue = (uint8_t)blue; 
			bur -> pixels[i][j].green = (uint8_t)green; 
			bur -> pixels[i][j].red = (uint8_t)red; 
			bur -> pixels[i][j].alpha = (uint8_t)alpha; 
		}
	}
	return bur;
	
}
#endif

Pixel getPixel(BMPImage * image, int r, int c){
	if (r < 0){
		r = 0;
	}
	if (r > ((image -> norm_height)-1)){
		r = image -> norm_height - 1;
	}
	if (c < 0){
		c = 0;
	}
	if (c > ((image -> header.width_px) - 1)){
		c = ((image -> header.width_px) - 1);
	}	
	return image -> pixels[r][c];
}



// EXTRA CREDIT START
BMPImage * apply(BMPImage * image, BoxFilter f) {
	int i = 0;
	int j = 0;

	int red = 0;
	int blue = 0;
	int green = 0;	
	int alpha = 0;

	//allocate the memory for new image
	BMPImage * bur = malloc(sizeof(BMPImage));
	bur -> header = image -> header;
	bur -> norm_height = image -> norm_height;
	bur -> pixels = malloc((bur -> norm_height) * sizeof(Pixel*));
	for (i = 0;i < (bur -> norm_height); i++){
		bur -> pixels[i] = malloc(sizeof(Pixel) * bur -> header.width_px);
		for(j = 0; j < (bur -> header.width_px); j++){

			Pixel p1 = getPixel(image,i - 1 ,j - 1);
			Pixel p2 = getPixel(image,i - 1,j);
			Pixel p3 = getPixel(image,i - 1,j + 1);
			Pixel p4 = getPixel(image,i,j - 1);
			Pixel p5 = getPixel(image,i,j);
			Pixel p6 = getPixel(image,i,j + 1);
			Pixel p7 = getPixel(image,i + 1,j - 1);
			Pixel p8 = getPixel(image,i + 1,j);
			Pixel p9 = getPixel(image,i + 1,j + 1);
			
			red = ((f.filter[0][0]) * p1.red + (f.filter[0][1]) * p2.red + (f.filter[0][2]) * p3.red + (f.filter[1][0]) * p4.red + (f.filter[1][1]) * p5.red + (f.filter[1][2]) * p6.red + (f.filter[2][0]) * p7.red + (f.filter[2][1]) * p8.red + (f.filter[2][2]) * p9.red) / (f.norm);
			
			alpha = ((f.filter[0][0]) * p1.alpha + (f.filter[0][1]) * p2.alpha + (f.filter[0][2]) * p3.alpha + (f.filter[1][0]) * p4.alpha + (f.filter[1][1]) * p5.alpha + (f.filter[1][2]) * p6.alpha + (f.filter[2][0]) * p7.alpha + (f.filter[2][1]) * p8.alpha + (f.filter[2][2]) * p9.alpha)/ (f.norm);

			green = ((f.filter[0][0]) * p1.green + (f.filter[0][1]) * p2.green + (f.filter[0][2]) * p3.green + (f.filter[1][0]) * p4.green + (f.filter[1][1]) * p5.green + (f.filter[1][2]) * p6.green + (f.filter[2][0]) * p7.green + (f.filter[2][1]) * p8.green + (f.filter[2][2]) * p9.green)/ (f.norm);

			blue = ((f.filter[0][0]) * p1.blue + (f.filter[0][1]) * p2.blue + (f.filter[0][2]) * p3.blue + (f.filter[1][0]) * p4.blue + (f.filter[1][1]) * p5.blue + (f.filter[1][2]) * p6.blue + (f.filter[2][0]) * p7.blue + (f.filter[2][1]) * p8.blue + (f.filter[2][2]) * p9.blue)/ (f.norm);

			//if the output channel is >255 or < 0
			if(blue > 255){
				blue = 255;
			}
			if(red > 255){
				red = 255;
			}
			if(green > 255){
				green = 255;
			}
			if(alpha > 255){
				alpha = 255;
			}


			if(blue < 0){
				blue = 0;
			}
			if(red < 0){
				red = 0;
			}
			if(green < 0){
				green = 0;
			}
			if(alpha < 0){
				alpha = 0;
			}
			
			bur -> pixels[i][j].blue = (uint8_t)blue; 
			bur -> pixels[i][j].green = (uint8_t)green; 
			bur -> pixels[i][j].red = (uint8_t)red; 
			bur -> pixels[i][j].alpha = (uint8_t)alpha; 
		}
	}
	return bur;
}

BoxFilter * readFilter(FILE * infile) {
	int i = 0;
	int j = 0;
	BoxFilter * fp = malloc (sizeof (BoxFilter));
	//fp -> filter = malloc(sizeof (int) * 3);//malloc filter [i]
	for (i = 0; i < 3;i++){
		//fp -> filter[i] = malloc(sizeof(int) * 3)//malloc filter [i][j]
		
		for (j = 0;j < 3;j++){
			fscanf(infile, "%d",&(fp -> filter)[i][j]);	
		}
	}
	fscanf(infile, "%f",&(fp -> norm));
		
return fp;
}
// EXTRA CREDIT END
