/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:23:59 by ltran             #+#    #+#             */
/*   Updated: 2017/06/30 15:35:37 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			*ft_itoa(int n)
{
	int		i;
	int		tmp;
	char	*tab;

	tmp = n;
	i = tmp < 0 ? 2 : 1;
	tmp = (tmp < 0) ? tmp * (-1) : tmp;
	while ((tmp = tmp / 10) > 0)
		++i;
	if (!(tab = (char*)malloc((sizeof(char)) * (i + 1))))
		return (NULL);
	tab[i] = '\0';
	tab[0] = '-';
	tmp = n < 0 ? 0 : -1;
	n = n < 0 ? n * -1 : n;
	while (--i > tmp && (tab[i] = (n % 10) + '0'))
		n = n / 10;
	return (tab);
}
