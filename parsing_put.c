/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:09:56 by ltran             #+#    #+#             */
/*   Updated: 2017/03/10 16:37:24 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *Declaration du bordel
 * */

#include "mlx.h"
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
	return (str);
}

int		main(int argc, char **argv)
{
	int		add = 10;
	void	*mlx;
	void	*win;
	size_t	y = 1;
	char	*en;
	char	**ent;
	int		x;
	int		fd;
	int		rd;
	char	buf[BUFF_SIZE + 1];
	int		i = 1;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 2800, 2000, "Cake");
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
		rd = (i % x) + 1;
		printf("%i ", rd);
		if (i > 0 && rd == 1)
			y++;
		ft_trace(add * rd, (rd + 1) * add, y * add, y * add, mlx, win); // ft-trace nexiste plus mais replace par ft_get_point
		i++;
	}
	printf("Rd/X = %i && Y = %zu\n", rd, y);
	i = 0;
	while (y > 1)
	{
		rd = (i % x) + 1;
		ft_trace(add * rd, rd * add, (y - 1) * add, y * add, mlx, win);
		if (i > 0 && i % x == 0)
		{
			ft_trace(((x + 1) * add), (1 + x) * add, (y - 1) * add, y * add, mlx, win);
			y--;
		}
		i++;
	}
	printf("Rd/X = %i && Y = %zu\n", rd, y);
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
	return(fd);
}
