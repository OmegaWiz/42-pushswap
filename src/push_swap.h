/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:36:09 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 13:51:48 by kkaiyawo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include<unistd.h>
# include<fcntl.h>
# include<stdlib.h>
# include<limits.h>
# include<errno.h>
# include"../lib/libft/libft.h"

# ifndef DEBUG
#  define DEBUG 1
# endif

struct s_node
{
	long			data;
	long			index;
	struct s_node	*next;
};
typedef struct s_node	t_node;

struct s_stack
{
	t_node	*a_top;
	t_node	*b_top;
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
char	**arg_format(int argc, char **argv);
int		arg_count(char **arg);

//	malloc_utils.c
void	*malloc_check(void *ptr);
void	*malloc_and_check(size_t size);
char	*ft_strappend(char *s1, char *s2);
void	free_all(char **arg, t_stack *stack);
void	free_exit(char **arg, t_stack *stack, int exitno);

//	stack_utils.c
void	ft_init_stack(t_stack *stack, char **arg);
void	ft_push(t_node *s_from, t_node *s_to);
void	ft_pop(t_stack *stack);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
//

//	stack_utils2.c
void	ft_reverse_rotate(t_stack *stack);
void	ft_print_stack(t_stack *stack);
void	ft_push_back(t_node *stack, long data);
int		ft_stack_size(t_stack *stack);
void	ft_stack_index(t_node *stack);
//

//	stack_utils3.c
int		is_sorted(t_stack *stack);
int		is_sorted_rev(t_stack *stack);

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
