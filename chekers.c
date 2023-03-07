/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:54:26 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/05 16:35:13 by gghaya           ###   ########.fr       */
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
			write(1, "Error1\n", 6);
			exit(1);
		}
		i++;
	}
}

void	chekersorted(int *numbers, int len, int argc)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (argc == 2 && len == 1)
		exit(1);
	while (i < len - 1)
	{
		if (numbers[i] > numbers[i + 1])
			k += 1;
		i++;
	}
	if (k == 0)
		exit(1);
}
