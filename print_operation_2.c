/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:54:06 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/14 17:33:31 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_operations_char(char **strs, t_context *context)
{
	int	i;

	i = 0;
	strs[i++] = int_to_char((context->st).ra);
	if (!strs[i - 1])
		return (error());
	strs[i++] = int_to_char((context->st).rb);
	if (!strs[i - 1])
		return (error());
	strs[i++] = int_to_char((context->st).rr);
	if (!strs[i - 1])
		return (error());
	strs[i++] = int_to_char((context->st).rra);
	if (!strs[i - 1])
		return (error());
	strs[i++] = int_to_char((context->st).rrb);
	if (!strs[i - 1])
		return (error());
	strs[i++] = int_to_char((context->st).rrr);
	if (!strs[i - 1])
		return (error());
	strs[i] = NULL;
}

void	print_operations_2(t_context *context)
{
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * 7);
	if (!strs)
		return (error());
	make_operations_char(strs, context);
	write (2, "[bench] ra:  ", 13);
	write (2, strs[0], str_len(strs[0]));
	write (2, "  rb:  ", 7);
	write (2, strs[1], str_len(strs[1]));
	write (2, "  rr:  ", 7);
	write (2, strs[2], str_len(strs[2]));
	write (2, "  rra:  ", 8);
	write (2, strs[3], str_len(strs[3]));
	write (2, "  rrb:  ", 8);
	write (2, strs[4], str_len(strs[4]));
	write (2, "  rrr:  ", 8);
	write (2, strs[5], str_len(strs[5]));
	write (2, "\n", 1);
	return (free_all(strs), (void)1);
}
