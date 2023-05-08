/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:56:01 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 18:14:13by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *stack, char **arg, int argc)
{
	ssize_t	i;
	long	data;

	i = -1;
	while (arg[++i])
	{
		if (is_int(arg[i]))
		{
			data = ft_atol(arg[i]) + INT_MAX + 1;
			stack->a_top = ft_push_front(stack->a_top, data);
		}
		else
			free_exit(arg, stack, 255);
	}
	if (ft_stack_size(stack->a_top) != i)
		free_exit(arg, stack, 255);
	if (ft_stack_size(stack->a_top) < argc - 1)
		free_exit(arg, stack, 255);
	if (is_duplicate(stack->a_top))
		free_exit(arg, stack, 255);
	free_all(arg, NULL);
}

void	ft_push(t_node **s_from, t_node **s_to)
{
	t_node	*tmp;

	if (ft_stack_size(*s_from) == 0)
		return ;
	tmp = *s_from;
	*s_from = (*s_from)->next;
	tmp->next = *s_to;
	*s_to = tmp;
}

void	ft_swap(t_node **stack)
{
	t_node	*tmp;

	if (ft_stack_size(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	ft_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*ptr;

	if (ft_stack_size(*stack) < 2)
		return ;
	if (ft_stack_size(*stack) == 2)
	{
		ft_swap(stack);
		return ;
	}
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ptr = *stack;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
}

void	ft_reverse_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*ptr;

	if (ft_stack_size(*stack) < 2)
		return ;
	if (ft_stack_size(*stack) == 2)
	{
		ft_swap(stack);
		return ;
	}
	tmp = *stack;
	ptr = (*stack)->next;
	while (ptr->next != NULL)
	{
		tmp = tmp->next;
		ptr = ptr->next;
	}
	tmp->next = NULL;
	ptr->next = *stack;
	*stack = ptr;
}
