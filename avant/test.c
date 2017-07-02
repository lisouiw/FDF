#include <stdio.h>
//#include <stdlib.h>

=======================================================================

typedef	struct	s_l
{
	int			x;
}				t_l;

void	ft_onverra(int *i)
{
	*i = 100;
}

int		main()
{
	t_l		w;

	w.x = 1;
	printf("%i\n", w.x);
	ft_onverra(&w.x);
	printf("%i\n", w.x);
	return (0);
}
/*
=======================================================================

void	ft_full(char *tab, int len)
{
	int		i = 0;
	printf("coucou\n");
	tab[len] = '\0';
	printf("coucou\n");

	while (tab[i])
	{
		tab[i] = '1';
		i++;
	printf("coucou\n");
	}
}

int		main()
{
	char	*tab;
	int		len = 10;

	printf("coucou\n");
	ft_full(&(*tab), len);
	printf("coucou\n");
	printf("%s\n", tab);

}

=======================================================================

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
}*/
