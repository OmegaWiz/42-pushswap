/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:35:28 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 14:00:52 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *sa, t_stack *sb, long bucket)
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
			ft_rotate(sa);
			ft_putstr_fd("ra\n", 1);
			ft_print_stack(sa);
			ft_print_stack(sb);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	sa;
	t_stack	sb;
	size_t	n;
	char	**arg;

	if (argc == 1)
		return (0);
	arg = arg_format(argv);
	ft_init_stack(&sa, argc, argv);
	ft_init_stack(&sb, 0, NULL);
	n = 1;
	if (sa.size == 3)
		ft_push_swap_3(&sa);
	else if (sa.size == 5)
		ft_push_swap_5(&sa, &sb, ft_stack5_mid(&sa));
	if (sa.size == 3 || sa.size == 5)
		return (0);
	while (is_sorted(&sa) == 0)
	{
		ft_push_swap(&sa, &sb, n);
		ft_push_back(&sa, &sb);
		n = n * 2;
	}
	return (0);
}
