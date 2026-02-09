/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:23:05 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/09 20:31:12 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_context	c;

	stack_init(&c.a, 8);
	stack_init(&c.b, 8);
	stats_init(&c.st);
	stack_free(&c.a);
	stack_free(&c.b);
	return (0);
}
