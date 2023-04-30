/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:03:40 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/30 22:45:30 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->bottom->prev;
	stack->bottom->prev = tmp->prev;
	tmp->prev->next = stack->bottom;
	tmp->next = stack->top->next;
	tmp->prev = stack->top;
	stack->top->next->prev = tmp;
	stack->top->next = tmp;
}

void	ft_print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top->next;
	if (DEBUG == 0)
		return ;
	while (tmp != stack->bottom)
	{
		ft_putnbr_fd(tmp->data + INT_MIN, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}
int		is_sorted(t_stack *stack)
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
