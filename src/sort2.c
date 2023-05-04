/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:07:49 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 14:30:09 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_2(t_stack *stack)
{
	long	a;
	long	b;

	a = sa->top->next->data;
	b = sa->top->next->next->data;
	if (a > b)
	{
		ft_swap(sa);
		ft_putstr_fd("sa\n", 1);
		ft_print_stack(sa, sb);
	}
}
