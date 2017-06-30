/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:09:56 by ltran             #+#    #+#             */
/*   Updated: 2017/04/30 03:29:37 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		*create_int(int *mapi, int e, int i, char *str)
{
	int		in = 0;
	int		a;

	mapi = (int*)malloc(e*sizeof(int));
	while (a < e)
	{
		mapi[a] = ft_atoi(&str[a]);
		a++;
	}
	in++;
	return(0);
}

int		ft_check(int argc, char **argv, t_l *info)
{
	int				i = 0;
	int				**mapi;
	int				e = 0;
	char			**map;
	char			**pt;
	int				a;
	int				in;

	info->height = 0;
	info->width = 0;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, X, Y, "FDF");
	if (!(info->fd = open(argv[1], O_RDONLY)))
		return (-1);
	info->rd = read(info->fd, info->buf, BUFF_SIZE);
	info->buf[info->rd] = '\0';
	printf("=========Avant===========\n%s\n", info->buf);
	pt = ft_strsplit(info->buf, '\n');
	map = ft_strsplit(info->buf, ' ');
	while (map[i])
		i++;
	while (pt[e])
		e++;
	printf("I ==> %i && E ==> %i\n", i, e);
	e = (e-1)/i;
	printf("I ==> %i && E ==> %i\n", i, e);
	mapi = (int**)malloc(i*sizeof(int*));
	while(in < i)
	{
		mapi[in] = create_int(*mapi, e, i, map[in]);
		in++;
	}
	in = 0;
	while (in < i)
	{
		a = 0;
		while (a < e)
			printf("%i ", mapi[i][a++]);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_l				info;

	if (ft_check(argc, argv, &info) == -1)
		return (-1);
	mlx_key_hook(info.win, ft_key, 0);
	mlx_loop(info.mlx);
	return (0);
}
