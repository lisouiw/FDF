/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 01:42:20 by ltran             #+#    #+#             */
/*   Updated: 2017/03/02 08:38:31 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

char	*ft_replace_char(char *str, char c, char r)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			str[i] = r;
		i++;
	}
	printf("len = %zu buf = |%s|\n",ft_strlen(str), str);
	return (str);
}

int		main(int argc, char **argv)
{
	size_t	y;
	char	*en;
	char	**ent;
	int		x;
	int		fd;
	int		rd;
	char	buf[BUFF_SIZE + 1];
	int		i = 1;
	
	fd = open(argv[1], O_RDONLY);
	rd = read(fd, buf, BUFF_SIZE);
	buf[rd - 1] = '\0';
	en = ft_strrchr(buf, '\n');
	ent = ft_strsplit(en, ' ');
	while (ent[i] != '\0')
		++i;
	x = i;
	free(ent);
	buf[rd - 1] = '\n';
	en = ft_replace_char(buf, '\n', ' ');
	ent = ft_strsplit(en, ' ');
	i = 0;
	while (ent[i])
	{
		if (i % x == 0)
			printf("\n");
		i++;
	}
	return(fd);
}
