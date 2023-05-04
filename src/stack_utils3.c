/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:49:48 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 17:50:30 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top->next;
	if (stack->size == 1)
		return (1);
	while (tmp->next != stack->bottom)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_sorted_rev(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top->next;
	if (stack->size == 1)
		return (1);
	while (tmp->next != stack->bottom)
	{
		if (tmp->data < tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
