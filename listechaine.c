/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debut.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 01:42:20 by ltran             #+#    #+#             */
/*   Updated: 2017/02/21 06:48:56 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	afficherliste(t_l *premier)
{
	int		i=0;
	t_w *actu = premier->babe;
	
	printf("ENTREE\n");
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
	t_l		*premier;
	t_w		*elem;
	t_w		*new;

	if (!(premier = (t_l*)malloc(sizeof(t_l))))
		return(0);
	if (!(elem = (t_w*)malloc(sizeof(t_w))))
		return(0);
	fd = open(argv[1], O_RDONLY);
	elem->list = NULL;
	elem->next = NULL;
	premier->babe = elem->next;
	while (get_next_line(fd, &line) == 1)
	{
		printf("line = %s\n", line);
		printf("elem = %s\n", elem->list);
		elem->list = line;
		elem->next = premier->babe;
		premier->babe = elem;
		printf("list = %s\n\n", elem->list);
	}
	printf("list = %s\n\n", premier->babe->list);
	afficherliste(premier);
	printf("SORTI\n");
	return(fd);
}
