/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:36:34 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 18:41:37 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	smart_rotate_a(t_stack *a, int index)
{
	int	i;

	i = index - 1;
	while (i >= 0 && i < a->size)
	{
		if (index > a->size / 2)
		{
			do_rra(a);
			i++;
		}
		else
		{
			do_ra(a);
			i--;
		}
	}
}

void	smart_rotate_b(t_stack *b, int index)
{
	int	i;

	i = index - 1;
	while (i >= 0 && i < b->size)
	{
		if (index > b->size / 2)
		{
			do_rrb(b);
			i++;
		}
		else
		{
			do_rb(b);
			i--;
		}
	}
}
