/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:53:10 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 17:04:44 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

long	ft_atol(const char *nbr)
{
	int		i;
	int		is_neg;
	long	res;

	i = 0;
	is_neg = 0;
	res = 0;
	while (is_space(nbr[i]))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		i++;
		if (nbr[i - 1] == '-')
			is_neg = 1;
	}
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			break ;
		res = res * 10 + (nbr[i] - '0');
		i++;
	}
	if (is_neg)
		res = -1 * res;
	return (res);
}

int	is_int_cont(const char *nbr, int i, int j, int is_number)
{
	if (i - j > 10)
		return (0);
	if (ft_atol(nbr) > INT_MAX || ft_atol(nbr) < INT_MIN)
		return (0);
	while (nbr[i])
	{
		if (!is_space(nbr[i]))
			return (0);
		i++;
	}
	if (!is_number)
		return (0);
	return (1);
}

int	is_int(const char *nbr)
{
	int	i;
	int	j;
	int	is_number;

	i = 0;
	is_number = 0;
	while (is_space(nbr[i]))
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	j = i;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
		{
			if (is_space(nbr[i]))
				break ;
			return (0);
		}
		else
			is_number = 1;
		i++;
	}
	return (is_int_cont(nbr, i, j, is_number));
}

int	is_duplicate(t_node *stack)
{
	t_node	*tmp;
	t_node	*cmp;

	tmp = stack;
	while (tmp)
	{
		cmp = stack->next;
		while (cmp != tmp && cmp)
		{
			if (cmp->data == tmp->data)
				return (1);
			cmp = cmp->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
