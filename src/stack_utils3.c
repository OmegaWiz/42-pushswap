/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:49:48 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 14:59:56 by kkaiyawo         ###   ########.fr       */
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
