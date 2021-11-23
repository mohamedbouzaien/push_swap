/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:51:52 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/11/22 00:25:24 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(int *stack, int *size, int to_add)
{
	int	i;

	i = *size;
	while (i >= 0)
	{
		stack[i + 1] = stack[i];
		i--;
	}
	if (i == -1)
		i = 0;
	stack[i] = to_add;
	(*size)++;
}

void	pop(int *stack, int *size)
{
	int	i;

	i = 1;
	while (i <= *size)
	{
		stack[i - 1] = stack[i];
		i++;
	}
	(*size)--;
}

void	do_pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (*size_b > -1)
	{
		push(stack_a, size_a, stack_b[0]);
		pop(stack_b, size_b);
		ft_putendl_fd("pa", 1);
	}
}

void	do_pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (*size_a > -1)
	{
		push(stack_b, size_b, stack_a[0]);
		pop(stack_a, size_a);
		ft_putendl_fd("pb", 1);
	}
}

