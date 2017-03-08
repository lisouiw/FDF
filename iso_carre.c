/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_carre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:34:13 by ltran             #+#    #+#             */
/*   Updated: 2017/03/05 13:44:48 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

int		ft_key(int keycode, void *param);

void	ft_trace(int x1, int x2, int y1, int y2, void *mlx, void *win);

void	ft_isometrie(int x, int y, void *mlx, void *win)
{
	int		ad = 50;
	int		tmpx = x;
	int		tmpy = y;
	int		x1 = x + 1;
	int		x2 = y;
	int		y1;

	x = ((tmpx + tmpy) / 2);
	y = ((tmpx - tmpy) / 2);
	y1 = ((x1 - tmpy) / 2);
	x1 = ((x1 + tmpy) / 2);
	printf("x = %i || y = %i && x1 = %i || y1 = %i\n", x , y, x1, y1);
	ft_trace(ad * x, x1 * ad, y * ad, y1 * ad, mlx, win);

}

int		main()
{	
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 2800, 2000, "Cake");
	ft_isometrie(1, 10, mlx, win);
	ft_isometrie(20, 10, mlx, win);
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
	return (0);
}





/*	if (x < y && x < 0)
	{
		y = y + abs(x);
		x = 0;
	}
	else if (x > y && y < 0)
	{
		x = abs(y);
		y = 0;
	}*/

/*
int		ft_key(int keycode, void *param);

void	ft_trace(int x1, int x2, int y1, int y2, void *mlx, void *win);

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
		if (i > 0 && rd == 1)
			y++;
		ft_trace(add * rd, (rd + 1) * add, y * add, y * add, mlx, win);
		i++;
	}
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
	mlx_key_hook(win, ft_key, 0);
	mlx_loop(mlx);
	return(fd);
}*/
