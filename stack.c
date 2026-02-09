/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:12:06 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/09 20:29:54 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(t_stack *s, int cap)
{
	s->data = (int *)malloc(cap * sizeof(int));
	if (!s->data)
		return (0);
	s->size = 0;
	s->cap = cap;
	return (1);
}

void	stack_free(t_stack *s)
{
	if (s->data)
		free(s->data);
	s->data = NULL;
	s->size = 0;
	s->cap = 0;
}

void	stats_init(t_stats *st)
{
	st->total = 0;
	st->sa = 0;
	st->sb = 0;
	st->ss = 0;
	st->pa = 0;
	st->pb = 0;
	st->ra = 0;
	st->rb = 0;
	st->rr = 0;
	st->rra = 0;
	st->rrb = 0;
	st->rrr = 0;
}
