/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:18:37 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 15:52:49 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_stack_max(t_stack *s)
{
	t_node	*tmp;
	long	mx;

	tmp = s->top->next;
	mx = INT_MIN;
	while (tmp != s->bottom)
	{
		if (tmp->data > mx)
			mx = tmp->data;
		tmp = tmp->next;
	}
	return (mx1);
}

void	ft_push_swap_4_cont(t_stack *sa, t_stack *sb)
{
	ft_push_swap_3(sa);
	ft_push(sa, sb->top->next->data);
	ft_pop(sb);
	ft_putstr_fd("pa\n", 1);
	ft_print_stack(sa, sb);
}

void	ft_push_swap_4(t_stack *sa, t_stack *sb)
{
	int		i;
	long	mx;

	if (is_sorted(sa))
		return ;
	i = -1;
	mx = ft_stack_max(sa);
	while (++i < 4)
	{
		if (sa->top->next->data >= mx)
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
	ft_push_swap_4_cont(sa, sb);
}

void	ft_push_swap_4_rev_cont(t_stack *sa, t_stack *sb)
{
	ft_push_swap_3_rev(sb);
	ft_push(sb, sa->top->next->data);
	ft_pop(sa);
	ft_putstr_fd("pb\n", 1);
	ft_print_stack(sa, sb);
}

void	ft_push_swap_4_rev(t_stack *sa, t_stack *sb)
{
	int		i;
	long	mx;

	if (is_sorted(sb))
		return ;
	i = -1;
	mx = ft_stack_max(sb);
	while (++i < 4)
	{
		if (sb->top->next->data >= mx)
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
	ft_push_swap_4_rev_cont(sa, sb);
}
