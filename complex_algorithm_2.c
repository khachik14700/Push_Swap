/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:03:37 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/11 20:05:27 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static void	merge_runs_helper(t_context *c, int *takenl, int *takenr, int lenL)
{
	*takenl = 0;
	*takenr = 0;
	transfer_left_run_to_b(c, lenL);
}

static void	merge_runs_helper_2(t_context *c, int flag,
			int *takenl, int *takenr)
{
	if (flag)
	{
		op_pa(c);
		op_ra(c);
		(*takenl)++;
	}
	else
	{
		op_ra(c);
		(*takenr)++;
	}
}

void	merge_runs(t_context *c, int lenL, int lenR)
{
	int	takenl;
	int	takenr;
	int	total;
	int	i;

	merge_runs_helper(c, &takenl, &takenr, lenL);
	total = lenL + lenR;
	i = 0;
	while (i < total)
	{
		if (takenl == lenL)
			merge_runs_helper_2(c, 0, &takenl, &takenr);
		else if (takenr == lenR)
			merge_runs_helper_2(c, 1, &takenl, &takenr);
		else
		{
			if (c->b.data[0] <= c->a.data[0])
				merge_runs_helper_2(c, 1, &takenl, &takenr);
			else
				merge_runs_helper_2(c, 0, &takenl, &takenr);
		}
		i++;
	}
}
