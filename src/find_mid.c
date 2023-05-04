/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:15:22 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 16:39:56 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_long(long *a, long *b)
{
	long	t;

	t = *a;
	*a = *b;
	*b = t;
}

long	find_mid(t_stack *s, int n)
{
	t_node	*tmp;
	long	mx[6];
	int		i;
	int		j;

	tmp = s->top->next;
	i = 0;
	while (++i <= (n + 1) / 2)
		mx[i] = INT_MIN;
	i = 0;
	while (++i <= n)
	{
		j = 0;
		mx[j] = tmp->data;
		while (++j <= (n + 1) / 2)
		{
			if (mx[j] < mx[j - 1])
				swap_long(mx + j, mx + j - 1);
		}
		tmp = tmp->next;
	}
	return (mx[1]);
}
