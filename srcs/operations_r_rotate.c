/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 00:14:52 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/11/22 11:35:24 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	reverse_rotate(int *stack, int size)
{
	int		i;
	int     tmp;

	if (size > 1)
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

void	do_rra(int *stack_a, int size)
{
	reverse_rotate(stack_a, size);
	ft_putendl_fd("rra", 1);
}

void	do_rrb(int *stack_b, int size)
{
	reverse_rotate(stack_b, size);
	ft_putendl_fd("rrb", 1);
}

void	do_rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	reverse_rotate(stack_a, size_a);
	reverse_rotate(stack_b, size_b);
	ft_putendl_fd("rrr", 1);
}