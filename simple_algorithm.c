/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:58:16 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/14 20:28:43 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted_and_not_empty(t_context *c)
{
	int	i;

	if (c->a.size < 2)
		return (1);
	i = 0;
	while (i < c->a.size - 1)
	{
		if (c->a.data[i] > c->a.data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	swap(t_context *c, int *swaped)
{
	op_sa(c);
	*swaped = 1;
}

void	bubble_sort(t_context *c)
{
	int	i;
	int	j;
	int	swaped;

	if (is_sorted_and_not_empty(c))
		return ;
	i = 0;
	while (i < c->a.size)
	{
		swaped = 0;
		j = 0;
		while (j < c->a.size - 1 - i)
		{
			if (c->a.data[0] > c->a.data[1])
				swap(c, &swaped);
			op_ra(c);
			j++;
		}
		j = 0;
		while (j++ < c->a.size - 1 - i)
			op_rra(c);
		if (swaped == 0)
			break ;
		i++;
	}
}
