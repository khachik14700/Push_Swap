/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:24:31 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/12 21:01:11 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	finde_pos_max_in_b(t_context *c)
{
	int	max;
	int	pos_max;
	int	i;

	max = c->b.data[0];
	pos_max = 0;
	i = 1;
	while (i < c->b.size)
	{
		if (c->b.data[i] > max)
		{
			max = c->b.data[i];
			pos_max = i;
		}
		i++;
	}
	return (pos_max);
}

static void	rotate_b_to_pos(t_context *c, int pos)
{
	int	i;

	if (pos == -1)
		return ;
	if (pos <= (c->b.size / 2))
	{
		i = 0;
		while (i++ < pos)
			op_rb(c);
	}
	else
	{
		i = 0;
		while (i++ < (c->b.size - pos))
			op_rrb(c);
	}
}

static int	helper(t_context *c, t_helper_2 *t)
{
	t->copy = make_copy_a(c);
	if (!t->copy)
		return (0);
	merge_sort_arr(t->copy, c->a.size);
	if (!indexize_a(c, t->copy))
	{
		free(t->copy);
		return (0);
	}
	free(t->copy);
	return (1);
}

void	chunk_based_sort(t_context *c)
{
	t_helper_2	t;

	if (!helper(c, &t))
		return ;
	t.k = (int)my_sqrt(c->a.size);
	if (t.k < 1)
		t.k = 1;
	t.chunk_size = (c->a.size + t.k - 1) / t.k;
	t.chunk = 0;
	while (t.chunk < t.k)
	{
		t.l = t.chunk * t.chunk_size;
		t.r = min_int(c->a.size - 1, t.l + t.chunk_size - 1);
		push_chunk(c, t.l, t.r);
		(t.chunk)++;
	}
	while (c->b.size > 0)
	{
		t.pos = finde_pos_max_in_b(c);
		rotate_b_to_pos(c, t.pos);
		op_pa(c);
	}
}
