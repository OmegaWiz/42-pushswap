/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:35:28 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/30 16:33:26 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *sa, t_stack *sb, int bucket)
{
	int	i;
	int	n;

	i = -1;
	n = sa->size;
	while (++i < n)
	{
		if (!(sa->top->next->data & bucket))
		{
			ft_push(sb, sa->top->next->data);
			ft_pop(sa);
			ft_putstr_fd("pb\n", 1);
			ft_print_stack(sa);
			ft_print_stack(sb);
		}
		else
		{
			ft_reverse(sa);
			ft_putstr_fd("ra\n", 1);
			ft_print_stack(sa);
			ft_print_stack(sb);
		}
	}
}

void	ft_push_back(t_stack *sa, t_stack *sb)
{
	while (sb->size > 0)
	{
		ft_push(sa, sb->top->next->data);
		ft_pop(sb);
		ft_putstr_fd("pa\n", 1);
	}
	ft_print_stack(sa);
	ft_print_stack(sb);
}

int	arg_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == '-' && j == 0)
				continue ;
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			if (j > 10)
				return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	sa;
	t_stack	sb;
	size_t	n;

	if (argc == 1)
		return (0);
	if (arg_check(argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ft_init_stack(&sa, argc, argv);
	ft_init_stack(&sb, 0, NULL);
	n = 1;
	while (is_sorted(&sa) == 0)
	{
		ft_push_swap(&sa, &sb, n);
		ft_push_back(&sa, &sb);
		n = n * 2;
	}
	return (0);
}
