/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:11:38 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/12 21:06:28 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	transfer_left_run_to_b(t_context *c, int lenL)
{
	int	i;

	i = 0;
	while (i < lenL)
	{
		op_pb(c);
		op_rb(c);
		i++;
	}
}

static void	merge_round(t_context *c, int len)
{
	int	n;
	int	processed;
	int	len_l;
	int	len_r;
	int	j;

	n = c->a.size;
	processed = 0;
	while (processed < n)
	{
		len_l = min_int(len, n - processed);
		len_r = min_int(len, n - processed - len_l);
		if (len_r > 0)
			merge_runs(c, len_l, len_r);
		else
		{
			j = 0;
			while (j++ < len_l)
				op_ra(c);
		}
		processed += (len_l + len_r);
	}
}

static void	rotate_to_min_helper(t_context *c, int *min_val,
			int *min_idx, int i)
{
	if (c->a.data[i] < *min_val)
	{
		*min_val = c->a.data[i];
		*min_idx = i;
	}
}

static void	rotate_to_min(t_context *c)
{
	int	min_val;
	int	min_idx;
	int	i;
	int	k;

	min_val = c->a.data[0];
	min_idx = 0;
	i = 1;
	while (i < c->a.size)
	{
		rotate_to_min_helper(c, &min_val, &min_idx, i);
		i++;
	}
	if (min_idx <= c->a.size / 2)
	{
		k = min_idx;
		while (k--)
			op_ra(c);
	}
	else
	{
		k = c->a.size - min_idx;
		while (k--)
			op_rra(c);
	}
}

void	merge_sort(t_context *c)
{
	int	len;

	len = 1;
	while (len < c->a.size)
	{
		merge_round(c, len);
		len *= 2;
	}
	rotate_to_min(c);
}
