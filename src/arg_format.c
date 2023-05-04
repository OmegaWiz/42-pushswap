/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:35:51 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 18:22:27 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**arg_format(char **argv)
{
	char	**arg;
	char	*tmp;
	char	*line;
	size_t	i;

	i = 1;
	line = (char *) malloc_check(ft_strdup(argv[i]));
	tmp = line;
	while (argv[++i])
	{
		tmp = line;
		line = (char *) malloc_check(ft_strjoin(tmp, " "));
		free(tmp);
		tmp = line;
		line = (char *) malloc_check(ft_strjoin(tmp, argv[i]));
		free(tmp);
	}
	arg = (char **) malloc_check(ft_split(line, ' '));
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
