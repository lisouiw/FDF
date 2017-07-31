/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:23:00 by ltran             #+#    #+#             */
/*   Updated: 2017/07/31 23:17:49 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		map(t_coord *pt, char *buf)
{
	int		i;

	i = -1;
	pt->r = 255;
	pt->g = 255;
	pt->b = 255;
	pt->buf = strsplit_two(buf, ' ', '\n');
	pt->zm = 0;
	start_window(pt, NULL, NULL);
	return (1);
}

char	*join(char *buf, char *c, char *str, char **bufi)
{
	char	*new;

	new = ft_strjoin(buf, c);
	free(buf);
	buf = ft_strjoin(new, str);
	free(str);
	free(bufi);
	return (buf);
}

int		main(int ac, char **av)
{
	t_coord		*pt;
	char		*buf;
	char		**bufi;
	int			i;

	pt = (t_coord*)malloc(sizeof(t_coord));
	pt->y = 1;
	pt->x = 0;
	i = -1;
	pt->op = open(av[1], O_RDONLY);
	if (ac != 2 || pt->op < 0 || ((i = get_next_line(pt->op, &(pt->ln))) == -1))
		return (err(strerror(errno), 0));
	i = 0;
	buf = pt->ln;
	while (get_next_line(pt->op, &pt->ln) == 1 && i == pt->x && ++(pt->y))
	{
		i = -1;
		bufi = ft_strsplit(pt->ln, ' ');
		while (bufi[++i])
			;
		pt->x = (pt->x == 0) ? i : pt->x;
		buf = join(buf, " ", pt->ln, bufi);
	}
	return (i == (pt->x) && i > 0) ? map(pt, buf) : (err(strerror(errno), 1));
}
