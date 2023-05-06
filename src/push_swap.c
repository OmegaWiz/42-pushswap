/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:35:28 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 17:01:39 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_node *sa, t_node *sb, long bucket)
{
	int	i;
	int	n;

	i = -1;
	n = ft_stack_size(sa);
	while (++i < n)
	{
		if (!(sa->index & bucket))
		{
			ft_push(sa, sb);
			ft_putstr_fd("pb\n", 1);
		}
		else
		{
			ft_rotate(sa);
			ft_putstr_fd("ra\n", 1);
		}
		ft_print_stack2(sa, sb);
	}
	while (ft_stack_size(sb) > 0)
	{
		ft_push(sb, sa);
		ft_putstr_fd("pa\n", 1);
		ft_print_stack2(sa, sb);
	}
}

void	ft_push_swap_small(t_stack *stack)
{
	int	n;

	n = ft_stack_size(stack->a_top);
	if (n == 2)
		ft_push_swap_2(stack->a_top);
	if (n == 3)
		ft_push_swap_3(stack->a_top);
	if (n == 4)
		ft_push_swap_4(stack->a_top);
	if (n == 5)
		ft_push_swap_5(stack->a_top);
	if (n == 6)
		ft_push_swap_6(stack->a_top, stack->b_top);
	if (n == 7)
		ft_push_swap_7(stack->a_top, stack->b_top);
	if (n == 8)
		ft_push_swap_8(stack->a_top, stack->b_top);
	if (n == 9)
		ft_push_swap_9(stack->a_top, stack->b_top);
	if (n == 10)
		ft_push_swap_10(stack->a_top, stack->b_top);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	size_t	n;
	char	**arg;

	if (argc == 1)
		return (0);
	arg = arg_format(argc, argv);
	ft_init_stack(&stack, arg);
	ft_print_stack(&stack);
	ft_stack_index(stack.a_top);
	n = 1;
	if (ft_stack_size(stack.a_top) <= 10)
		ft_push_swap_small(&stack);
	else
	{
		while (is_sorted(&sa) == 0)
		{
			ft_push_swap(stack.a_top, stack.b_top, n);
			n = n * 2;
		}
	}
	free_all(arg, &stack);
	return (0);
}
