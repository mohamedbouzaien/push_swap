/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:41:03 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/01 17:09:28 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

void	show_stack(int *stack, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		printf("%d | ", stack[i]);
		i++;
	}
	printf("\n");
}

void	three_elements_sort(int *stack, int size)
{

	if (stack[0] > stack[1] && stack[1] > stack[2] && stack[2] < stack[0])
	{
		do_sa(stack, size);
		do_rra(stack, size);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[2] > stack[0])
		do_sa(stack, size);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[2] > stack[0])
	{
		do_sa(stack, size);
		do_ra(stack, size);
	}
	else if (stack[0] > stack[1] && stack[1] < stack[2] && stack[2] < stack[0])
		do_ra(stack, size);
	else if (stack[0] < stack[1] && stack[1] > stack[2] && stack[2] < stack[0])
		do_rra(stack, size);
}

int		find_min(int *stack, int size)
{
	int		i;
	int		min;
	int		pos;

	min = 2147483647;
	pos = -1;
	i = 0;
	while (i <= size)
	{
		if (min > stack[i] || (min == stack[i] && (size - i) < pos) || \
			(stack[i] == 2147483647 && min == 2147483647))
		{
			min = stack[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int		find_max(int *stack, int size)
{
	int		i;
	int		max;
	int		pos;

	max = -2147483648;
	pos = -1;
	i = 0;
	while (i <= size)
	{
		if (max < stack[i] || (max == stack[i] && (size - i) < pos) || \
			(stack[i] == -2147483648 && max == -2147483648))
		{
			max = stack[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int		abs(int n)
{
	return (n < 0 ? -n : n);
}

int		find_closest(int *stack, int size, int n)
{
	int	i;
	int	distance;
	int	closest;

	i = 0;
	distance = 2147483647;
	closest = -1;
	while (i <= size)
	{
		if (abs(stack[i] - n) <= distance && stack[i] >= n) 
		{
			distance = abs(stack[i] - n);
			closest = i;
		}
		i++;
	}
	if (closest == -1)
		return (find_min(stack, size));
	return (closest);
}

void	smart_rotate_a(int *stack, int size, int index)
{
	int	i;

	i = index - 1;
	while (i >= 0 && i < size)
	{
		if (index > size / 2)
		{
			do_rra(stack, size);
			i++;
		}
		else
		{
			do_ra(stack, size);
			i--;
		}
	}
}

void	smart_rotate_b(int *stack, int size, int index)
{
	int	i;

	i = index - 1;
	while (i >= 0 && i < size)
	{
		if (index > size / 2)
		{
			do_rrb(stack, size);
			i++;
		}
		else
		{
			do_rb(stack, size);
			i--;
		}
	}
}

void	small_size_sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	if (*size_a == 1)
		do_sa(stack_a, *size_a);
	else if (*size_a == 2)
		three_elements_sort(stack_a, *size_a);
	else
	{
		while (*size_a != 2)
			do_pb(stack_a, stack_b, size_a, size_b);
		three_elements_sort(stack_a, *size_a);
		while (*size_b != -1)
		{
			smart_rotate_a(stack_a, *size_a, find_closest(stack_a, *size_a, stack_b[0]));
			do_pa(stack_a, stack_b, size_a, size_b);
		}
		smart_rotate_a(stack_a, *size_a, find_min(stack_a, *size_a));
	}
}

int		find_first_unsorted_max(int *stack, int size)
{
	while (size != -1 && find_max(stack, size) == size)
	{
		size--;
	}
	return (find_max(stack, size));
}

int		get_range(int *stack, int size, int max, int min)
{
	int	i;
	int	range;

	i = 0;
	range = 0;
	while (i <= size)
	{
		if (stack[i] >= min && stack[i] <= max) 
		{
			range++;
		}
		i++;
	}
	return (range);
}

int		get_predecessor(int *stack, int size, int n)
{
	int	i;
	int	distance;
	int	closest;

	i = 0;
	distance = 2147483647;
	closest = -1;
	while (i <= size)
	{
		if (abs(stack[i] - n) <= distance && stack[i] < n) 
		{
			distance = abs(stack[i] - n);
			closest = i;
		}
		i++;
	}
	if (closest == -1)
		return (find_min(stack, size));
	return (closest);
}

int		get_successor(int *stack, int size, int n)
{
	int	i;
	int	distance;
	int	closest;

	i = 0;
	distance = 2147483647;
	closest = -1;
	while (i <= size)
	{
		if (abs(stack[i] - n) <= distance && stack[i] > n) 
		{
			distance = abs(stack[i] - n);
			closest = i;
		}
		i++;
	}
	if (closest == -1)
		return (find_min(stack, size));
	return (closest);
}

int		index_of(int *stack, int size, int n)
{
	int		i;

	i = 0;
	while (i <= size && stack[i] != n)
		i++;
	if (stack[i] == n)
		return (i);
	return (-1);
}

int		find_next_in_range(int *stack, int size, int max, int min)
{
	int	i;
	int	distance;
	int	closest;

	i = 0;
	distance = 2147483647;
	closest = -1;
	while (i <= size)
	{
		if ((abs(stack[i] - min) <= distance || abs(stack[i] - max) <= distance) && (stack[i] >= min && stack[i] <= max))
		{
			if (abs(stack[i] - min) <= distance)
				distance = abs(stack[i] - min);
			else
				distance = abs(stack[i] - min);
			closest = i;
		}
		i++;
	}
	return (closest);
}

void	sort_chunk(int *stack_a, int *stack_b, int *size_a, int *size_b, int max, int min)
{
	int		i;
	int		tmp;
	int		chunk_size;

	chunk_size = get_range(stack_a, *size_a, stack_a[max], stack_a[min]);
	max = stack_a[max];
	min = stack_a[min];
	while (chunk_size > 0)
	{
		while (stack_a[0] < min || stack_a[0] > max)
			do_rra(stack_a, *size_a);
		do_pb(stack_a, stack_b, size_a, size_b);
		chunk_size--;
	}
	max = find_max(stack_b, *size_b);
	smart_rotate_a(stack_a, *size_a, find_closest(stack_a, *size_a, stack_b[max]));
	while (*size_b > -1)
	{
		max = find_max(stack_b, *size_b);
		min = find_min(stack_b, *size_b);
		if ((min < max && min < *size_b / 4) || (min > max && min >= *size_b / 4))
		{
			smart_rotate_b(stack_b, *size_b, min);
			do_pa(stack_a, stack_b, size_a, size_b);
			do_ra(stack_a, *size_a);
		}
		else
		{
			smart_rotate_b(stack_b, *size_b, max);
			do_pa(stack_a, stack_b, size_a, size_b);
		}
		chunk_size--;
	}
}

int		get_limit(int *stack, int size, int max, int range)
{
	int	i;
	int	distance;
	int	closest;

	while (range > 1)
	{
		i = 0;
		distance = 2147483647;
		closest = -1;
		while (i <= size)
		{
			if (abs(stack[i] - max) <= distance && stack[i] < max) 
			{
				distance = abs(stack[i] - max);
				closest = i;
			}
			i++;
		}
		max = stack[closest];
		range--;
	}
	if (closest == -1)
		return (find_min(stack, size));
	return (closest);
}

void	big_size_sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int		min;
	int		tmp;
	int		max;
	int		coef;
	int 	chunks;

	if (*size_a > 200)
		coef = 50;
	else
		coef = 20;
	chunks = *size_a / coef + 1;
	max =  find_max(stack_a, *size_a);
	while (chunks > 0)
	{
		if (chunks == 1)
			min = find_min(stack_a, *size_a);
		else
			min = get_limit(stack_a, *size_a, stack_a[max], *size_a / chunks);
		tmp = stack_a[min];
		sort_chunk(stack_a, stack_b, size_a, size_b, max, min);
		max = get_predecessor(stack_a, *size_a, tmp);
		chunks--;
	}
	min = find_min(stack_a, *size_a);
	smart_rotate_a(stack_a, *size_a, min);
}