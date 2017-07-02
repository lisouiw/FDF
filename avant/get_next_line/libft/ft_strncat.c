/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:54:02 by ltran             #+#    #+#             */
/*   Updated: 2016/11/30 22:25:53 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict dst, const char *restrict src, size_t n)
{
	unsigned int	i;
	unsigned int	c;

	i = ft_strlen(dst);
	c = 0;
	while (c < n && src[c] != '\0')
		dst[i++] = src[c++];
	dst[i++] = '\0';
	return (dst);
}
