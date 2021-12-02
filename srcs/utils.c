/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:36:38 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 19:05:49 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->cntr[i] > stack->cntr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_limit(t_stack *stack, int max, int range)
{
	int	i;
	int	distance;
	int	closest;

	while (range > 1)
	{
		i = 0;
		distance = INT_MAX;
		closest = -1;
		while (i <= stack->size)
		{
			if (ft_abs(stack->cntr[i] - max) <= distance && \
				stack->cntr[i] < max)
			{
				distance = ft_abs(stack->cntr[i] - max);
				closest = i;
			}
			i++;
		}
		max = stack->cntr[closest];
		range--;
	}
	if (closest == -1)
		return (find_min(stack));
	return (closest);
}
