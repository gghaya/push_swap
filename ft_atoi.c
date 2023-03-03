/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:53:44 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/03 02:04:36 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

int	ft_atoi(const char *str)
{
	long int	n;
	int			i;
	int			sign;

	i = 0 ;
	n = 0 ;
	sign = 1 ;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == 32
			|| str[i + 1] == '\0' || (str[i + 1] >= 9 && str[i + 1] <= 13))
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
			n = n * 10 + str[i] - 48 ;
			i++;
	}
	return (ft_erreur(n, sign));
}

int	ft_erreur(long int n, int sign)
{
	if (n * sign < -2147483646 || n * sign > 2147483647)
	{
		printf("Error\n");
		exit (1);
	}
	return (n * sign);
}
