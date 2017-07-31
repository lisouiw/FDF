/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:01:02 by ltran             #+#    #+#             */
/*   Updated: 2017/07/31 23:10:43 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		size_w(char *s, int *n, char c, char d)
{
	int		i;

	i = 0;
	while (s[*n])
	{
		if (s[*n] != c && s[*n] != d)
		{
			while (s[*n + i] != c && s[*n + i] != d && s[*n + i] != '\0')
			{
				++i;
				if (s[*n + i - 1] == ',')
					s[*n + i - 1] = '\0';
			}
			*n += i;
			return (ft_atoi(ft_strsub(s, *n - i, i)));
		}
		++(*n);
	}
	return (0);
}

int		*nb_word(char *s, char c, char d, int *w)
{
	int		i;
	int		*spl;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c || s[i] == d)
			i++;
		else
		{
			while (s[i] != c && s[i] != d && s[i] != '\0')
				++i;
			++(*w);
		}
	}
	spl = (int*)malloc((*w + 1) * sizeof(int));
	spl[*w] = 0;
	return (spl);
}

int		*strsplit_two(char *s, char c, char d)
{
	int		*spl;
	int		w;
	int		i;
	int		n;

	n = 0;
	i = -1;
	w = 0;
	if ((spl = nb_word(s, c, d, &w)) == NULL)
		return (NULL);
	while (++i < w)
	{
		spl[i] = (int)malloc(sizeof(int));
		spl[i] = size_w(s, &n, c, d);
		if (spl[i] > 1300)
			spl[i] = 1300;
	}
	return (spl);
}
