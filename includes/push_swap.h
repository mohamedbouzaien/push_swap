/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:12:54 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/11/22 12:38:20 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H_

# define PUSH_SWAP_H_
# include "libft.h"

void	do_sa(int *stack_a, int size);
void	do_sb(int *stack_b, int size);
void	do_ss(int *stack_a, int *stack_b, int size_a, int size_b);
void	do_pa(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	do_pb(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	do_ra(int *stack_a, int size);
void	do_rb(int *stack_b, int size);
void	do_rr(int *stack_a, int *stack_b, int size_a, int size_b);
void	do_rra(int *stack_a, int size);
void	do_rrb(int *stack_b, int size);
void	do_rrr(int *stack_a, int *stack_b, int size_a, int size_b);
void	small_size_sort(int *stack_a, int *stack_b, int *size_a, int *size_b);

#endif