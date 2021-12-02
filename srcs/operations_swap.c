/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:51:23 by mbouzaie          #+#    #+#             */
/*   Updated: 2021/12/02 19:09:53 by mbouzaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	do_sa(t_stack *a)
{
	if (a->size > 0)
	{
		swap(&(a->cntr[0]), &(a->cntr[1]));
		ft_putendl_fd("sa", 1);
	}
}

void	do_sb(t_stack *b)
{
	if (b->size > 0)
	{
		swap(&(b->cntr[0]), &(b->cntr[1]));
		ft_putendl_fd("sb", 1);
	}
}

void	do_ss(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		swap(&(a->cntr[0]), &(a->cntr[1]));
	if (b->size > 0)
		swap(&(b->cntr[0]), &(b->cntr[1]));
	ft_putendl_fd("ss", 1);
}
