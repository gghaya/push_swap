/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:30:16 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/03 02:05:00 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include<stdio.h>

typedef struct node
{
	int			data;
	struct node	*next;
	int			position;
}	t_node;

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		ft_isdigit(char *s);
char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char const *s, char c);
void	freeall(char **c, int i);
char	*ft_substr(char const *s, int start, int len);
t_node	*parcing(int argc, char *argv[]);
void	chekerduplication(int *numbers, int j);
void	chekersorted(int *numbers, int len);
t_node	*ft_lstnew(int content);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);
void	ft_lstclear(t_node **lst, void (*del)(int));
void	ft_lstadd_front(t_node **lst, t_node *new);
t_node	*ft_create_list(int *numbers, int len);
t_node	*ft_lstlast(t_node *lst);
void	sort_3(t_node **stack_a);
void	sort_4(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	rot(t_node **stack);
void	ra(t_node **stack_a);
void	rra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rrb(t_node **stack_b);
void	swap(t_node **stack_a);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	revrot(t_node **stack);
void	push(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
void	pa(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **stack_a, t_node **stack_b);
void	fct(int *sortednumber, t_node *liste, int len);
int		*ft_sort_int_tab(int *tab, int size);
int		getmin( t_node *head);
int		getmax( t_node *head);
int		getindex(t_node *head, int data);
void	push_min(t_node **stack_a, t_node **stack_b);
void	mainsort(t_node **stack_a, t_node **stack_b);
void	fillin_stack_a(t_node **stack_a, t_node **stack_b);
void	fillin(t_node **stack_a, t_node **stack_b, int i, int j);
int		getdemistack(t_node *stack_a);
char	**returnsplitedtab(int argc, char *argv[]);
int		ft_erreur(long int n, int sign);
#endif
