/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_new.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:53:48 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/14 20:25:14 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(t_context *c)
{
	int	i;

	i = 0;
	while (i < c->a.size - 1)
	{
		if (c->a.data[i] > c->a.data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	get_max_bits(int n)
{
	int	max;
	int	bits;

	max = n - 1;
	bits = 0;
	while (max > 0)
	{
		bits++;
		max = max / 2;
	}
	return (bits);
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

static void	helper_2(t_context *c, t_helper_2 *t, int n, int bit)
{
	int	x;

	t->k = 0;
	while (t->k < n)
	{
		x = c->a.data[0];
		if ((x >> bit) & 1)
			op_ra(c);
		else
			op_pb(c);
		t->k++;
	}
}

void	radix_sort(t_context *c)
{
	t_helper_2	t;
	int			bits;
	int			bit;
	int			n;

	if (!helper(c, &t))
		return ;
	bits = get_max_bits(c->a.size);
	bit = 0;
	while (bit < bits)
	{
		n = c->a.size;
		if (n <= 1)
			return ;
		helper_2(c, &t, n, bit);
		while (c->b.size > 0)
			op_pa(c);
		if (is_sorted_a(c))
			return ;
		bit++;
	}
}
