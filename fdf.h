/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:56:01 by ltran             #+#    #+#             */
/*   Updated: 2017/03/02 15:14:32 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define X 2600
#define Y 1400
#define BUFF_SIZE 200000

#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		ft_get_point(int x1, int x2, int y1, int y2);

typedef	struct		s_w
{
	char			*list;
	struct s_w		*next;
}					t_w;

//typedef	struct		s_l
//{
//	t_w		*babe;
//}					t_l;

#endif
