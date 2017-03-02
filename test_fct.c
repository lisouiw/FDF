/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 09:04:58 by ltran             #+#    #+#             */
/*   Updated: 2017/02/28 09:18:39 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	*ft_strrchr(const char *s, int c);

int		main()
{
	char	*str = "sjsjhs\neeee\nhddj";

	printf("|%s| ",str = ft_strrchr(str, '\n'));
	printf("lenght = %lu\n", strlen(str));
	return (0);
}
