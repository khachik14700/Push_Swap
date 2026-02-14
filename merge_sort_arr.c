/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:35:02 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/12 21:07:53 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*mallocer(int *arr, int n, int start)
{
	int	*result;
	int	i;

	result = (int *)malloc(sizeof(int) * n);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = arr[start + i];
		i++;
	}
	return (result);
}

static void	push(int *arr, t_helper *t)
{
	t->i = 0;
	t->j = 0;
	while ((t->i < t->n1) && (t->j < t->n2))
	{
		if (t->l[t->i] <= t->r[t->j])
		{
			arr[t->left] = t->l[t->i];
			(t->i)++;
		}
		else
		{
			arr[t->left] = t->r[t->j];
			(t->j)++;
		}
		(t->left)++;
	}
}

static void	merge(int *arr, int left, int mid, int right)
{
	t_helper	t;

	t.n1 = mid - left + 1;
	t.n2 = right - mid;
	merge_init(&t, arr, left, mid);
	push(arr, &t);
	while (t.i < t.n1)
	{
		arr[t.left] = t.l[t.i];
		(t.i)++;
		(t.left)++;
	}
	while (t.j < t.n2)
	{
		arr[t.left] = t.r[t.j];
		(t.j)++;
		(t.left)++;
	}
	free(t.l);
	free(t.r);
}

static void	merge_sort_a(int *arr, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		merge_sort_a(arr, left, mid);
		merge_sort_a(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void	merge_sort_arr(int *arr, int size)
{
	if (arr == NULL)
		return ;
	if (size <= 0)
		return ;
	merge_sort_a(arr, 0, size - 1);
}
