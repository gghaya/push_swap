/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_function2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:58:33 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/03 01:23:22 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rrb(t_node **stack_b)
{
	revrot(stack_b);
	write (1, "rrb\n", 4);
}


void	rrr(t_node **stack_a, t_node **stack_b)
{
	revrot(stack_a);
	revrot(stack_b);
	write(1, "rrr\n", 4);
}

void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (stack_b && *stack_b)
	{
		tmp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		tmp->next = NULL;
		ft_lstadd_front(stack_a, tmp);
	}
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	write (1, "pa\n", 3);
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	push(stack_a, stack_b);
	write (1, "pb\n", 4);
}

