/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:56:10 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 13:28:40 by kkaiyawo         ###   ########.fr       */
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

	if (DEBUG == 0)
		return ;
	tmp = stack->a_top;
	ft_putstr_fd("A | ", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->data + INT_MIN, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
	tmp = stack->b_top;
	ft_putstr_fd("B | ", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->data + INT_MIN, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}

void	ft_push_back(t_node *stack, long data)
{
	t_node	*ptr;

	ptr = stack;
	if (ptr == NULL)
	{
		ptr = (t_node *) malloc(sizeof(t_node));
		ptr->data = data;
		ptr->next = NULL;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = (t_node *) malloc(sizeof(t_node));
	ptr->next->data = data;
	ptr->next->next = NULL;
}

int	ft_stack_size(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
