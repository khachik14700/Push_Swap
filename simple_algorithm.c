/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:58:16 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/10 20:32:38 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (c->a.size < 2)
		return ;
	i = 0;
	while (i < c->a.size - 1)
	{
		swaped = 0;
		j = 0;
		while (j < c->a.size - i - 1)
		{
			if (c->a.data[0] > c->a.data[1])
				swap(c, &swaped);
			op_ra(c);
			j++;
		}
		j = 0;
		while (j++ < c->a.size - i - 1)
			op_rra(c);
		if (swaped == 0)
			break ;
		i++;
	}
}
