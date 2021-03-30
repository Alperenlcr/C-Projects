#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"bmp.h"

unsigned char* adding_padding(unsigned char* pixel);
unsigned char* reading();
void printing_image_info();
unsigned char* downsizing(unsigned char*);
void writing(const char*,unsigned char*);
unsigned char* smoothing(unsigned char*,int);

FILE* fp;
FILE* out;
BITMAPFILEHEADER fh;
BITMAPINFOHEADER fi;
int size,dsize,ssize,psize;
//choose picture
const char* filename_r = "original.bmp";

void main ()
{
//downsizing reading
    unsigned char* pixel = reading();
//downsizing printing info
    printf("\n\nFirst\n\n");
    printing_image_info();
    int needed = fi.biSize;
//downsizing downsizing
    unsigned char* dpixel = downsizing(pixel);
//downsizing printing info
    printf("\n\nDOWNSIZED\n\n");
    printing_image_info();
//downsizing writing
    const char* filename_w = "downsized.bmp";
    writing(filename_w,dpixel);

//smoothing padding and reading
    pixel = reading();
	pixel = adding_padding(pixel);
//smoothing smoothing
    unsigned char* spixel = smoothing(pixel,needed);
//smoothing printing info
    printf("\n\nSMOOTHED\n\n");
    printing_image_info();
//smoothing writing
    filename_w = "smoothed.bmp";
    writing(filename_w,spixel);

    free(pixel);
    free(dpixel);
    free(spixel);
}

unsigned char* reading()
{
    fp = fopen(filename_r,"rb");
    fread(&fh,sizeof(fh),1,fp);
    fread(&fi,sizeof(fi),1,fp);
    // allocate 3 bytes per pixel
    size = 3 * fi.biWidth * fi.biHeight;
    unsigned char* pixelF = malloc(size * sizeof(unsigned));
    // read the rest of the pixel at once
    fread(pixelF, sizeof(unsigned char), size, fp); 
    fclose(fp);
    return pixelF;
}

void printing_image_info()
{
    printf("BitCount: %d\nClrImportant: %d\nClrUsed: %d\nCompression: %d\nHeight: %d\nPlanes: %d\nSize(i): %d\nSizeImage: %d\nWidth: %d\nXPelsPerMeter: %d\nYPelsPerMeter: %d\n***\n",fi.biBitCount,fi.biClrImportant,fi.biClrUsed,fi.biCompression,fi.biHeight,fi.biPlanes,fi.biSize,fi.biSizeImage,fi.biWidth,fi.biXPelsPerMeter,fi.biYPelsPerMeter);
    printf("OffBits: %d\nReserved1: %d\nReserved2: %d\nSize(f): %d\nType: %d\n",fh.bfOffBits,fh.bfReserved1,fh.bfReserved2,fh.bfSize,fh.bfType);
}

unsigned char* downsizing(unsigned char* pixel)
{
    dsize = size/4;
    unsigned char* dpixel = malloc(dsize * sizeof(unsigned));
    int x,i,j;
    long a = 0;
    if (fi.biHeight % 2 == 1)
        x = fi.biHeight-1;
    else
        x = fi.biHeight;
    for ( i = 0; i < x; i+=2)
    {
        for ( j = 0; j < fi.biWidth*3; j+=6)
        {
            dpixel[a] = (   pixel[(j+fi.biWidth*3*i)] +
                            pixel[(j+fi.biWidth*3*i+3)] + 
                            pixel[(j+fi.biWidth*3*(i+1))] + 
                            pixel[(j+fi.biWidth*3*(i+1)+3)] ) / 4;
            a++;
            dpixel[a] = (   pixel[((j+1)+fi.biWidth*3*i)] + 
                            pixel[((j+1)+fi.biWidth*3*i+3)] + 
                            pixel[((j+1)+fi.biWidth*3*(i+1))] + 
                            pixel[((j+1)+fi.biWidth*3*(i+1)+3)] ) / 4;
            a++;
            dpixel[a] = (   pixel[((j+2)+fi.biWidth*3*i)] + 
                            pixel[((j+2)+fi.biWidth*3*i+3)] + 
                            pixel[((j+2)+fi.biWidth*3*(i+1))] + 
                            pixel[((j+2)+fi.biWidth*3*(i+1)+3)] ) / 4;
            a++;
        }
    }
    fh.bfSize = (fh.bfSize-54)/4 + 54;
    fi.biWidth = fi.biWidth/2;
    fi.biHeight = fi.biHeight/2;
    return dpixel;
}

void writing(const char* filename_w,unsigned char* pixelF)
{
    out = fopen(filename_w,"wb");
    fwrite(&fh,sizeof(fh),1,out);
    fwrite(&fi,sizeof(fi),1,out);
    fwrite(pixelF,size,1,out);
    fclose(out);
}

unsigned char* adding_padding(unsigned char* pixel)
{
    // allocate 3 bytes per pixel
    psize = 3 * (fi.biWidth+2) * (fi.biHeight+2);
    unsigned char* pixelF = malloc(psize * sizeof(unsigned));
	int i,j,k,a=0,w = fi.biWidth,h = fi.biHeight;
	for ( i = 0; i < w*3+3; i++)
		pixelF[i] = 0;
	for ( j = 0; j < h ; j++)
	{
		for ( k = 0; k < 6; k++)
		{
			pixelF[i] = 0;
			i++;	
		}
		memcpy(pixelF+i,pixel+a,w*3);
		a+=w*3;i+=w*3;
	}
	for ( j = 0; j < w*3+9; j++)
	{	
		pixelF[i] = 0;
		i++;
	}
	return pixelF;
}
unsigned char* smoothing(unsigned char* pixel_padded, int needed)
{
    ssize = size;
    unsigned char* spixel = malloc(ssize * sizeof(unsigned));
    int i,j;
    long a = 0;

    for ( i = 0; i < fi.biHeight+2; i++)
    {
        for ( j = 0; j < fi.biWidth*3-6 ; j++)
        {
            spixel[a] = (   pixel_padded[(j+fi.biWidth*3*i)] * 0.0625 +
                            pixel_padded[(j+fi.biWidth*3*i+3)] * 0.125 + 
                            pixel_padded[(j+fi.biWidth*3*i+6)] * 0.0625 + 
                            pixel_padded[(j+fi.biWidth*3*(i+1))] * 0.125 + 
                            pixel_padded[(j+fi.biWidth*3*(i+1)+3)] * 0.25 + 
                            pixel_padded[(j+fi.biWidth*3*(i+1)+6)] * 0.125 + 
                            pixel_padded[(j+fi.biWidth*3*(i+2))] * 0.0625 + 
                            pixel_padded[(j+fi.biWidth*3*(i+2)+3)] * 0.125 + 
                            pixel_padded[(j+fi.biWidth*3*(i+2)+6)] * 0.0625 
                        );
            a++;
        }
    }
    return spixel;
}