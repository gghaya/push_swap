/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:13:41 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/08 22:38:29 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		while (j > i)
		{
			if (tab[j - 1] > tab[j])
			{
				temp = tab[j];
				tab[j] = tab [j - 1];
				tab[j - 1] = temp;
			}
			j--;
		}
		i++;
	}
	return (tab);
}

int	getmin(t_node *head)
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

int	getmax(t_node *head)
{
	t_node	*p;
	int		max;

	p = head;
	max = p->position;
	while (p->next)
	{
		if (max < p->position)
			max = p->position;
		p = p->next;
	}
	if (max < p->position)
		max = p->position;
	return (max);
}

int	getindex(t_node *head, int data)
{
	int	i;

	i = 1;
	while (head)
	{
		if (head->position != data)
			i++;
		else
			break ;
		head = head->next;
	}
	return (i);
}

void	push_min(t_node **stack_a, t_node **stack_b)
{
	int		indexmin;
	int		midlle;
	t_node	*p;

	p = (*stack_a);
	indexmin = getindexx(p, getminn(p));
	midlle = ft_lstsize((*stack_a)) / 2;
	while (indexmin != 1)
	{
		if (indexmin > 2)
			rra(stack_a);
		else
			sa(stack_a);
		indexmin = getindexx((*stack_a), getminn((*stack_a)));
	}
	pb(stack_a, stack_b);
}
