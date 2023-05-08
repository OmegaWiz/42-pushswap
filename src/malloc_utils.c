/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:54:24 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/08 09:03:23 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*malloc_check(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit(255);
	}
	return (ptr);
}

void	*malloc_and_check(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit(255);
	}
	return (ptr);
}

char	*ft_strappend(char *s1, char *s2)
{
	char	*new;

	new = (char *) malloc_and_check((ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcat(new, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	s1 = new;
	return (new);
}

void	free_all(char **arg, t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = -1;
	if (arg != NULL)
	{
		while (arg[++i] != NULL)
			free(arg[i]);
		free(arg);
		arg = NULL;
	}
	if (stack == NULL)
		return ;
	while (stack->a_top != NULL)
	{
		tmp = stack->a_top;
		stack->a_top = stack->a_top->next;
		free(tmp);
	}
	while (stack->b_top != NULL)
	{
		tmp = stack->b_top;
		stack->b_top = stack->b_top->next;
		free(tmp);
	}
}

void	free_exit(char **arg, t_stack *stack, int exitno)
{
	free_all(arg, stack);
	if (exitno != 0)
		ft_putstr_fd("Error\n", 2);
	exit(255);
}
