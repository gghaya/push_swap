/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 18:36:51 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/02 23:20:27 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc == 1)
		exit (0);
	if (argc >= 2)
	{
		stack_a = parcing (argc, argv);
		if (ft_lstsize(stack_a) == 3)
			sort_3(&stack_a);
		else if (ft_lstsize(stack_a) == 4)
			sort_4(&stack_a, &stack_b);
		else if (ft_lstsize(stack_a) == 5)
			sort_5(&stack_a, &stack_b);
		else
			mainsort(&stack_a, &stack_b);
	}
	while(stack_a)
	{
		printf("%d || ",(stack_a)->data);
		(stack_a) = (stack_a)->next;
	}
}
