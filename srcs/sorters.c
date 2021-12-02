/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:41:03 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 20:10:13 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	three_elements_sort(t_stack *s)
{
	int	*stack;

	stack = s->cntr;
	if (stack[0] > stack[1] && stack[1] > stack[2] && stack[2] < stack[0])
	{
		do_sa(s);
		do_rra(s);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[2] > stack[0])
		do_sa(s);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[2] > stack[0])
	{
		do_sa(s);
		do_ra(s);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[2] < stack[0])
		do_ra(s);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[2] < stack[0])
		do_rra(s);
}

void	small_size_sort(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		do_sa(a);
	else if (a->size == 2)
		three_elements_sort(a);
	else
	{
		while (a->size != 2)
			do_pb(a, b);
		three_elements_sort(a);
		while (b->size != -1)
		{
			smart_rotate_a(a, find_closest(a, b->cntr[0]));
			do_pa(a, b);
		}
		smart_rotate_a(a, find_min(a));
	}
}

static void	push_range(t_stack *a, t_stack *b, int max, int min)
{
	int		chunk_size;

	chunk_size = find_range(a, max, min);
	while (chunk_size > 0)
	{
		while (a->cntr[0] < min || a->cntr[0] > max)
			do_rra(a);
		do_pb(a, b);
		chunk_size--;
	}
}

static void	sort_chunk(t_stack *a, t_stack *b, int max, int min)
{
	push_range(a, b, max, min);
	max = find_max(b);
	smart_rotate_a(a, find_closest(a, b->cntr[max]));
	while (b->size > -1)
	{
		max = find_max(b);
		min = find_min(b);
		if ((min < max && min < b->size / 4) || \
			(min > max && min >= b->size / 4))
		{
			smart_rotate_b(b, min);
			do_pa(a, b);
			do_ra(a);
		}
		else
		{
			smart_rotate_b(b, max);
			do_pa(a, b);
		}
	}
}

void	big_size_sort(t_stack *a, t_stack *b)
{
	int		min;
	int		max;
	int		coef;
	int		chunks;

	if (a->size > 200)
		coef = 50;
	else
		coef = 20;
	chunks = a->size / coef + 1;
	max = a->cntr[find_max(a)];
	while (chunks > 0)
	{
		if (chunks == 1)
			min = a->cntr[find_min(a)];
		else
			min = a->cntr[get_limit(a, max, coef)];
		sort_chunk(a, b, max, min);
		max = a->cntr[find_predecessor(a, min)];
		chunks--;
	}
	min = find_min(a);
	smart_rotate_a(a, min);
}
