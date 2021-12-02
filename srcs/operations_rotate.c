/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:32:12 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 17:14:16 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack *stack)
{
	int		i;
	int		tmp;

	if (stack->size >= 1)
	{
		tmp = stack->cntr[0];
		i = 0;
		while (i < stack->size)
		{
			stack->cntr[i] = stack->cntr[i + 1];
			i++;
		}
		stack->cntr[stack->size] = tmp;
	}
}

void	do_ra(t_stack *a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	do_rb(t_stack *b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	do_rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
