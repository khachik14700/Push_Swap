/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_helper_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:59:01 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/12 21:00:24 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_pos_in_range(t_context *c, int L, int R)
{
	int	best_pos;
	int	best_cost;
	int	pos;
	int	cost_bottom;
	int	cost;

	best_pos = -1;
	best_cost = c->a.size + 1;
	pos = 0;
	while (pos < c->a.size)
	{
		if (c->a.data[pos] <= R && c->a.data[pos] >= L)
		{
			cost_bottom = c->a.size - pos;
			cost = min_int(pos, cost_bottom);
			if (cost < best_cost)
			{
				best_cost = cost;
				best_pos = pos;
			}
		}
		pos++;
	}
	return (best_pos);
}

void	rotate_a_to_pos(t_context *c, int pos)
{
	int	i;

	if (pos == -1)
		return ;
	if (pos <= (c->a.size / 2))
	{
		i = 0;
		while (i++ < pos)
			op_ra(c);
	}
	else
	{
		i = 0;
		while (i++ < (c->a.size - pos))
			op_rra(c);
	}
}

void	push_chunk(t_context *c, int L, int R)
{
	int	mid;
	int	pos;

	mid = (L + R) / 2;
	while (1)
	{
		pos = find_best_pos_in_range(c, L, R);
		if (pos == -1)
			break ;
		rotate_a_to_pos(c, pos);
		op_pb(c);
		if (c->b.data[0] < mid)
			op_rb(c);
	}
}
