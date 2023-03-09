/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:37:31 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/09 00:39:42 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	size_total(char **strs, char *sep, int size)
{
	int	i;
	int	tlen;

	i = 0;
	tlen = 0;
	while (i < size)
	{
		tlen += ft_strlen(strs[i]);
		i++;
	}
	tlen += ft_strlen(sep) * (size - 1);
	return (tlen);
}

char	*ft_strjoin(int size, char **strs, char *sep, int i)
{
	int		j;
	int		k;
	char	*s;
	int		f;

	s = (char *)malloc(sizeof(char) * (size_total(strs, sep, size) + 1));
	k = 0;
	f = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			if (ft_digit(strs[i][j]))
				f = 1;
			s[k++] = strs[i][j++];
		}
		if (f == 0)
			write_error();
		j = 0;
		while (sep[j] && i < size - 1)
			s[k++] = sep[j++];
		i++;
	}
	return (s[k] = '\0', s);
}
