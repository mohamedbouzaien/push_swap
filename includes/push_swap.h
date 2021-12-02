/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:12:54 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 20:11:50 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>

typedef struct s_stack
{
	int		*cntr;
	int		size;
}				t_stack;

void	do_sa(t_stack *a);
void	do_sb(t_stack *b);
void	do_ss(t_stack *a, t_stack *b);
void	do_pa(t_stack *a, t_stack *b);
void	do_pb(t_stack *a, t_stack *b);
void	do_ra(t_stack *a);
void	do_rb(t_stack *b);
void	do_rr(t_stack *a, t_stack *b);
void	do_rra(t_stack *a);
void	do_rrb(t_stack *b);
void	do_rrr(t_stack *a, t_stack *b);
void	small_size_sort(t_stack *a, t_stack *b);
void	big_size_sort(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_closest(t_stack *stack, int n);
int		find_range(t_stack *stack, int max, int min);
int		find_predecessor(t_stack *stack, int n);
void	smart_rotate_a(t_stack *a, int index);
void	smart_rotate_b(t_stack *b, int index);
int		get_limit(t_stack *stack, int max, int range);
#endif
