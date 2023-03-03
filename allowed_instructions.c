/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:14:14 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/03 01:33:52 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap(t_node **stack_a)
{
	int tmp;
	int p;

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
void	sa(t_node ** stack_a)
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
	write(1, "ss\n", 3);
}

void	rot(t_node **stack)
{
	t_node	*tmp;

	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp ->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	ra(t_node **stack_a)
{
	rot(stack_a);
	write (1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	rot(stack_b);
	write(1, "rb\n", 3);
}
void	rr(t_node **stack_a, t_node **stack_b)
{
	rot(stack_a);
	rot(stack_b);
	write(1, "rr\n", 3);
}

void	revrot(t_node **stack)
{
	t_node	*last;

	last = ft_lstlast(*stack);
	ft_lstadd_front(stack, last);
}

void	rra(t_node **stack_a)
{
	revrot(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack_b)
{
	revrot(stack_b);
	write(1, "rrb\n", 4);
}

void rrr(t_node **stack_a, t_node **stack_b)
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
	push(stack_a,stack_b);
	write (1, "pa\n", 3);
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	push(stack_a,stack_b);
	write (1, "pb\n", 4);
}


// int main (int argc, char *argv[])
// {
// 	t_node * stack_a;
// 	// t_node * stack;
// 	t_node * stack_b;
// 	stack_a = parcing(argc,argv);
// // = ft_lstnew(8);//8 1 7  6->  6 8 1 7
// // 	ft_lstadd_back(&stack_a, ft_lstnew(4));
// // 	ft_lstadd_back(&stack_a, ft_lstnew(-7));
// // 	ft_lstadd_back(&stack_a, ft_lstnew(0));
// 	stack_b = NULL;//8 1 7 ->  7 8 1
// 	// ft_lstadd_back(&stack_b, ft_lstnew(7));
// 	// ft_lstadd_back(&stack_b, ft_lstnew(5));
// 	// sort_3(&stack_a);
// 	mainsort(&stack_a,&stack_b);
// // 	pb(&stack_a, &stack_b);
// // 	pb(&stack_a, &stack_b);
// 	// stack = stack_a;
// 	// ra(&stack_a);
// 	// ra(&stack_a);
// 	// printf("%d", getindex (stack_a, 6879));
// 	while (stack_a != NULL)
// 	{
// 		printf(" %d || ", (stack_a)->data);
// 		stack_a = (stack_a)->next;
// 	}
// 	// printf("\n");

// 	// printf("\n stack_b");
// 	// while (stack_b != NULL)
// 	// {
// 	// 	printf("%d ||", (stack_b)->data);
// 	// 	stack_b = (stack_b)->next;
// 	// }
// 	return 0;
// }