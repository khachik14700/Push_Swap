/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:14:17 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/10 17:38:19 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_ra(t_context *c)
{
	int	tmp;
	int	i;

	if ((c->a).size < 2)
		return ;
	tmp = (c->a).data[0];
	i = 0;
	while (i < (c->a).size - 1)
	{
		(c->a).data[i] = (c->a).data[i + 1];
		i++;
	}
	(c->a).data[i] = tmp;
	(c->st).ra++;
	(c->st).total++;
	write(1, "ra\n", 3);
}

void	op_rb(t_context *c)
{
	int	tmp;
	int	i;

	if ((c->b).size < 2)
		return ;
	tmp = (c->b).data[0];
	i = 0;
	while (i < (c->b).size - 1)
	{
		(c->b).data[i] = (c->b).data[i + 1];
		i++;
	}
	(c->b).data[i] = tmp;
	(c->st).rb++;
	(c->st).total++;
	write(1, "rb\n", 3);
}

static void	process_a(t_context *c)
{
	int	tmp;
	int	i;

	tmp = (c->a).data[0];
	i = 0;
	while (i < (c->a).size - 1)
	{
		(c->a).data[i] = (c->a).data[i + 1];
		i++;
	}
	(c->a).data[i] = tmp;
}

static void	process_b(t_context *c)
{
	int	tmp;
	int	i;

	tmp = (c->b).data[0];
	i = 0;
	while (i < (c->b).size - 1)
	{
		(c->b).data[i] = (c->b).data[i + 1];
		i++;
	}
	(c->b).data[i] = tmp;
}

void	op_rr(t_context *c)
{
	if (((c->a).size < 2) && ((c->b).size < 2))
		return ;
	if ((c->a).size >= 2)
		process_a(c);
	if ((c->b).size >= 2)
		process_b(c);
	(c->st).rr++;
	(c->st).total++;
	write(1, "rr\n", 3);
}
