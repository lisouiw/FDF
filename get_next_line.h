/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 00:39:56 by ltran             #+#    #+#             */
/*   Updated: 2017/05/11 17:43:31 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 3000

# include "./libft/libft.h"
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_read(int fd, char *buf, int r);

#endif
