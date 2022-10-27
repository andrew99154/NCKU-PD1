#include <stdio.h>
#include <math.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};

char layers[4] = {'C', 'M', 'Y', 'K'};

void print_C(unsigned int mask[][MAX_SIZE]);
void print_M(unsigned int mask[][MAX_SIZE]);
void print_Y(unsigned int mask[][MAX_SIZE]);
void print_K(unsigned int mask[][MAX_SIZE]);
void CMYK_to_RGB();

int main()
{
    // Get the dimension of the image.
    scanf("%u %u", &W, &H);

    // Declare the mask for single ink color.
    unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

    // For each layer, do the following:
    for (int layer = 0; layer < 4; ++layer)
    {
        // Get color mask.
        for (int i = 0; i < H; ++i)
        {
            for (int j = 0; j < W; ++j)
            {
                scanf("%u", &mask[i][j]);
            }
        }

        // Print a layer of that color to the paper.
        switch (layers[layer])
        {
            case 'C': print_C(mask); break;
            case 'M': print_M(mask); break;
            case 'Y': print_Y(mask); break;
            case 'K': print_K(mask); break;
        }
    }

    // Convert CMYK color to RGB color.
    CMYK_to_RGB();

    // Show the final result.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            printf("#%06x ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void print_C(unsigned int mask[][MAX_SIZE])
{
	for(int i = 0;i<H;i++){
        for (int j=0;j<W;j++){
            mask[i][j] = mask[i][j]<<24;
            image[i][j] |= mask[i][j];
        }   
    }
}

void print_M(unsigned int mask[][MAX_SIZE])
{
	for(int i = 0;i<H;i++){
        for (int j=0;j<W;j++){
            mask[i][j] = mask[i][j]<<16;
            image[i][j] |= mask[i][j];
        }   
    }
}

void print_Y(unsigned int mask[][MAX_SIZE])
{
	for(int i = 0;i<H;i++){
        for (int j=0;j<W;j++){
            mask[i][j] = mask[i][j]<<8;
            image[i][j] |= mask[i][j];
        }   
    }
}

void print_K(unsigned int mask[][MAX_SIZE])
{
	for(int i = 0;i<H;i++){
        for (int j=0;j<W;j++){
            image[i][j] |= mask[i][j];
        }   
    }
}

void CMYK_to_RGB()
{
    int c,m,y,k,r,g,b;
    int mask = 0x000000ff;
	for(int i = 0;i<H;i++){
        for (int j=0;j<W;j++){
            k = image[i][j] & mask;
            image[i][j] >>= 8;
            y = image[i][j] & mask;
            image[i][j] >>= 8;
            m = image[i][j] & mask;
            image[i][j] >>= 8;
            c = image[i][j] & mask;
            r = lround(255*((100.0f-c)/100.0f)*((100.0f-k)/100.0f));
            g = lround(255*((100.0f-m)/100.0f)*((100.0f-k)/100.0f));
            b = lround(255*((100.0f-y)/100.0f)*((100.0f-k)/100.0f));
            image[i][j] = 0;
            image[i][j] |= (r<<16);
            image[i][j] |= (g<<8);
            image[i][j] |= b;
        }
    }
}
