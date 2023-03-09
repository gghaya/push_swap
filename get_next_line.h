/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:24:32 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/08 00:31:12 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ftstrjoin(char *s1, char *s2);
char	*ftsubstr(char *s, unsigned int start, size_t len);
int		ftstrchr(char *buf, char c);
char	*get_next_line(int fd);
size_t	ftstrlen(const char *s);
char	*save(char *str);
char	*newligne(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);

#endif
