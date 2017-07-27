/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:49:25 by ltran             #+#    #+#             */
/*   Updated: 2017/07/27 15:39:47 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define BUFF_SIZE 200000

#include "minilibx_macos/mlx.h"
//#include "minilibx/mlx.h"
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "./libft/libft.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

typedef struct		s_xy
{
	int				x;
	int				y;
	int				xx;
	int				yy;
	struct s_xy		*next;
}					t_xy;

typedef struct		s_yx
{
	int				x;
	int				y;
	int				xx;
	int				yy;
	struct s_yx		*next;
}					t_yx;

typedef struct		s_coord
{
	int				high;
	int				r;
	int				g;
	int				b;
	int				dex;
	int				dey;
	int				zm;
	int				s_zm;
	void			*mlx;
	void			*win;
	void			*img;
	int				endian;
	char			*adr;
	int				bit;
	int				line;
	int				x;
	int				xk;
	int				y;
	int				yk;
	int				xmax;
	int				xmin;
	int				ymax;
	int				ymin;
	int				*buf;
	char			**map;
}					t_coord;

typedef struct		s_trace
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				ex;
	int				ey;
	int				xinc;
	int				yinc;
}					t_trace;

void	trace_xy(t_trace t, int x, t_coord *pt);
void	trace_yx(t_trace t, int y, t_coord *pt);
int 	*strsplit_two(char const *s, char c, char d);
void	trace(t_xy *x, t_coord *pt);
void	get_info_map(t_coord *pt, char *buf);
void	start_window(t_coord *pt);
void	pixel_put(t_trace t, int color, t_coord *pt);
int		ft_key(int keycode, void *param);
int		err(char *str, int i);
int		createRGB(t_coord *pt);

#endif
