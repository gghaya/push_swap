/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:09:35 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/02 23:17:37 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getdemistack(t_node *stack_a)
{
	int	demi;

	demi = ft_lstsize(stack_a) / 2;
	return (demi);
}

int	getposition(t_node *stack_a, int p)
{
	int	i;

	i = 1;
	while (stack_a)
	{
		if (stack_a->position != p)
			i++;
		else
			break ;
		stack_a = stack_a->next;
	}
	return (i);
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*tmp;
	t_node	*last;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	last = lst;
	if (tmp ->next == NULL)
		return (tmp);
	while (tmp)
	{
		if (tmp->next->next == NULL)
		{
			tmp = tmp->next;
			break ;
		}
		last = last->next;
		tmp = tmp->next;
	}
	last->next = NULL;
	return (tmp);
}

void	fillin(t_node **stack_a, t_node **stack_b, int i, int j)
{
	t_node	*head;

	head = *stack_a;
	while (ft_lstsize(*stack_a) > 0)
	{
		if (head->position < i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if (head->position < (i + j))
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
		head = *stack_a;
		if (ft_lstsize(*stack_b) > 1)
			if ((*stack_b)->position < (*stack_b)->next->position)
				sb(stack_b);
	}
}
