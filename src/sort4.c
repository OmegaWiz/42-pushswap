/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:18:37 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 14:18:38 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_stack5_mid(t_stack *s)
{
	t_node	*tmp;
	long	mx1;
	long	mx2;
	long	mx3;

	tmp = s->top->next;
	mx1 = INT_MIN;
	mx2 = INT_MIN;
	mx3 = INT_MIN;
	while (tmp != s->bottom)
	{
		if (tmp->data > mx1)
			mx1 = tmp->data;
		if (tmp->data > mx2)
			mx1 = mx2;
		if (tmp->data > mx2)
			mx2 = tmp->data;
		if (tmp->data > mx3)
			mx2 = mx3;
		if (tmp->data > mx3)
			mx3 = tmp->data;
		tmp = tmp->next;
	}
	return (mx1);
}

void	ft_push_swap_5_cont(t_stack *sa, t_stack *sb)
{
	ft_push_swap_3(sa);
	if (sb->top->next->data < sb->top->next->next->data)
	{
		ft_swap(sb);
		ft_putstr_fd("sb\n", 1);
		ft_print_stack(sa);
		ft_print_stack(sb);
	}
	ft_push(sa, sb->top->next->data);
	ft_pop(sb);
	ft_putstr_fd("pa\n", 1);
	ft_print_stack(sa);
	ft_print_stack(sb);
	ft_push(sa, sb->top->next->data);
	ft_pop(sb);
	ft_putstr_fd("pa\n", 1);
	ft_print_stack(sa);
	ft_print_stack(sb);
}

void	ft_push_swap_5(t_stack *sa, t_stack *sb, long mid)
{
	int	i;

	if (is_sorted(sa))
		return ;
	i = -1;
	while (++i < 5)
	{
		if (sa->top->next->data < mid)
		{
			ft_push(sb, sa->top->next->data);
			ft_pop(sa);
			ft_putstr_fd("pb\n", 1);
			ft_print_stack(sa);
			ft_print_stack(sb);
		}
		else
		{
			ft_rotate(sa);
			ft_putstr_fd("ra\n", 1);
			ft_print_stack(sa);
			ft_print_stack(sb);
		}
	}
	ft_push_swap_5_cont(sa, sb);
}
