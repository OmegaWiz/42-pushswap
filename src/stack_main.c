/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:03:38 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/30 16:16:43 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = argc;
	stack->top = (t_node *) malloc(sizeof(t_node));
	stack->bottom = (t_node *) malloc(sizeof(t_node));
	stack->top->next = stack->bottom;
	stack->bottom->prev = stack->top;
	stack->top->prev = NULL;
	stack->bottom->next = NULL;
	stack->size = 0;
	while (--i > 0)
	{
		ft_push(stack, ft_atoi(argv[i]));
	}
	ft_print_stack(stack);
}

void	ft_push(t_stack *stack, int data)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof(t_node));
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

void	ft_reverse(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next->prev = stack->top;
	tmp->next = stack->bottom;
	tmp->prev = stack->bottom->prev;
	stack->bottom->prev->next = tmp;
	stack->bottom->prev = tmp;
}
