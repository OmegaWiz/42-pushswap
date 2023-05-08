/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:35:51 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/08 11:23:59 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**arg_format(int argc, char **argv)
{
	char	*line;
	char	**arg;
	int		i;

	line = malloc_check(ft_strdup(""));
	i = 0;
	while (++i < argc)
	{
		line = ft_strappend(line, argv[i]);
		line = ft_strappend(line, " ");
	}
	arg = (char **) malloc_check(ft_split(line, ' '));
	free(line);
	return (arg);
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
