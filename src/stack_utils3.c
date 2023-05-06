/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:49:48 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 19:56:43 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_sorted_rev(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	swap_long(long *a, long *b)
{
	long	t;

	t = *a;
	*a = *b;
	*b = t;
}

long	ft_mid_index(t_node *sa)
{
	long	arr[5];
	int		i;
	int		j;
	t_node	*tmp;

	i = -1;
	tmp = sa;
	while (tmp)
	{
		arr[++i] = tmp->index;
		tmp = tmp->next;
	}
	while (++i < 10)
	{
		j = -1;
		while (++j < 5 - (i - 5) - 1)
		{
			if (arr[j] < arr[j + 1])
			{
				swap_long(&arr[j], &arr[j + 1]);
			}
		}
	}
	return (arr[2]);
}

long	ft_max_index(t_node *sa)
{
	t_node	*tmp;
	long	mx;

	tmp = sa;
	mx = tmp->index;
	while (tmp)
	{
		if (tmp->index > mx)
			mx = tmp->index;
		tmp = tmp->next;
	}
	return (mx);
}
