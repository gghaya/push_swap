/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fctsupplimentaires.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:38:58 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/08 22:43:12 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getminn(t_node *head)
{
	t_node	*p;
	int		min;

	min = head->data;
	p = head;
	while (p)
	{
		if (p->next && min > p->next->data)
			min = p->next->data;
		p = p->next;
	}
	return (min);
}

int	getmaxx(t_node *head)
{
	t_node	*p;
	int		max;

	max = head->data;
	p = head;
	while (p)
	{
		if (p->next && max < p->next->data)
			max = p->next->data;
		p = p->next;
	}
	return (max);
}

int	getindexx(t_node *head, int data)
{
	int	i;

	i = 1;
	while (head)
	{
		if (head->data != data)
			i++;
		else
			break ;
		head = head->next;
	}
	return (i);
}
