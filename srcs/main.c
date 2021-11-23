/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:52:44 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/11/22 12:43:15 by mbouzaie         ###   ########.fr       */
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
	while (i < (n - 1))
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int     main(int ac, char **av)
{
	int     i;
	int     val;
	int		size_b;
	int     *stack_a;
	int		*stack_b;

	i = 1;
	size_b = -1;
	if (ac > 2)
	{
		stack_a = (int *)malloc(ac * sizeof(int));
		stack_b = (int *)malloc(ac * sizeof(int));
		while (i < ac)
		{
			val= ft_atoi(av[i]);
			if ((av[i][0] != '0' && val == 0) || find(stack_a, val, i))
			{
				ft_putstr_fd("Error\n", 2);
				free(stack_a);
				free(stack_b);
				exit(0);
			}
			else
				stack_a[i - 1] = val;
			i++;
		}
		i = i - 2;
		small_size_sort(stack_a, stack_b, &i, &size_b);
	}
	else
		ft_putchar_fd('\n', 1);
}