/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:41:03 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/11/22 13:12:59 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	three_elements_sort(int *stack, int size)
{
	if (stack[2] < stack[1] && stack[2] < stack[1] && stack[0] > stack[2])
	{
		do_sa(stack, size);
		do_rra(stack, size);
	}
	else if (stack[1] > stack[0] && stack[2] < stack[1] && stack[0] < stack[2])
		do_sa(stack, size);
	else if (stack[1] < stack[0] && stack[2] > stack[1] && stack[0] < stack[2])
	{
		do_sa(stack, size);
		do_ra(stack, size);
	}
	else if (stack[1] > stack[0] && stack[2] < stack[1] && stack[0] > stack[2])
		do_ra(stack, size);
	else if (stack[1] < stack[0] && stack[2] > stack[1] && stack[0] > stack[2])
		do_rra(stack, size);
}

void	small_size_sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (*size_a == 1)
		do_sa(stack_a, *size_a);
	else if (*size_a == 2)
		three_elements_sort(stack_a, *size_a);
}