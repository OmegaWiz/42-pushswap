/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:01:18 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 14:02:31 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_3_cont(t_stack *sa, long a, long b, long c)
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
}

void	ft_push_swap_3(t_stack *sa)
{
	long	a;
	long	b;
	long	c;

	a = sa->top->next->data;
	b = sa->top->next->next->data;
	c = sa->top->next->next->next->data;
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
