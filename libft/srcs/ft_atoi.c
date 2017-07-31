/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <ltran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:34:43 by ltran             #+#    #+#             */
/*   Updated: 2017/07/31 18:53:36 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int				ft_atoi(const char *str)
{
	unsigned int		nb;
	int					ent;
	int					sgn;

	nb = 0;
	ent = 0;
	sgn = 0;
	while (*str == '\f' || *str == '\v' || *str == '\r' ||
		*str == '\n' || *str == ' ' || *str == '\t')
		++str;
	if (*str == '-' && ft_strlen(str) >= 10 &&
			ft_strcmp("-2147483648", str) >= 0)
		return (-2147483648);
	if (*str == '+' || ((*str == '-') && (sgn = 1)))
		++str;
	if (ft_strlen(str) >= 10 && ft_strcmp("2147483647", str) >= 0)
		return (2147483647);
	else if (!ft_isdigit(*str))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		++str;
	}
	return (nb = (sgn == 1) ? -(nb) : nb);
}
