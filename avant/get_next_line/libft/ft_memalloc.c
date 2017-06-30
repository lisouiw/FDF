/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:16:36 by ltran             #+#    #+#             */
/*   Updated: 2017/02/15 18:52:10 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mo;

	if (!(mo = (char *)malloc(size * sizeof(mo))))
		return (NULL);
	ft_bzero(mo, size);
	return (mo);
}
