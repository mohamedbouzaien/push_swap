/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:52:44 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 01:20:30 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int     find(int *tab, int  val, int n)
{
	int i;

	i = 0;
	while (tab[i] != val && i < n - 1)
		i++;
	return (tab[i] == val && i < (n - 1));
}

int		is_sorted(int *stack, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

t_stack	*create_stack(char **str, int begin, int size)
{
	int				i;
	t_stack			*stack;
	long int		val;

	stack = (t_stack *)malloc(sizeof(t_stack) + 1);
	stack->cntr = (int *)malloc(size * sizeof(int) * 2);
	i = begin;
	while (i < size)
	{
		val= ft_atol(str[i]);
		if ((str[i][0] != '0' && val == 0) || val > INT_MAX || val < INT_MIN \
			|| find(stack->cntr, (int)val, i))
		{
			ft_putstr_fd("Error\n", 2);
			free(stack->cntr);
			free(stack);
			exit(0);
		}
		else
		{
			if (begin == 1)
				stack->cntr[i - 1] = (int)val;
			else
				stack->cntr[i] = (int)val;
		}
		i++;
	}
	stack->size = i - begin - 1;
	return (stack);
}

int     main(int ac, char **av)
{
	int				i;
	t_stack			*a;
	t_stack			b;
	char			**str;
	int				*stack_b;

	i = 0;
	b.size = -1;
	if (ac >= 2)
	{
		if (ac == 2)
		{
			str = ft_split(av[1], ' ');
			while (str[i] != NULL)
				i++;
			a = create_stack(str, 0, i);
			i = 0;
			while (str[i])
			{
				free(str[i]);
				i++;
			}
			free(str);	
			stack_b = (int *)malloc(i * sizeof(int) * 2);
		}
		else
		{
			a = create_stack(av, 1, ac);
			stack_b = (int *)malloc(ac * sizeof(int) * 2);
		}
		if (!is_sorted(a->cntr, a->size))
		{
			if (i < 5)
				small_size_sort(a->cntr, stack_b, &(a->size), &(b.size));
			else
				big_size_sort(a->cntr,stack_b, &(a->size), &(b.size));
		}
		free(stack_b);
		free(a->cntr);
		free(a);
	}
	else
		ft_putchar_fd('\n', 1);
}