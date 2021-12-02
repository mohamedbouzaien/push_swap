/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 00:14:52 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 17:14:08 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	int		i;
	int		tmp;

	if (stack->size >= 1)
	{
		tmp = stack->cntr[stack->size];
		i = stack->size;
		while (i > 0)
		{
			stack->cntr[i] = stack->cntr[i - 1];
			i--;
		}
		stack->cntr[0] = tmp;
	}
}

void	do_rra(t_stack *a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	do_rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	do_rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}
