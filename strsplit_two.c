/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:01:02 by ltran             #+#    #+#             */
/*   Updated: 2017/07/10 18:54:02 by ltran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		**nb_word(const char *s, char c, char d, int *w)
{
	int			i;
	char		**spl;

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
	printf("W %i\n", *w);
	spl = (char**)malloc((*w + 1) *sizeof(char*));
	spl[*w] = NULL;
	return (spl);
}

static char		*size_w(char const *s, int *n, char c, char d)
{
	while (s[*n] == c || s[*n] == d || s[*n])
		++n;

	return (NULL);
}

char			**strsplit_two(char const *s, char c, char d)
{
	char	**spl;
	int		w;
	int		i;
	int		n;

	i = -1;
	w = 0;
	if ((spl = nb_word(s, c, d, &w)) == NULL)
		return (NULL);
	while (++i < w)
	{
		spl[i] = size_w(s, &n, c, d);
		printf("S = %s\n", n);
	}
	return (spl);
}

int		main(int ac, char **av)
{
	char	**buf;
	int		i = -1;

	buf = strsplit_two(" \n  shs jks \n 1 22 sjsk ", ' ', '\n');
//	while (buf[++i])
//		printf("-> |%s|\n", buf[i]);
}
