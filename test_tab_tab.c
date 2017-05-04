
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	char	**tab;
	char	tabi[5] = "papou";

	tab = (char**)malloc(2 * sizeof(char*));
	tab[2] = "\0";
	tab[1] = tabi;
	printf("%s\n",tab[1]);
	return (0);
}
