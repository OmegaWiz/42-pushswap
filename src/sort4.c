/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:18:37 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 19:59:37 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_min_index(t_node *sa)
{
	t_node	*tmp;
	long	mn;

	tmp = sa;
	mn = tmp->index;
	while (tmp)
	{
		if (tmp->index < mn)
			mn = tmp->index;
		tmp = tmp->next;
	}
	return (mn);
}

void	ft_push_swap_4_cont(t_node **sa, t_node **sb)
{
	ft_push_swap_3(sa);
	ft_push(sb, sa);
	ft_putstr_fd("pa\n", 1);
	ft_print_stack2(*sa, *sb);
}

void	ft_push_swap_4(t_node **sa, t_node **sb)
{
	int		i;
	long	mx;
	long	mn;

	if (is_sorted(*sa))
		return ;
	i = -1;
	mx = ft_stack_size(*sa) - 1;
	mn = ft_min_index(*sa);
	while (++i < 4)
	{
		if ((*sa)->index == mn)
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
	ft_push_swap_4_cont(sa, sb);
}

void	ft_push_swap_4_rev_cont(t_node **sa, t_node **sb)
{
	ft_push_swap_3_rev(sb);
	ft_push(sa, sb);
	ft_putstr_fd("pb\n", 1);
	ft_print_stack2(*sa, *sb);
}

void	ft_push_swap_4_rev(t_node **sa, t_node **sb)
{
	int		i;
	long	mx;
	long	mn;

	if (is_sorted_rev(*sb))
		return ;
	i = -1;
	mx = ft_stack_size(*sb) - 1;
	mn = ft_max_index(*sb);
	while (++i < 4)
	{
		if ((*sb)->index == mn)
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
	ft_push_swap_4_rev_cont(sa, sb);
}
