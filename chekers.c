/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:54:26 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/03 01:10:16 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	chekerduplication(int *numbers, int j)
{
	int	i;

	i = 0;
	while (j > i)
	{
		if (numbers[j] == numbers[i])
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	chekersorted(int *numbers, int len)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < len - 1)
	{
		if (numbers[i] > numbers[i + 1])
			k += 1;
		i++;
	}
	if (k == 0)
	{
		write(1, "Error2\n", 6);
		exit(1);
	}
}
