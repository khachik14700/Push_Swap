/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:32:25 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/10 17:42:11 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_context *c)
{
	int	tmp;
	int	i;

	if ((c->a).size < 2)
		return ;
	i = (c->a).size - 1;
	tmp = (c->a).data[i];
	while (i > 0)
	{
		(c->a).data[i] = (c->a).data[i - 1];
		i--;
	}
	(c->a).data[i] = tmp;
	(c->st).rra++;
	(c->st).total++;
	write(1, "rra\n", 4);
}

void	op_rrb(t_context *c)
{
	int	tmp;
	int	i;

	if ((c->b).size < 2)
		return ;
	i = (c->b).size - 1;
	tmp = (c->b).data[i];
	while (i > 0)
	{
		(c->b).data[i] = (c->b).data[i - 1];
		i--;
	}
	(c->b).data[i] = tmp;
	(c->st).rrb++;
	(c->st).total++;
	write(1, "rrb\n", 4);
}

static void	process_a(t_context *c)
{
	int	tmp;
	int	i;

	i = (c->a).size - 1;
	tmp = (c->a).data[i];
	while (i > 0)
	{
		(c->a).data[i] = (c->a).data[i - 1];
		i--;
	}
	(c->a).data[i] = tmp;
}

static void	process_b(t_context *c)
{
	int	tmp;
	int	i;

	i = (c->b).size - 1;
	tmp = (c->b).data[i];
	while (i > 0)
	{
		(c->b).data[i] = (c->b).data[i - 1];
		i--;
	}
	(c->b).data[i] = tmp;
}

void	op_rrr(t_context *c)
{
	if (((c->a).size < 2) && ((c->b).size < 2))
		return ;
	if ((c->a).size >= 2)
		process_a(c);
	if ((c->b).size >= 2)
		process_b(c);
	(c->st).rrr++;
	(c->st).total++;
	write(1, "rrr\n", 4);
}
