/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:36:09 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/30 17:48:42 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include"../lib/libft/libft.h"

# define DEBUG 0

struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
};
typedef struct s_node t_node;

struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
};
typedef struct s_stack t_stack;

int		is_int(char *nbr);
void	ft_init_stack(t_stack *stack, int argc, char **argv);
void	ft_push(t_stack *stack, int data);
void	ft_pop(t_stack *stack);
void	ft_reverse(t_stack *stack);
void	ft_push_swap(t_stack *sa, t_stack *sb, int bucket);
void	ft_print_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

#endif
