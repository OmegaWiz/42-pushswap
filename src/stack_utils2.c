/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:56:10 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/08 12:32:28 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	ft_print_stack2(t_node *sa, t_node *sb)
{
	t_node	*tmp;

	if (DEBUG == 0)
		return ;
	tmp = sa;
	ft_putstr_fd("A | ", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->data + INT_MIN, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
	tmp = sb;
	ft_putstr_fd("B | ", 1);
	while (tmp)
	{
		ft_putnbr_fd(tmp->data + INT_MIN, 1);
		ft_putchar_fd(' ', 1);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}

t_node	*ft_push_front(t_node *stack, long data)
{
	t_node	*ptr;

	ptr = malloc(sizeof(t_node));
	if (ptr == NULL)
	{
		while (stack)
		{
			ptr = stack->next;
			free(stack);
			stack = ptr;
		}
		return (NULL);
	}
	ptr->data = data;
	ptr->index = -1;
	if (stack == NULL)
	{
		ptr->next = NULL;
		return (ptr);
	}
	ptr->next = stack;
	stack = ptr;
	return (ptr);
}

int	ft_stack_size(t_node *stack)
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

void	ft_stack_index(t_node *stack)
{
	t_node	*ptr;
	t_node	*min;
	int	i;

	i = 0;
	while (i < ft_stack_size(stack))
	{
		min = stack;
		while (min->index >= 0)
			min = min->next;
		ptr = stack;
		while (ptr)
		{
			if (ptr->data < min->data && ptr->index < 0)
				min = ptr;
			ptr = ptr->next;
		}
		min->index = i++;
	}
}
