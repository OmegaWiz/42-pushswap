/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:03:40 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/30 17:48:19 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_int(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '-')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top->next;
	if (DEBUG == 0)
		return ;
	while (tmp != stack->bottom)
	{
		ft_putnbr_fd(tmp->data, 1);
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
