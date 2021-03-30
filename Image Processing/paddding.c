#include<stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

unsigned char* adding_padding(unsigned char*);
unsigned char* reading();
typedef struct
{
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} __attribute__((__packed__)) BITMAPFILEHEADER;

typedef struct
{
    uint32_t biSize;
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} __attribute__((__packed__)) BITMAPINFOHEADER;

FILE* fp;
FILE* out;
BITMAPFILEHEADER fh;
BITMAPINFOHEADER fi;
int size,psize;
const char* filename_r = "32bit.bmp";


void main()
{
	//pixel lazim
	 unsigned char* pixel = reading();
	//pixel e ekleme cikarma lazim
	pixel = adding_padding(pixel);
	int i,j=1;
	for(i = 0 ; i < 102*102*3 ; i++)
    {
        if (i % 306 == 0)
		{
            printf("\n\n%d----->>>>>\t",j);j++;
		}
        printf("%d / ",pixel[i]);
        i++;
    }
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
	printf("i = %d		j = %d",i,a);
	return pixelF;
}

































//adding padding
/*
typedef struct
{
    uint8_t  rgbtBlue;
    uint8_t  rgbtGreen;
    uint8_t  rgbtRed;
} __attribute__((__packed__)) RGBTRIPLE;
*/
/*
    //factor to resize by
    const int FACTOR = 1;

    // open input file 
    FILE* inptr = fopen("itu.bmp", "rb");

    // open output file
    FILE* outptr = fopen("padded.bmp", "wb");

    fread(&fh, sizeof(fh), 1, inptr);
    fread(&fi, sizeof(fi), 1, inptr);

	//old width 
	int oldWidth = fi.biWidth;
	int oldHeight = fi.biHeight;
    int old_padding = ((4 - (fi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4);

	//buffer to store old scanline in
	RGBTRIPLE scanline[oldWidth];
	
	// determine padding for scanlines
    int padding = 2;
	
	// size of new scanline
	int sizeOfScanline = (fi.biWidth * sizeof(RGBTRIPLE));

	fi.biSizeImage = sizeOfScanline * (abs(fi.biHeight));
	fh.bfSize = sizeof(fh) + sizeof(fi) + fi.biSizeImage;


    fwrite(&fh, sizeof(fh), 1, outptr);
    fwrite(&fi, sizeof(fi), 1, outptr);

    // iterate over "itu.bmp"'s scanlines
    for (int i = 0, height = abs(oldHeight); i < height; i++)
    {
        // iterate over pixels in scanline
		for (int j = 0; j < oldWidth; j++)
        {
            // read RGB triple from "itu.bmp"
            fread(&scanline[j], sizeof(RGBTRIPLE), 1, inptr);
		}

		fseek(inptr, old_padding, SEEK_CUR);

		//write FACTOR number of scanlines
		for (int s = 0; s < FACTOR; s++) 
		{
			//write a scanline
			for (int l = 0; l < fi.biWidth; l++)
			{ 
				//write a pixel
				for (int m = 0; m < FACTOR; m++)
				{
					// write RGB triple to "padded.bmp"
					fwrite(&scanline[l], sizeof(RGBTRIPLE), 1, outptr);
				}
			}
			//padding
			for (int n = 0; n < padding; n++)
			{
				fputc(0x00, outptr);
			}
			//reset file position indicator  WHY ??
			fseek(outptr, -(sizeOfScanline * (FACTOR -1)), SEEK_CUR);
		}
   }

	// close "itu.bmp"
    fclose(inptr);

    // close "padded.bmp"
    fclose(outptr);
*/