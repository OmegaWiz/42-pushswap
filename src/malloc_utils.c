/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:54:24 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 10:39:07 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*malloc_check(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit(ENOMEM);
	}
	return (ptr);
}

void	*malloc_and_check(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit(ENOMEM);
	}
	return (ptr);
}

void	free_all(char **arg, t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = -1;
	while (arg[++i])
	{
		free(arg[i]);
	}
	free(arg);
	while (stack->a_top != NULL)
	{
		tmp = stack->a_top;
		stack->a_top = stack->a_top->next;
		free(tmp);
	}
	while (stack->b_top != NULL)
	{
		tmp = stack->b_top;
		stack->b_top = stack->b_top->next;
		free(tmp);
	}
}

void	free_exit(char **arg, t_stack *stack)
{
	free_all(arg, stack);
	exit(ENOMEM);
}
