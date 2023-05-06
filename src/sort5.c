/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:01:24 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 20:00:09 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_5_cont(t_node **sa, t_node **sb)
{
	ft_push_swap_3(sa);
	ft_push_swap_2_rev(sb);
	ft_push(sb, sa);
	ft_putstr_fd("pa\n", 1);
	ft_print_stack2(*sa, *sb);
	ft_push(sb, sa);
	ft_putstr_fd("pa\n", 1);
	ft_print_stack2(*sa, *sb);
}

void	ft_push_swap_5(t_node **sa, t_node **sb)
{
	int		i;
	long	mid;

	if (is_sorted(*sa))
		return ;
	mid = ft_mid_index(*sa);
	i = -1;
	while (++i < 5)
	{
		if ((*sa)->index < mid)
		{
			ft_push(sa, sb);
			ft_putstr_fd("pb\n", 1);
			ft_print_stack2(*sa, *sb);
		}
		else
		{
			ft_rotate(sa);
			ft_putstr_fd("ra\n", 1);
			ft_print_stack2(*sa, *sb);
		}
	}
	ft_push_swap_5_cont(sa, sb);
}

void	ft_push_swap_5_rev_cont(t_node **sa, t_node **sb)
{
	ft_push_swap_3_rev(sb);
	ft_push_swap_2(sa);
	ft_push(sa, sb);
	ft_putstr_fd("pb\n", 1);
	ft_print_stack2(*sa, *sb);
	ft_push(sa, sb);
	ft_putstr_fd("pb\n", 1);
	ft_print_stack2(*sa, *sb);
}

void	ft_push_swap_5_rev(t_node **sa, t_node **sb)
{
	int		i;
	long	mid;

	if (is_sorted_rev(*sb))
		return ;
	mid = ft_mid_index(*sb);
	i = -1;
	while (++i < 5)
	{
		if ((*sb)->index > mid)
		{
			ft_push(sb, sa);
			ft_putstr_fd("pa\n", 1);
			ft_print_stack2(*sa, *sb);
		}
		else
		{
			ft_rotate(sb);
			ft_putstr_fd("rb\n", 1);
			ft_print_stack2(*sa, *sb);
		}
	}
	ft_push_swap_5_rev_cont(sa, sb);
}
