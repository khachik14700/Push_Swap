/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:12:06 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/10 18:18:41 by kkhachat         ###   ########.fr       */
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

void	stats_init(t_context *c)
{
	c->st.total = 0;
	c->st.sa = 0;
	c->st.sb = 0;
	c->st.ss = 0;
	c->st.pa = 0;
	c->st.pb = 0;
	c->st.ra = 0;
	c->st.rb = 0;
	c->st.rr = 0;
	c->st.rra = 0;
	c->st.rrb = 0;
	c->st.rrr = 0;
	c->mode = 0;
	c->bench = 0;
}
