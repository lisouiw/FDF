/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 15:49:25 by ltran             #+#    #+#             */
/*   Updated: 2017/07/11 14:17:11 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define BUFF_SIZE 2000000

#include "minilibx_macos/mlx.h"
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "libft/libft.h"
#include <fcntl.h>
#include <sys/stat.h>

typedef struct		s_coord
{
	int				x;
	int				y;
	char			**ln;
}					t_coord;

typedef struct		s_tool
{
	void			*mlx;
	void			*win;
	void			*img;
	int				endian;
	int				bit;
	int				line;
}					t_tool;

//void	trace_xy(int x1, int y1, int x2, int y2, char *adr, int line);
//void	trace_yx(int x1, int y1, int x2, int y2, char *adr, int line);
int 	*strsplit_two(char const *s, char c, char d);
void	trace(int x1, int y1, int x2, int y2, char *adr, int line);
int		get_info_map(int i, char *buf);
void	start_window(char **map, t_coord *pt, t_tool *t, int *buf);
void	pixel_put(char *adr, int x, int y, int color, int line);
int		ft_key(int keycode, void *param);

#endif
