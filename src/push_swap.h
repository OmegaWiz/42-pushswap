/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:36:09 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/04/30 23:14:28 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<limits.h>
# include"../lib/libft/libft.h"

# ifndef DEBUG
#  define DEBUG 0
# endif

struct s_node
{
	long			data;
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

int		is_int(const char *nbr);
int		is_duplicate(t_stack *stack);
long	ft_atol(const char *nbr);
void	ft_init_stack(t_stack *stack, int argc, char **argv);
void	ft_push(t_stack *stack, long data);
void	ft_pop(t_stack *stack);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);
long	ft_stack5_mid(t_stack *s);
void	ft_push_swap_3(t_stack *stack);
void	ft_push_swap_5(t_stack *sa, t_stack *sb, long mid);
void	ft_push_swap(t_stack *sa, t_stack *sb, long bucket);
void	ft_print_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

#endif
