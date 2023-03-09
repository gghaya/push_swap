/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:14:14 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/08 02:00:37 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_node **stack_a)
{
	int	tmp;
	int	p;

	if ((*stack_a)->next != NULL)
	{
		tmp = (*stack_a)->data;
		p = (*stack_a)->position;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->position = (*stack_a)->next->position;
		(*stack_a)->next->position = p;
		(*stack_a)->next->data = tmp;
	}
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	write (1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	write (1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write (1, "ss\n", 3);
}

void	rot(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack);
	if (tmp != NULL)
	{
		(*stack) = (*stack)->next;
		tmp ->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
}
