/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:52:44 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 19:16:54 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find(int *tab, int val, int n)
{
	int	i;

	i = 0;
	while (tab[i] != val && i < n - 1)
		i++;
	return (tab[i] == val && i < (n - 1));
}

static void	add_value(t_stack *stack, char **str, int index, int begin)
{
	long int	val;

	val = ft_atol(str[index]);
	if ((str[index][0] != '0' && val == 0) || val > INT_MAX || val < INT_MIN \
		|| find(stack->cntr, (int)val, index))
	{
		ft_putstr_fd("Error\n", 2);
		free(stack->cntr);
		free(stack);
		exit(0);
	}
	else
	{
		if (begin == 1)
			stack->cntr[index - 1] = (int)val;
		else
			stack->cntr[index] = (int)val;
	}
}

static t_stack	*create_stack(char **str, int begin, int size, t_stack *b)
{
	int				i;
	t_stack			*stack;

	stack = (t_stack *)malloc(sizeof(t_stack) + 1);
	if (!stack)
		return (NULL);
	stack->cntr = (int *)malloc(size * sizeof(int) * 2);
	b->cntr = (int *)malloc(size * sizeof(int) * 2);
	if (!stack->cntr || !b->cntr)
		return (NULL);
	i = begin;
	while (i < size)
	{
		add_value(stack, str, i, begin);
		i++;
	}
	stack->size = i - begin - 1;
	return (stack);
}

static t_stack	*create_from_string(char *arg, t_stack *b)
{
	int		i;
	char	**str;
	t_stack	*a;

	i = 0;
	str = ft_split(arg, ' ');
	while (str[i] != NULL)
		i++;
	a = create_stack(str, 0, i, b);
	if (!a)
		return (NULL);
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (a);
}

int	main(int ac, char **av)
{
	t_stack			*a;
	t_stack			b;

	b.size = -1;
	if (ac >= 2)
	{
		if (ac == 2)
			a = create_from_string(av[1], &b);
		else
			a = create_stack(av, 1, ac, &b);
		if (!is_sorted(a))
		{
			if (a->size < 5)
				small_size_sort(a, &b);
			else
				big_size_sort(a, &b);
		}
		free(b.cntr);
		free(a->cntr);
		free(a);
	}
}
