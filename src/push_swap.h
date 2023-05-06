/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaiyawo <kkaiyawo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:36:09 by kkaiyawo          #+#    #+#             */
/*   Updated: 2023/05/06 20:01:07 by kkaiyawo         ###   ########.fr       */
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
#  define DEBUG 0
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
void	ft_push_swap(t_node **sa, t_node **sb, long bucket);
void	ft_push_swap_small(t_stack *stack);

//	arg_check.c
int		is_int(const char *nbr);
int		is_duplicate(t_node *stack);
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
void	ft_push(t_node **s_from, t_node **s_to);
void	ft_swap(t_node **stack);
void	ft_rotate(t_node **stack);
void	ft_reverse_rotate(t_node **stack);
//

//	stack_utils2.c
void	ft_print_stack(t_stack *stack);
void	ft_print_stack2(t_node *sa, t_node *sb);
t_node	*ft_push_front(t_node *stack, long data);
int		ft_stack_size(t_node *stack);
void	ft_stack_index(t_node *stack);
//

//	stack_utils3.c
int		is_sorted(t_node *stack);
int		is_sorted_rev(t_node *stack);
long	ft_mid_index(t_node *sa);
long	ft_max_index(t_node *sa);
//

//	sort2.c
void	ft_push_swap_2(t_node **sa);
void	ft_push_swap_2_rev(t_node **sb);

//	sort3.c
void	ft_push_swap_3(t_node **sa);
void	ft_push_swap_3_rev(t_node **sb);

//	sort4.c
void	ft_push_swap_4(t_node **sa, t_node **sb);
void	ft_push_swap_4_rev(t_node **sa, t_node **sb);

//	sort5.c
void	ft_push_swap_5(t_node **sa, t_node **sb);
void	ft_push_swap_5_rev(t_node **sa, t_node **sb);

//	sort6.c
void	ft_push_swap_6(t_node **sa, t_node **sb);

//	sort7.c
void	ft_push_swap_7(t_node **sa, t_node **sb);

//	sort8.c
void	ft_push_swap_8(t_node **sa, t_node **sb);

//	sort9.c
void	ft_push_swap_9(t_node **sa, t_node **sb);

//	sort10.c
void	ft_push_swap_10(t_node **sa, t_node **sb);

#endif
