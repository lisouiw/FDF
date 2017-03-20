/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:56:01 by ltran             #+#    #+#             */
/*   Updated: 2017/03/20 17:15:51 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define X 2600
#define Y 1400
#define BUFF_SIZE 200000

#include "mlx.h"
#include "../libft/libft.h"
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef	struct		s_l
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bit;
	int		size;
	int		endian;
	char	*addr;
	int		fd;
	int		rd;
	int		height;
	int 	width;
}					t_l;

int		ft_map_sqr(char *map, int len, int x, int *y);
char	*ft_replace_char(char *str, char c, char r);
int		*ft_array_int(char **pt, int len, int x, int width);
void	ft_isometrie(int *x1, int *y1, int *x2, int *y2);
int		ft_get_point(int x1, int y1, int x2, int y2, t_l *info);
void	ft_diagonal_ey(int ex, int ey, int x1, int y1, int x2, int y2, t_l *info);
void	ft_diagonal_ex(int ex, int ey, int x1, int y1, int x2, int y2, t_l *info);
void	ft_pixel_put(t_l *info, int x, int y, int color);
int		ft_key(int keycode, void *param);

#endif
