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

int	nb_line(char *buf, int *i, int nb)
{
	while (buf[*i] != '\n')
	{
		while (buf[*i] == ' ')
			(*i)++;
		if (buf[*i] >= '0' && buf[*i] <= '9')
		{
			nb++;
			while (buf[*i] != ' ')
				(*i)++;
		}
	}
	return (nb);
}

int	**make_int(int **nb, char *buf, int i, int o)
{
	int	a = 0;
	while (buf[o++] != '\0')
		i = (buf[o] == '\n') ? i+1 : i;
	printf("=========%i========\n",i);
	nb = (int**)malloc((i+1)*sizeof(int*));
	nb[i] = "\0";
	o = 0;
	while (buf[in])
	{
		nb[a] = line_tab(buf[in], &in, 0);
	
	}
	return (nb);
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
	printf("%s\n", buf);
	return(0);
}
