/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 01:42:20 by ltran             #+#    #+#             */
/*   Updated: 2017/02/23 11:50:16 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	char	**ent;
	int		fd;
	int		rd;
	int		i = 0;
	char	buf[BUFF_SIZE];

	fd = open(argv[1], O_RDONLY);
	rd = read(fd, buf, BUFF_SIZE);
	ent = ft_strsplit(buf, ' ');
	while (ft_strchr(ent[i], '\n') == NULL)
		i++;
	rd = i + 1;
	i = 0;
	while (ent[i])
		ft_putstr(ent[i++]);
	i = 0;
	ft_get_point(ent);
/*		while (ent[i])
	{
		//ft_strchr(ent[i],',');
		ft_atoi(ent[i++]);
	}*/
	return(fd);
}
