/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:05:14 by ltran             #+#    #+#             */
/*   Updated: 2017/02/15 19:38:29 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strdup(const char *s)
{
	int		i;
	char	*tab;

	i = -1;
	if (!(tab = (char *)malloc((ft_strlen(s) + 1) * sizeof(*tab))))
		return (NULL);
	while (s[++i])
		tab[i] = s[i];
	tab[i] = '\0';
	return (tab);
}
