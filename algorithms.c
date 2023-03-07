/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:48:26 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/05 17:19:03 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_3(t_node **stack_a)
{
	int	max;
	int	min;
	int	diff;

	min = getindex(*stack_a, getmin(*stack_a));
	max = getindex(*stack_a, getmax(*stack_a));
	diff = max - min;
	if (diff == -1)
	{
		if (max == 1)
			ra(stack_a);
		else
			rra(stack_a);
	}
	else if (diff == 1)
	{
		sa(stack_a);
		if (max == 2)
			ra(stack_a);
	}
	else
	{
		ra(stack_a);
		sa(stack_a);
	}
}

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	push_min(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	push_min(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
	system("leaks push_swap");
}

void	fillin_stack_a(t_node **stack_a, t_node **stack_b)
{
	int	pos;
	int	middle;
	int	i;

	while (ft_lstsize(*stack_b) > 0)
	{
		if (*stack_b)
		{
			i = 0;
			pos = getindex(*stack_b, getmax(*stack_b));
			middle = getindex(*stack_b, getdemistack(*stack_b));
			if (pos <= middle)
			{
				while (i++ < pos - 1)
					rb(stack_b);
				pa(stack_a, stack_b);
			}
			else if (pos > middle)
			{
				while (i++ < ft_lstsize(*stack_b) - pos + 1)
					rrb(stack_b);
				pa(stack_a, stack_b);
			}
		}
	}
}

void	mainsort(t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;
	t_node	*p;

	i = 1;
	j = 15;
	if (ft_lstsize(*stack_a) > 250)
		j = 25;
	p = *stack_a;
	fillin(stack_a, stack_b, i, j);
	fillin_stack_a(stack_a, stack_b);
}
