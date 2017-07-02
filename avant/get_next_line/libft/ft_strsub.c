/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:29:10 by ltran             #+#    #+#             */
/*   Updated: 2017/02/15 19:38:56 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*troncon;

	i = -1;
	if (!s || !(troncon = (char *)malloc((sizeof(char) * (len + 1)))))
		return (NULL);
	while (++i < len)
	{
		troncon[i] = s[start];
		start++;
	}
	troncon[i] = '\0';
	return (troncon);
}
