/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:28:46 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/12 20:58:50 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merge_init(t_helper *t, int *arr, int left, int mid)
{
	t->l = mallocer(arr, t->n1, left);
	t->r = mallocer(arr, t->n2, mid + 1);
	if (!t->l || !t->r)
	{
		free(t->l);
		free(t->r);
		return (0);
	}
	t->left = left;
	return (1);
}

int	*make_copy_a(t_context *c)
{
	int	*result;
	int	i;

	if (c->a.size == 0)
		return (NULL);
	result = malloc((c->a).size * sizeof(int));
	if (!result)
		return (NULL);
	i = 0;
	while (i < c->a.size)
	{
		result[i] = c->a.data[i];
		i++;
	}
	return (result);
}

int	find_index_in_sorted(int *copy, int size, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (copy[mid] == value)
			return (mid);
		else if (copy[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

int	indexize_a(t_context *c, int *copy)
{
	int	i;
	int	rank;

	i = 0;
	while (i < c->a.size)
	{
		rank = find_index_in_sorted(copy, c->a.size, c->a.data[i]);
		if (rank == -1)
			return (0);
		c->a.data[i] = rank;
		i++;
	}
	return (1);
}

int	my_sqrt(int n)
{
	int	i;

	i = 0;
	while ((long)(i + 1)*(i + 1) <= n)
		i++;
	return (i);
}
