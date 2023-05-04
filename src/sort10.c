/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:05:42 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 16:13:30 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_10_cont(t_stack *sa, t_stack *sb)
{
	int	i;
	ft_push_swap_5(sa, sb);
	ft_push_swap_5_rev(sa, sb);
	i = 0;
	while (++i <= 5)
	{
		ft_push(sa, sb->top->next->data);
		ft_pop(sb);
		ft_putstr_fd("pa\n", 1);
		ft_print_stack(sa, sb);
	}
}

void	ft_push_swap_10(t_stack *sa, t_stack *sb)
{
	int		i;
	long	mid;

	if (is_sorted(sa))
		return ;
	mid = find_mid(sa, 10);
	i = -1;
	while (++i < 10)
	{
		if (sa->top->next->data < mid)
		{
			ft_push(sb, sa->top->next->data);
			ft_pop(sa);
			ft_putstr_fd("pb\n", 1);
			ft_print_stack(sa, sb);
		}
		else
		{
			ft_rotate(sa);
			ft_putstr_fd("ra\n", 1);
			ft_print_stack(sa, sb);
		}
	}
	ft_push_swap_5_cont(sa, sb);
}
