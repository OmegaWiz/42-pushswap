/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:56:01 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 13:23:33 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *sa, t_stack *sb, int argc, char **argv)
{
	int	i;

	i = argc;
	stack->top = (t_node *) malloc_and_check(sizeof(t_node));
	stack->bottom = (t_node *) malloc_and_check(sizeof(t_node));
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
	stack->size = 0;
	while (--i >= 0 && argv[i])
	{
		if (is_int(argv[i]) == 0)
			ft_putstr_fd("Error\n", 2);
		if (is_int(argv[i]) == 0)
			exit(0);
		ft_push(stack, ft_atol(argv[i]) + INT_MAX + 1);
	}
	if (is_duplicate(stack) == 1)
		ft_putstr_fd("Error\n", 2);
	if (is_duplicate(stack) == 1)
		exit(0);
}

void	ft_init_stack(t_stack *stack, char **arg)
{
	ssize_t	i;

	i = -1;
	while (arg[++i])
	{
		if (is_int(arg[i]))
			ft_push_back(stack->a_top, ft_atol(arg[i]) + INT_MAX + 1);
		else
			free_exit(stack, arg, ENOMEM);
	}
	if (is_duplicate(stack->a_top) || ft_stack_size(stack->a_top) != i)
		free_exit(stack, arg, ENOMEM);
	free_all(arg, NULL);
}

void	ft_push(t_stack *stack, long data)
{
	t_node	*new;

	new = (t_node *) malloc_and_check(sizeof(t_node));
	new->data = data;
	new->next = stack->top->next;
	new->prev = stack->top;
	stack->top->next->prev = new;
	stack->top->next = new;
	stack->size++;
}

void	ft_pop(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next->prev = stack->top;
	free(tmp);
	stack->size--;
}

void	ft_swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next->prev = stack->top;
	tmp->next = stack->top->next->next;
	tmp->prev = stack->top->next;
	stack->top->next->next->prev = tmp;
	stack->top->next->next = tmp;
}

void	ft_rotate(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next->prev = stack->top;
	tmp->next = stack->bottom;
	tmp->prev = stack->bottom->prev;
	stack->bottom->prev->next = tmp;
	stack->bottom->prev = tmp;
}
