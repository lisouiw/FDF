/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 01:42:20 by ltran             #+#    #+#             */
/*   Updated: 2017/02/25 00:22:00 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	afficherliste(t_l *premier)
{
	int		i=0;
	t_w *actu = premier->babe;
	
	while (i++ < 10 && actu != NULL)
	{
		printf("COUCOU %s\n", actu->list);
		actu = actu->next;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_w		*elem;

	if (!(elem = (t_w*)malloc(sizeof(t_w))))
		return(0);
	elem->next = (t_w*)malloc(sizeof(t_w));

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		elem->list = line;
		elem->next = premier->babe;
		premier->babe = elem;
	}
	afficherliste(premier);
	return(fd);
}
