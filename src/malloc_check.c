/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:47:01 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/03 17:50:01 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*malloc_check(void *ptr)
{
	if (!ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
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
		exit(1);
	}
	return (ptr);
}
