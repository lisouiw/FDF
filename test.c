#include <stdio.h>
//#include <stdlib.h>

void decoupeMinutes(int *heures, int *minutes);

int main(int argc, char *argv[])
{
   	int heures = 0, minutes = 90;
   
	decoupeMinutes(&heures, &minutes);
	printf("%d heures et %d minutes", heures, minutes);

	 return 0;
}

void decoupeMinutes(int *heures, int *minutes)
{
	*heures = *minutes / 60;
	*minutes = *minutes % 60;
}
