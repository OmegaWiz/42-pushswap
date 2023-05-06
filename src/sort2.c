/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:07:49 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 15:14:01 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_2(t_node *sa)
{
	if (!is_sorted(sa))
	{
		ft_swap(sa);
		ft_putstr_fd("sa\n", 1);
	}
}

void	ft_push_swap_2_rev(t_node *sb)
{
	if (!is_sorted_rev(sb))
	{
		ft_swap(sb);
		ft_putstr_fd("sb\n", 1);
	}
}
