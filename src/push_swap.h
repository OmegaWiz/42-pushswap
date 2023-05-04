/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:36:09 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/04 16:26:20 by kkaiyawo         ###   ########.fr       */
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
typedef struct s_node	t_node;

struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
};
typedef struct s_stack	t_stack;

//	push_swap.c
void	ft_push_swap(t_stack *sa, t_stack *sb, long bucket);
void	ft_push_swap_small(t_stack *sa, t_stack *sb);

//	arg_check.c
int		is_int(const char *nbr);
int		is_duplicate(t_stack *stack);
long	ft_atol(const char *nbr);
//

//arg_format.c
char	**arg_format(char **argv);

//	malloc_utils.c
void	*malloc_check(void *ptr);
void	*malloc_and_check(size_t size);

//	stack_utils.c
void	ft_init_stack(t_stack *stack, int argc, char **argv);
void	ft_push(t_stack *stack, long data);
void	ft_pop(t_stack *stack);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
//

//	stack_utils2.c
void	ft_reverse_rotate(t_stack *stack);
void	ft_print_stack(t_stack *sa, t_stack *sb);
void	ft_push_back(t_stack *sa, t_stack *sb);
int		is_sorted(t_stack *stack);
//

//	find_mid.c
long	find_mid(t_stack *s, int n);

//	sort2.c
void	ft_push_swap_2(t_stack *sa);
void	ft_push_swap_2_rev(t_stack *sa);

//	sort3.c
void	ft_push_swap_3(t_stack *sa);
void	ft_push_swap_3_rev(t_stack *sb);

//	sort4.c
void	ft_push_swap_4(t_stack *sa, t_stack *sb);
void	ft_push_swap_4_rev(t_stack *sa, t_stack *sb);

//	sort5.c
void	ft_push_swap_5(t_stack *sa, t_stack *sb);
void	ft_push_swap_5_rev(t_stack *sa, t_stack *sb);

//	sort6.c
void	ft_push_swap_6(t_stack *sa, t_stack *sb);

//	sort7.c
void	ft_push_swap_7(t_stack *sa, t_stack *sb);

//	sort8.c
void	ft_push_swap_8(t_stack *sa, t_stack *sb);

//	sort9.c
void	ft_push_swap_9(t_stack *sa, t_stack *sb);

//	sort10.c
void	ft_push_swap_10(t_stack *sa, t_stack *sb);

#endif
