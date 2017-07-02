/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:25:16 by ltran             #+#    #+#             */
/*   Updated: 2017/02/15 18:55:11 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char				*new;

	if (!(new = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
