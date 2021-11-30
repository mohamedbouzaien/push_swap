/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:32:12 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/11/26 10:55:13 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	rotate(int *stack, int size)
{
	int		i;
	int     tmp;

	if (size >= 1)
	{
		tmp = stack[0];
		i = 0;
		while (i < size)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[size] = tmp;
	}
}

void	do_ra(int *stack_a, int size)
{
	rotate(stack_a, size);
	ft_putendl_fd("ra", 1);
}

void	do_rb(int *stack_b, int size)
{
	rotate(stack_b, size);
	ft_putendl_fd("rb", 1);
}

void	do_rr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rotate(stack_a, size_a);
	rotate(stack_b, size_b);
	ft_putendl_fd("rr", 1);
}