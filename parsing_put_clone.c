/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:09:56 by ltran             #+#    #+#             */
/*   Updated: 2017/03/23 11:13:20 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**cut_all(char *buf, int i, int ln, int a)
{
	char	**line;
	char	**lise;
	char	**lin;
	int	**nb;
	unsigned int	in;
	int	p = 0;

	line = ft_strsplit(buf,'\n');
	while (line[ln])
		ln++;
	lin = ft_strsplit(buf, ' ');
	nb = (int**)malloc(ln*sizeof(int*));
	while (i < ln)
	{
		in = 0;
		a  = 0;
		lise = ft_strsplit(line[i], ' ');
		while (lise[a])
			a++;
		nb[i] = (int*)malloc(a*sizeof(int));
		if (p > 0 && ft_strrchr(lin[p-1], '\n') != NULL)
		{
			printf("a-> %i i-> %i line %s\n",a,i, lin[p-1]);
			printf("Give %i\n",nb[i][0] = ft_atoi(ft_strrchr(lin[p-1], '\n')));
			in++;
		}		
		while (in < a)
		{
			printf("tab[%i][%i] = %i\n",i,in,nb[i][in] = ft_atoi(lin[p++]));
			in++;
		}
		printf("a-> %i i-> %i\n",a,i);
		i++;
	}
	return(nb);
}


int	**make_int(int **nb, char *buf, int i, int o)
{
	int	**nice;

	nice = cut_all(buf,0,0,0);
	printf("nice=> %i\n", nice[36][168]);
	return (nice);
}

int		main(int argc, char **argv)
{
	int	fd;
	int	rd;
	int	**nb;
	int	i = 0;
	char	buf[BUFF_SIZE+1];

	fd = open(argv[1], O_RDONLY);
	rd = read(fd, buf, BUFF_SIZE);
	buf[rd] = '\0';

	nb = make_int(nb, buf, 0, 0);
	return(0);
}
