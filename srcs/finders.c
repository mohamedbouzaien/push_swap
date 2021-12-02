/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:22:47 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 19:08:16 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack)
{
	int		i;
	int		min;
	int		pos;

	min = INT_MAX;
	pos = -1;
	i = 0;
	while (i <= stack->size)
	{
		if (min > stack->cntr[i] || (min == stack->cntr[i] && \
			(stack->size - i) < pos) || \
			(stack->cntr[i] == INT_MAX && min == INT_MAX))
		{
			min = stack->cntr[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	find_max(t_stack *stack)
{
	int		i;
	int		max;
	int		pos;

	max = INT_MIN;
	pos = -1;
	i = 0;
	while (i <= stack->size)
	{
		if (max < stack->cntr[i] || (max == stack->cntr[i] && \
			(stack->size - i) < pos) || \
			(stack->cntr[i] == INT_MIN && max == INT_MIN))
		{
			max = stack->cntr[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	find_closest(t_stack *stack, int n)
{
	int	i;
	int	distance;
	int	closest;

	i = 0;
	distance = 2147483647;
	closest = -1;
	while (i <= stack->size)
	{
		if (ft_abs(stack->cntr[i] - n) <= distance && stack->cntr[i] >= n)
		{
			distance = ft_abs(stack->cntr[i] - n);
			closest = i;
		}
		i++;
	}
	if (closest == -1)
		return (find_min(stack));
	return (closest);
}

int	find_range(t_stack *stack, int max, int min)
{
	int	i;
	int	range;

	i = 0;
	range = 0;
	while (i <= stack->size)
	{
		if (stack->cntr[i] >= min && stack->cntr[i] <= max)
		{
			range++;
		}
		i++;
	}
	return (range);
}

int	find_predecessor(t_stack *stack, int n)
{
	int	i;
	int	distance;
	int	closest;

	i = 0;
	distance = INT_MAX;
	closest = -1;
	while (i <= stack->size)
	{
		if (ft_abs(stack->cntr[i] - n) <= distance && stack->cntr[i] < n)
		{
			distance = ft_abs(stack->cntr[i] - n);
			closest = i;
		}
		i++;
	}
	if (closest == -1)
		return (find_min(stack));
	return (closest);
}
