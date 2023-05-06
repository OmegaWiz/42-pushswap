/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:05:31 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 16:43:03 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_9_cont(t_node *sa, t_node *sb)
{
	int	i;

	ft_push_swap_5(sa, sb);
	ft_push_swap_4_rev(sa, sb);
	i = 0;
	while (++i <= 4)
	{
		ft_push(sb, sa);
		ft_putstr_fd("pa\n", 1);
		ft_print_stack2(sa, sb);
	}
}

void	ft_push_swap_9(t_node *sa, t_node *sb)
{
	int		i;
	long	mid;

	if (is_sorted(sa))
		return ;
	mid = ft_stack_size(sa) / 2;
	i = -1;
	while (++i < 9)
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
	ft_push_swap_9_cont(sa, sb);
}
