/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:17:27 by ltran             #+#    #+#             */
/*   Updated: 2017/02/07 15:55:41 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef	struct		s_coord
{
	int			x;
	int			y;
	char		*color;
}					t_coord;

void	ft_number(char **tab, unsigned int i)
{
	t_coord		p[i];
	if (ft_strlen(tab) == 1)
	{
		p[i].x = ;
		p[i].y = ;
	}
	if (ft_strlen(tab) == 2 /* > 2*/)
	{
		p[i].x = ;
		p[i].y = ;
	}
	if (!(p.color = ft_strchr(tab, ','))
		blanc;
}
