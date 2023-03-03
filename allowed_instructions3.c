/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_instructions3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:23:42 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/03 01:26:17 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rra(t_node **stack_a)
{
	revrot(stack_a);
	write (1, "rra\n", 4);
}

void	ra(t_node **stack_a)
{
	rot(stack_a);
	write (1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	rot(stack_b);
	write (1, "rb\n", 3);
}