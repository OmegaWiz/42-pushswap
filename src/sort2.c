/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:07:49 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/08 09:25:32 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_2(t_node **sa)
{
	long	a;
	long	b;

	a = (*sa)->data;
	b = (*sa)->next->data;
	if (is_sorted(*sa))
		return ;
	if (a > b)
	{
		ft_swap(sa);
		ft_putstr_fd("sa\n", 1);
	}
	ft_print_stack2(*sa, NULL);
}

void	ft_push_swap_2_rev(t_node **sb)
{
	long	a;
	long	b;

	a = (*sb)->data;
	b = (*sb)->next->data;
	if (is_sorted_rev(*sb))
		return ;
	if (a < b)
	{
		ft_swap(sb);
		ft_putstr_fd("sb\n", 1);
	}
	ft_print_stack2(NULL, *sb);
}
