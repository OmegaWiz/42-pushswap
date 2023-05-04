/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:01:24 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 15:57:37 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_5_cont(t_stack *sa, t_stack *sb)
{
	ft_push_swap_3(sa);
	ft_push_swap_2_rev(sb)
	ft_push(sa, sb->top->next->data);
	ft_pop(sb);
	ft_putstr_fd("pa\n", 1);
	ft_print_stack(sa, sb);
	ft_push(sa, sb->top->next->data);
	ft_pop(sb);
	ft_putstr_fd("pa\n", 1);
	ft_print_stack(sa, sb);
}

void	ft_push_swap_5(t_stack *sa, t_stack *sb)
{
	int		i;
	long	mid;

	if (is_sorted(sa))
		return ;
	mid = find_mid(sa, 5);
	i = -1;
	while (++i < 5)
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

void	ft_push_swap_5_rev_cont(t_stack *sa, t_stack *sb)
{
	ft_push_swap_3_rev(sb);
	ft_push_swap_2(sa)
	ft_push(sb, sa->top->next->data);
	ft_pop(sa);
	ft_putstr_fd("pb\n", 1);
	ft_print_stack(sa, sb);
	ft_push(sb, sa->top->next->data);
	ft_pop(sa);
	ft_putstr_fd("pb\n", 1);
	ft_print_stack(sa, sb);
}

void	ft_push_swap_5_rev(t_stack *sa, t_stack *sb)
{
	int		i;
	long	mid;

	if (is_sorted(sb))
		return ;
	mid = find_mid(sb, 5);
	i = -1;
	while (++i < 5)
	{
		if (sb->top->next->data > mid)
		{
			ft_push(sa, sb->top->next->data);
			ft_pop(sb);
			ft_putstr_fd("pa\n", 1);
			ft_print_stack(sa, sb);
		}
		else
		{
			ft_rotate(sb);
			ft_putstr_fd("rb\n", 1);
			ft_print_stack(sa, sb);
		}
	}
	ft_push_swap_5_rev_cont(sa, sb);
}
