/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:56:10 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 14:26:31 by kkaiyawo         ###   ########.fr       */
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

void	ft_print_stack(t_stack *sa, t_stack *sb)
{
	t_node	*tmp;

	if (DEBUG == 0)
		return ;
	tmp = sa->top->next;
	ft_putstr_fd("sa | ")
	while (tmp != stack->bottom)
	{
		ft_putnbr_fd(tmp->data + INT_MIN, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
	tmp = sb->top->next;
	ft_putstr_fd("sb | ")
	while (tmp != stack->bottom)
	{
		ft_putnbr_fd(tmp->data + INT_MIN, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}

void	ft_push_back(t_stack *sa, t_stack *sb)
{
	while (sb->size > 0)
	{
		ft_push(sa, sb->top->next->data);
		ft_pop(sb);
		ft_putstr_fd("pa\n", 1);
	}
	ft_print_stack(sa);
	ft_print_stack(sb);
}

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
