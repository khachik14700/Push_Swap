/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:43:04 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/10 17:13:55 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_sa(t_context *c)
{
	int	tmp;

	if ((c->a).size < 2)
		return ;
	tmp = (c->a).data[0];
	(c->a).data[0] = (c->a).data[1];
	(c->a).data[1] = tmp;
	(c->st).sa++;
	(c->st).total++;
	write(1, "sa\n", 3);
}

void	op_sb(t_context *c)
{
	int	tmp;

	if ((c->b).size < 2)
		return ;
	tmp = (c->b).data[0];
	(c->b).data[0] = (c->b).data[1];
	(c->b).data[1] = tmp;
	(c->st).sb++;
	(c->st).total++;
	write(1, "sb\n", 3);
}

void	op_ss(t_context *c)
{
	int	tmp;

	if (((c->a).size < 2) && ((c->b).size < 2))
		return ;
	if ((c->a).size >= 2)
	{
		tmp = (c->a).data[0];
		(c->a).data[0] = (c->a).data[1];
		(c->a).data[1] = tmp;
	}
	if ((c->b).size >= 2)
	{
		tmp = (c->b).data[0];
		(c->b).data[0] = (c->b).data[1];
		(c->b).data[1] = tmp;
	}
	(c->st).ss++;
	(c->st).total++;
	write(1, "ss\n", 3);
}

void	op_pb(t_context *c)
{
	int	x;
	int	i;

	if ((c->a).size == 0)
		return ;
	x = (c->a).data[0];
	i = 0;
	while (i < (c->a).size - 1)
	{
		(c->a).data[i] = (c->a).data[i + 1];
		i++;
	}
	(c->a).size--;
	i = (c->b).size;
	while (i > 0)
	{
		(c->b).data[i] = (c->b).data[i - 1];
		i--;
	}
	(c->b).data[0] = x;
	(c->b).size++;
	(c->st).pb++;
	(c->st).total++;
	write(1, "pb\n", 3);
}

void	op_pa(t_context *c)
{
	int	x;
	int	i;

	if ((c->b).size == 0)
		return ;
	x = (c->b).data[0];
	i = 0;
	while (i < (c->b).size - 1)
	{
		(c->b).data[i] = (c->b).data[i + 1];
		i++;
	}
	(c->b).size--;
	i = (c->a).size;
	while (i > 0)
	{
		(c->a).data[i] = (c->a).data[i - 1];
		i--;
	}
	(c->a).data[0] = x;
	(c->a).size++;
	(c->st).pa++;
	(c->st).total++;
	write(1, "pa\n", 3);
}
