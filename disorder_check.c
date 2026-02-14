/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:03:47 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/14 19:40:29 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < a->size - 1)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs += 1;
			if ((a->data)[i] > (a->data)[j])
				mistakes += 1;
			++j;
		}
		++i;
	}
	return ((double)mistakes / (double)total_pairs);
}

void	adaptive_sort(double disorder, t_context *context)
{
	if (disorder < 0.2)
		bubble_sort(context);
	else if (disorder >= 0.2 && disorder < 0.5)
		chunk_based_sort(context);
	else if (disorder >= 0.5)
		radix_sort(context);
}

void	bench_mode(double disorder, t_context *context)
{
	print_disorder(disorder);
	print_strategy(context, disorder);
	print_total_ops(context);
	print_operations_1(context);
	print_operations_2(context);
}

void	start(t_context *context)
{
	double	disorder;

	disorder = compute_disorder(&(context->a));
	printf("%f\n", disorder);
	if (context->mode == 1)
		adaptive_sort(disorder, context);
	else if (context->mode == 2)
		bubble_sort(context);
	else if (context->mode == 3)
		chunk_based_sort(context);
	else if (context->mode == 4)
		radix_sort(context);
	if (context->bench == 1)
		bench_mode(disorder, context);
}
