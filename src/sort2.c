/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:07:49 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 16:43:04 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_2(t_stack *sa)
{
	long	a;
	long	b;

	a = sa->top->next->data;
	b = sa->top->next->next->data;
	if (a > b)
	{
		ft_swap(sa);
		ft_putstr_fd("sa\n", 1);
	}
}

void	ft_push_swap_2_rev(t_stack *sb)
{
	long	a;
	long	b;

	a = sb->top->next->data;
	b = sb->top->next->next->data;
	if (a < b)
	{
		ft_swap(sb);
		ft_putstr_fd("sb\n", 1);
	}
}
