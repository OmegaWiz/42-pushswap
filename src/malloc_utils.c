/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:54:24 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 18:33:02 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*malloc_check(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
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
		exit(1);
	}
	return (ptr);
}

void	free_all(char **arg, t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		free(arg[i]);
	}
	free(arg);
	while (a->top->next != a->bottom)
		ft_pop(a);
	if (a->top)
		free(a->top);
	if (a->bottom)
		free(a->bottom);
	while (b->top->next != b->bottom)
		ft_pop(b);
	if (b->top)
		free(b->top);
	if (b->bottom)
		free(b->bottom);
}
