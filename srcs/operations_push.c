/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:51:52 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 17:18:18 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack *stack, int to_add)
{
	int	i;

	i = stack->size;
	while (i >= 0)
	{
		stack->cntr[i + 1] = stack->cntr[i];
		i--;
	}
	if (i == -1)
		i = 0;
	stack->cntr[i] = to_add;
	stack->size++;
}

static void	pop(t_stack *stack)
{
	int	i;

	i = 1;
	while (i <= stack->size)
	{
		stack->cntr[i - 1] = stack->cntr[i];
		i++;
	}
	stack->size--;
}

void	do_pa(t_stack *a, t_stack *b)
{
	if (b->size > -1)
	{
		push(a, b->cntr[0]);
		pop(b);
		ft_putendl_fd("pa", 1);
	}
}

void	do_pb(t_stack *a, t_stack *b)
{
	if (a->size > -1)
	{
		push(b, a->cntr[0]);
		pop(a);
		ft_putendl_fd("pb", 1);
	}
}
