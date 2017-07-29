/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <ltran@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:34:43 by ltran             #+#    #+#             */
/*   Updated: 2017/07/29 17:54:06 by ltran            ###   ########.fr       */
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
	if (*str == '-' && ft_strcmp(str, "-2147483648") > 0)
		return (-2147483648);
	if (ft_strcmp(str, "+2147483647") > 0 || ft_strcmp(str, "2147483647") > 0)
		return (2147483647);
	while (*str == '\f' || *str == '\v' || *str == '\r' ||
		*str == '\n' || *str == ' ' || *str == '\t')
		++str;
	if (*str == '+' || ((*str == '-') && (sgn = 1)))
		++str;
	else if (!ft_isdigit(*str))
		return (0);
	while (*str >= '0' && *str <= '9' && (ent = *str - 48))
	{
		nb = nb * 10 + ent;
		++str;
	}
	return (nb = (sgn == 1) ? -(nb) : nb);
}
