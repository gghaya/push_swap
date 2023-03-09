/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:24:18 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/08 01:20:04 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstt;
	unsigned char	*srcc;
	size_t			i;

	dstt = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	i = 0;
	if (dstt == srcc)
		return (dstt);
	if (dst != 0 || src != 0)
	{
		while (i < n)
		{
			dstt[i] = srcc[i];
			i++;
		}
		return (dstt);
	}
	return (0);
}

char	*ftstrjoin(char *s1, char *s2)
{
	char	*concat;
	size_t	len;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (free(s1), NULL);
	len = ftstrlen(s1) + ftstrlen(s2);
	concat = (char *)malloc(len + 1);
	if (!concat)
		return (NULL);
	ft_memcpy (concat, s1, ftstrlen(s1));
	ft_memcpy (concat + ftstrlen(s1), s2, ftstrlen(s2));
	concat[len] = '\0';
	return (concat);
}

char	*ftsubstr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len + start >= ftstrlen(s))
		len = ftstrlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ftstrchr(char *buff, char c)
{
	int	i;

	i = 0;
	if (!buff)
		return (-1);
	while (buff[i])
	{
		if (buff[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

size_t	ftstrlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
