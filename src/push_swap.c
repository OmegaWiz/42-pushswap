/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:35:28 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 15:12:29 by kkaiyawo         ###   ########.fr       */
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
			ft_print_stack(sa, sb);
		}
		else
		{
			ft_rotate(sa);
			ft_putstr_fd("ra\n", 1);
			ft_print_stack(sa, sb);
		}
	}
}

void	ft_push_swap_small(t_stack *stack)
{
	if (sa->size == 2)
		ft_push_swap_2(stack->a_top);
	if (sa->size == 3)
		ft_push_swap_3(stack->a_top);
	if (sa->size == 4)
		ft_push_swap_4(stack->a_top);
	if (sa->size == 5)
		ft_push_swap_5(stack->a_top);
	if (sa->size == 6)
		ft_push_swap_6(stack->a_top, stack->b_top);
	if (sa->size == 7)
		ft_push_swap_7(stack->a_top, stack->b_top);
	if (sa->size == 8)
		ft_push_swap_8(stack->a_top, stack->b_top);
	if (sa->size == 9)
		ft_push_swap_9(stack->a_top, stack->b_top);
	if (sa->size == 10)
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
			ft_push_swap(&sa, &sb, n);
			ft_push_back(&sa, &sb);
			n = n * 2;
		}
	}
	free_all(arg, sa, sb);
	return (0);
}
