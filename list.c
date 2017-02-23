/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 06:04:18 by ltran             #+#    #+#             */
/*   Updated: 2017/02/19 19:47:58 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct		s_w
{
	char			*chn;
	struct s_w		*next;
}					t_w;

int		main()
{
	char	*l1 = "Hello";
	char	*l2 = "toi";
	char	*l3 = "je t'aime";
	char	*l4 = "bien";

	t_w		*w;
	t_w		*liste;
	t_w		*prev = NULL;
	t_w		*cure = NULL;
	if (!(w = (t_w*)malloc(sizeof(t_w))))
		return(0);
	w->chn = l1;
	w->next = liste;
	printf("%s\n", w->chn);
	w->chn = l2;
	w->next = liste;
	printf("%s\n", w->chn);
	return(0);
}
