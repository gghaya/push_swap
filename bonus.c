/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:41:38 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/09 22:16:24 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheker_bonus(t_node *stack_a)
{
	char	*ligne;
	t_node	*stack_b;

	ligne = get_next_line(0);
	stack_b = 0;
	while (ligne)
	{
		if (ft_strncmp(ligne, "sa\n", 3) == 0
			|| ft_strncmp(ligne, "sb\n", 3) == 0
			|| ft_strncmp(ligne, "ra\n", 3) == 0
			|| ft_strncmp(ligne, "rb\n", 3) == 0
			|| ft_strncmp(ligne, "rra\n", 4) == 0
			|| ft_strncmp(ligne, "rrb\n", 4) == 0)
			compare1(ligne, &stack_a, &stack_b);
		else if (ft_strncmp(ligne, "pa\n", 3) == 0
			|| ft_strncmp(ligne, "pb\n", 3) == 0
			|| ft_strncmp(ligne, "rrr\n", 4) == 0
			|| ft_strncmp(ligne, "ss\n", 3) == 0)
			compare2(ligne, &stack_a, &stack_b);
		else
			write_error();
		free (ligne);
		ligne = get_next_line(0);
	}
	check(&stack_a, &stack_b);
}

int	ft_strncmp(const char *first, const char *second, size_t n)
{
	unsigned char	*f ;
	unsigned char	*s;
	size_t			i;

	f = (unsigned char *)first;
	s = (unsigned char *)second;
	i = 0;
	while ((f[i] || s[i]) && i < n)
	{
		if (f[i] != s[i])
			return ((unsigned char )f[i] - (unsigned char )s[i]);
		i++;
	}
	return (0);
}

void	check(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;

	head = *stack_a;
	while (head)
	{
		if (head->next && head->position > head->next->position)
		{
			write(1, "KO", 2);
			exit(1);
		}
		head = head->next;
	}
	if (ft_lstsize(*stack_b) == 0)
		write(1, "OK", 2);
	else
	{
		write(1, "KO", 2);
		exit (1);
	}
	ft_lstclear(stack_a);
}

void	compare1(char *ligne, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(ligne, "sa\n", 3) == 0)
		swap(stack_a);
	else if (ft_strncmp(ligne, "sb\n", 3) == 0)
		swap(stack_b);
	else if (ft_strncmp(ligne, "ra\n", 3) == 0)
		rot(stack_a);
	else if (ft_strncmp(ligne, "rb\n", 3) == 0)
		rot(stack_b);
	else if (ft_strncmp(ligne, "rra\n", 4) == 0)
		revrot(stack_a);
	else if (ft_strncmp(ligne, "rrb\n", 4) == 0)
		revrot(stack_b);
}

void	compare2(char *ligne, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(ligne, "pa\n", 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(ligne, "pb\n", 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(ligne, "rrr\n", 4) == 0)
	{
		revrot(stack_a);
		revrot(stack_b);
	}
	else if (ft_strncmp(ligne, "ss\n", 3) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
}
