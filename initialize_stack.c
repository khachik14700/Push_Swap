/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 17:36:24 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/12 18:45:15 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

int	char_to_int(char *str)
{
	long long	n;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign *= -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	n = 0;
	while (str[i] != '\0')
	{
		n *= 10;
		n += (str[i] - '0');
		++i;
	}
	return ((int)(n * sign));
}

void	arr_to_stack(char **arr, t_stack *stack)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		(stack->data)[i] = char_to_int(arr[i]);
		++i;
	}
}

int	initialize_stack(char **arr, t_context *context)
{
	int	cap;

	cap = len_arr(arr);
	if (!stack_init(&(context->a), cap) || !stack_init(&(context->b), cap))
		return (stack_free(&(context->a)), stack_free(&(context->b)), 0);
	context->a.size = cap;
	arr_to_stack(arr, &context->a);
	return (1);
}
