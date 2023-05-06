/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:35:51 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 13:11:52 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**arg_format(int argc, char **argv)
{
	char	*line;

	line = "";
	while (--argc)
	{
		line = ft_strappend(line, argv[argc]);
		line = ft_strappend(line, " ");
	}
	return ((char **) malloc_check(ft_split(line, ' ')));
}

int	arg_count(char **arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		i++;
	}
	return (i);
}
