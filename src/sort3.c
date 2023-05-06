/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:01:18 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 18:22:35 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_3_cont(t_node *sa, long a, long b, long c)
{
	if (a < b && b > c && a > c)
	{
		ft_reverse_rotate(sa);
		ft_putstr_fd("rra\n", 1);
	}
	if (a > b && b < c && a > c)
	{
		ft_rotate(sa);
		ft_putstr_fd("ra\n", 1);
	}
	if (a > b && b > c && a > c)
	{
		ft_swap(sa);
		ft_putstr_fd("sa\n", 1);
		ft_reverse_rotate(sa);
		ft_putstr_fd("rra\n", 1);
	}
	ft_print_stack2(sa, NULL);
}

void	ft_push_swap_3(t_node *sa)
{
	long	a;
	long	b;
	long	c;

	a = sa->data;
	b = sa->next->data;
	c = sa->next->next->data;
	if (is_sorted(sa))
		return ;
	if (a < b && b > c && a < c)
	{
		ft_reverse_rotate(sa);
		ft_putstr_fd("rra\n", 1);
		ft_swap(sa);
		ft_putstr_fd("sa\n", 1);
	}
	if (a > b && b < c && a < c)
	{
		ft_swap(sa);
		ft_putstr_fd("sa\n", 1);
	}
	ft_push_swap_3_cont(sa, a, b, c);
}

void	ft_push_swap_3_rev_cont(t_node *sb, long a, long b, long c)
{
	if (a > b && b < c && a < c)
	{
		ft_reverse_rotate(sb);
		ft_putstr_fd("rrb\n", 1);
	}
	if (a < b && b > c && a < c)
	{
		ft_rotate(sb);
		ft_putstr_fd("rb\n", 1);
	}
	if (a < b && b < c && a < c)
	{
		ft_swap(sb);
		ft_putstr_fd("sb\n", 1);
		ft_reverse_rotate(sb);
		ft_putstr_fd("rrb\n", 1);
	}
	ft_print_stack2(NULL, sb);
}

void	ft_push_swap_3_rev(t_node *sb)
{
	long	a;
	long	b;
	long	c;

	a = sb->data;
	b = sb->next->data;
	c = sb->next->next->data;
	if (is_sorted_rev(sb))
		return ;
	if (a > b && b < c && a > c)
	{
		ft_reverse_rotate(sb);
		ft_putstr_fd("rrb\n", 1);
		ft_swap(sb);
		ft_putstr_fd("sb\n", 1);
	}
	if (a < b && b > c && a > c)
	{
		ft_swap(sb);
		ft_putstr_fd("sb\n", 1);
	}
	ft_push_swap_3_rev_cont(sb, a, b, c);
}
