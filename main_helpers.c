/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:58:11 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/13 21:57:39 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

int	str_cmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		++i;
	}
	if (str1[i] != str2[i])
		return (0);
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		++i;
	if (str[i] == '-' || str[i] == '+')
		++i;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		++i;
	}
	return (is_integer(str));
}

int	is_valid(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (is_valid_number(arr[i]))
			++i;
		else
			return (0);
	}
	return (have_duplicate(arr));
}

int	check_second_arg(char **arr, t_context *context)
{
	if (context->bench == 1)
	{
		if (str_cmp(arr[1], "--adaptive"))
			context->mode = 1;
		else if (str_cmp(arr[1], "--simple"))
			context->mode = 2;
		else if (str_cmp(arr[1], "--medium"))
			context->mode = 3;
		else if (str_cmp(arr[1], "--complex"))
			context->mode = 4;
		else if (!is_valid(arr + 1))
			return (context->mode = -1, context->mode);
		return (context->mode = 1, context->mode);
	}
	if (str_cmp(arr[1], "--bench"))
	{
		if (!is_valid(arr + 2))
			return (context->mode = -1, context->mode);
		context->bench = 1;
	}
	else if (!is_valid(arr + 1))
		return (context->mode = -1, context->mode);
	return (context->mode);
}
