/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:10:02 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/08 01:19:45 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc(ftstrlen(s1) + 1);
	if (str == 0)
		return (NULL);
	ft_memcpy (str, s1, ftstrlen(s1));
	str[ftstrlen(s1)] = '\0';
	return (str);
}

char	*newligne(char	*str)
{
	if (!str)
	{
		free (str);
		return (NULL);
	}
	if (str != NULL && ftstrchr(str, '\n') != -1)
	{
		return (ftsubstr(str, 0, ftstrchr(str, '\n') + 1));
	}
	if (str != NULL && ftstrchr(str, '\n') == -1)
	{
		return (str);
	}
	return (NULL);
}

char	*save(char	*str)
{
	int		len;
	char	*s;

	s = NULL;
	if (!str)
		return (free (str), str = NULL, NULL);
	if (ftstrchr(str, '\n') != -1)
	{
		len = ftstrlen(str) - ftstrchr(str, '\n') + 1;
		s = ftsubstr(str, ftstrchr(str, '\n') + 1, len);
		free(str);
		str = s;
		return (str);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*statvar;
	int			nbytes;
	char		*newl;
	char		*tmp;
	char		*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(statvar), statvar = NULL, NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (free(buf), free(statvar), statvar = NULL, NULL);
	nbytes = 1;
	while (nbytes > 0 && ftstrchr(statvar, '\n') == -1)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		buf[nbytes] = '\0';
		tmp = ftstrjoin(statvar, buf);
		free (statvar);
		statvar = tmp;
		if (statvar[0] == '\0')
			return (free(buf), buf = NULL, free(statvar), statvar = NULL, NULL);
	}
	newl = newligne(statvar);
	statvar = save(statvar);
	return (free(buf), buf = NULL, newl);
}
