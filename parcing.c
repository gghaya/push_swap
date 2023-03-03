/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gghaya <gghaya@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 23:14:36 by gghaya            #+#    #+#             */
/*   Updated: 2023/03/03 01:56:25 by gghaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*parcing(int argc, char *argv[])
{
	int		*numbers;
	int		j;
	int		len;
	char	**splitedtab;

	j = 0;
	len = 0;
	splitedtab = returnsplitedtab(argc, argv);
	while (splitedtab[len] != NULL)
		len++;
	numbers = malloc(len * sizeof(int));
	while (splitedtab[j])
	{
		if (ft_isdigit(splitedtab[j]) == 1)
			numbers[j] = ft_atoi(splitedtab[j]);
		else
		{
			printf("Error1\n");
			exit(1);
		}
		chekerduplication(numbers, j);
		j++;
	}
	chekersorted(numbers, len);
	return (ft_create_list(numbers, len));
}

t_node	*ft_create_list(int *numbers, int len)
{
	t_node	*head;
	t_node	*current;
	int		*sortednumbers;
	int		i;

	head = NULL;
	i = 0;
	while (i < len)
	{
		current = ft_lstnew(numbers[i++]);
		ft_lstadd_back(&head, current);
		current->position = 0;
		current = current->next;
	}
	sortednumbers = ft_sort_int_tab(numbers, len);
	fct (sortednumbers, head, len);
	return (head);
}

void	fct(int *sortednumber, t_node *liste, int len)
{
	int		i;
	t_node	*head;

	i = 0;
	while (i < len)
	{
		head = liste;
		while (head)
		{
			if (sortednumber[i] == head->data)
				head->position = i + 1;
			head = head->next;
		}
		i++;
	}
}

char	**returnsplitedtab(int argc, char *argv[])
{
	char	**arguments;
	char	**splitedtab;
	char	*jointure;
	int		i;

	i = 1;
	jointure = NULL;
	arguments = (char **)malloc((argc + 1) * sizeof(char *));
	while (i < argc)
	{
		arguments[i - 1] = argv[i];
		i++;
	}
	jointure = ft_strjoin(argc - 1, arguments, " ");
	splitedtab = ft_split(jointure, ' ');
	return (splitedtab);
}
