/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:05:42 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 17:13:40 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_10_cont(t_node *sa, t_node *sb)
{
	int	i;

	ft_push_swap_5(sa, sb);
	ft_push_swap_5_rev(sa, sb);
	i = 0;
	while (++i <= 5)
	{
		ft_push(sb, sa);
		ft_putstr_fd("pa\n", 1);
		ft_print_stack2(sa, sb);
	}
}

void	ft_push_swap_10(t_node *sa, t_node *sb)
{
	int		i;
	long	mid;

	if (is_sorted(sa))
		return ;
	mid = ft_stack_size(sa) / 2;
	i = -1;
	while (++i < 10)
	{
		if (sa->index < mid)
		{
			ft_push(sa, sb);
			ft_putstr_fd("pb\n", 1);
			ft_print_stack2(sa, sb);
		}
		else
		{
			ft_rotate(sa);
			ft_putstr_fd("ra\n", 1);
			ft_print_stack2(sa, sb);
		}
	}
	ft_push_swap_10_cont(sa, sb);
}
