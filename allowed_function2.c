/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_function2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 00:58:33 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/05 16:11:27 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rrb(t_node **stack_b)
{
	revrot(stack_b);
	write (1, "rrb\n", 4);
}

void	revrot(t_node **stack)
{
	t_node	*last;

	last = ft_lstlast(*stack);
	ft_lstadd_front(stack, last);
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
	write (1, "pb\n", 3);
}
