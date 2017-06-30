/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:19:18 by ltran             #+#    #+#             */
/*   Updated: 2017/02/15 19:01:58 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	i = -1;
	if (!s || !(ret = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
		return (NULL);
	while (s[++i])
		ret[i] = f(i, s[i]);
	ret[i] = '\0';
	return (ret);
}
