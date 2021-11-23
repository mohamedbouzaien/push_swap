/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:51:23 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/11/22 12:47:35 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/libft.h"

void	swap(int *a, int *b)
{
	int     tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	do_sa(int *stack_a, int size)
{
	if (size > 0)
	{
		swap(&stack_a[0], &stack_a[1]);
		ft_putendl_fd("sa", 1);
	}
}

void	do_sb(int *stack_b, int size)
{
	if (size > 0)
	{
		swap(&stack_b[0], &stack_b[1]);
		ft_putendl_fd("sb", 1);
	}
}

void	do_ss(int *stack_a, int *stack_b, int size_a, int size_b)
{
	if (size_a > 0)
		swap(&stack_a[0], &stack_a[1]);
	if (size_b > 0)
		swap(&stack_b[0], &stack_b[1]);
	ft_putendl_fd("ss", 1);
}