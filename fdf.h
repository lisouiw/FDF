/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:56:01 by ltran             #+#    #+#             */
/*   Updated: 2017/02/23 11:50:25 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define X 2600
#define Y 1400
#define BUFF_SIZE 3000

#include "./get_next_line/get_next_line.h"
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	ft_get_point(char **ent);

typedef	struct		s_w
{
	char			*list;
	struct s_w		*next;
}					t_w;

typedef	struct		s_l
{
	t_w		*babe;
}					t_l;

#endif
