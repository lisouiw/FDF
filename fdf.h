/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:49:25 by ltran             #+#    #+#             */
/*   Updated: 2017/07/27 20:58:37 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define X 2560
#define Y 1400

#include "minilibx_macos/mlx.h"
#include "minilibx/mlx.h"
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "./libft/libft.h"
#include "./get_next_line.h"
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

typedef struct		s_coord
{
	int				op;
	char			*ln;
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

void		get_info_map(t_coord *pt, char *buf);
int			ft_key(int keycode, void *param);
int			ft_key2(int keycode, void *param);
void		pixel_put(t_trace t, int color, t_coord *pt);
int			rgb_to_hexa(t_coord *pt);
void		start_window(t_coord *pt, t_xy *xy, t_xy *yx);
void		create_menu(t_coord *pt);
void		giv_zoom(t_coord *pt, int y);
void		trace_gril(t_coord *pt, t_xy *xy, t_xy *yx);
t_xy		*add_x(int x, int y, t_xy *xy, t_coord *pt);
t_xy		*add_y(int x, int y, t_xy *yx, t_coord *pt);
t_xy		*lst_xy(t_coord *pt, t_xy *xy);
t_xy		*lst_yx(t_coord *pt, t_xy *yx);
void		trace_xy(t_trace t, int x, t_coord *pt);
void		trace_yx(t_trace t, int y, t_coord *pt);
void		trace(t_xy *x, t_coord *pt);
int			*strsplit_two(char const *s, char c, char d);
int			err(char *str, int i);

#endif
