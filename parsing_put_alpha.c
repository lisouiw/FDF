/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:09:56 by ltran             #+#    #+#             */
/*   Updated: 2017/03/13 15:09:55 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *Declaration du bordel
 * */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

int		ft_map_sqr(char *map, int len, int *x, int *y)
{
	char	**line;

	map[len - 1] = '\0';
	line = ft_strsplit(ft_strrchr(map, '\n'), ' ');
	while (line[i] != '\0')
		*(++x);
	line = ft_strsplit(map, '\n');
	while (*line[y] != '\0')
	{
		if (ft_strlen(*ft_strsplit(*line[y], ' ')) != x)
			return (-1);
		*++y;
	}
	return (x);
}

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
	return (str);
}

int		main(int argc, char **argv)
{
	t_l				w;
	int				add = 10;
	size_t			y = 0;
	char			*map;
	char			**line;
	int				x;
	unsigned int	fd;
	int				rd;
	char			buf[BUFF_SIZE + 1];
	int				i = 0;
	
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, 2800, 2000, "Cake");
	if (!(fd = open(argv[1], O_RDONLY))
			return (-1);
	rd = read(fd, buf, BUFF_SIZE);
/*	buf[rd] = '\0';
	buf[rd - 1] = '\0';
	en = ft_strrchr(buf, '\n');
	ent = ft_strsplit(en, ' ');
	while (ent[i] != '\0')
		++i;
	x = i;
	free(ent);
	buf[rd - 1] = '\n';*/
	x = ft_map_sqr(buf, rd, 1, &y); 
	map = ft_replace_char(buf, '\n', ' ');
	line = ft_strsplit(map, ' ');
	while (ent[i])
	{
		rd = (i % x) + 1;
		printf("%i ", rd);
		if (i > 0 && rd == 1)
			y++;
		ft_trace(add * rd, (rd + 1) * add, y * add, y * add; // ft-trace nexiste plus mais replace par ft_get_point
		i++;
	}
	printf("Rd/X = %i && Y = %zu\n", rd, y);
	i = 0;
	while (y > 1)
	{
		rd = (i % x) + 1;
		ft_trace(add * rd, rd * add, (y - 1) * add, y * add);
		if (i > 0 && i % x == 0)
		{
			ft_trace(((x + 1) * add), (1 + x) * add, (y - 1) * add, y * add);
			y--;
		}
		i++;
	}
	printf("Rd/X = %i && Y = %zu\n", rd, y);
	mlx_key_hook(w.win, ft_key, 0);
	mlx_loop(w.mlx);
	return(0);
}
