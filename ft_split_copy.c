/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:15:14 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/02 01:36:53 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int	countwords(const char *str, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && c == str[i])
			i++;
		if (str[i])
			k++;
		while (str[i] && c != str[i])
			i++;
	}
	return (k);
}

void	freeall(char **c, int i)
{
	while (i >= 0)
	{
		free(c[i]);
		i--;
	}
	free(c);
}

static char	**ft_fct(const char *s, char c, int i, int k)
{
	int		start;
	char	**rslt;

	rslt = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!rslt)
		return (0);
	while (++k < countwords(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		rslt[k] = ft_substr(s, start, i - start);
		if (rslt[k] == NULL)
		{
			freeall (rslt, k);
			return (NULL);
		}
	}
	rslt[k] = 0;
	return (rslt);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_fct(s, c, 0, -1));
}
