
#include <stdio.h>

int	createRGB(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}


int	main(void)
{
	int	r = 213;
	int	g = 0;
	int	b = 0;

	printf("%x\n",createRGB(r,g,b));
	return (0);
}


/*
unsigned long createRGBA(int r, int g, int b, int a)
{   
    return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8)
           + (a & 0xff);
}*/
