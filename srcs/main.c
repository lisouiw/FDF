/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:23:00 by ltran             #+#    #+#             */
/*   Updated: 2017/07/27 21:00:41 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		get_info_map(t_coord *pt, char *buf)
{
	pt->r = 255;
	pt->g = 255;
	pt->b = 255;
	pt->buf = strsplit_two(buf, ' ', '\n');
	pt->zm = 0;
	start_window(pt, NULL, NULL);
}

int			main(int ac, char **av)
{
	t_coord		*pt;
	int		op;
	char	*line;
	char	*buf;
	char	**bufi;
	int		i;

	pt = (t_coord*)malloc(sizeof(t_coord));
	buf = NULL;
	pt->y = 1;
	pt->x = 0;
	i = -1;
	op = open(av[1], O_RDONLY);
	if (ac != 2 || op < 0 || ((i = get_next_line(op, &line)) == -1))
		return (err(strerror(errno), 0));
	else if (i == 1 && (i = -1))
	{
		buf = line;
		bufi = ft_strsplit(line, ' ');
		while (bufi[++i])
			++(pt->x);
	}
	else
		return (0);
	while (get_next_line(op, &line) == 1 && i == pt->x && ++(pt->y))
	{
		i = -1;
		buf = ft_strjoin(buf, " ");
		buf = ft_strjoin(buf, line);
		bufi = ft_strsplit(line, ' ');
		while (bufi[++i])
			;
		if (i != (pt->x))
			return (0);
	}
	get_info_map(pt, buf);
	return (0);
}
