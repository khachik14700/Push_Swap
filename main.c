/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:18:06 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/14 20:55:24 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **arr, t_context *context)
{
	if (str_cmp(arr[0], "--adaptive"))
		context->mode = 1;
	else if (str_cmp(arr[0], "--simple"))
		context->mode = 2;
	else if (str_cmp(arr[0], "--medium"))
		context->mode = 3;
	else if (str_cmp(arr[0], "--complex"))
		context->mode = 4;
	else if (str_cmp(arr[0], "--bench"))
		context->bench = 1;
	else if (!is_valid(arr))
		return (context->mode = -1, context->mode);
	if (context->mode != 0 || context->bench == 1)
		context->mode = check_second_arg(arr, context);
	else if (context->mode == 0)
		context->mode = 1;
	return (context->mode);
}

int	elem_count(char **argv, int argc)
{
	int	i;
	int	j;
	int	count;
	int	in_word;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		in_word = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] != ' ' && in_word == 0)
			{
				in_word = 1;
				++count;
			}
			if (argv[i][j] == ' ')
				in_word = 0;
			++j;
		}
		++i;
	}
	return (count);
}

char	*get_elem(char *str, int *j)
{
	char	*substr;
	int		a;
	int		i;

	i = 0;
	while (str[*j] == ' ' && str[*j] != '\0')
		++(*j);
	a = *j;
	while (str[*j] != ' ' && str[*j] != '\0')
		++(*j);
	substr = (char *)malloc(*j - a + 1);
	if (!substr)
		return (NULL);
	while (str[a] != '\0' && str[a] != ' ')
	{
		substr[i] = str[a];
		++a;
		++i;
	}
	substr[i] = '\0';
	return (substr);
}

char	**parse(char **argv, int argc)
{
	int		i;
	int		j;
	char	**arr;
	int		k;

	arr = (char **)malloc(sizeof(char *) * (elem_count(argv, argc) + 1));
	if (!arr)
		return (NULL);
	i = 1;
	k = 0;
	while (i++ < argc)
	{
		j = 0;
		while (argv[i - 1][j] != '\0')
		{
			while (argv[i - 1][j] == ' ')
				++j;
			if (argv[i - 1][j] == '\0')
				break ;
			arr[k++] = get_elem(argv[i - 1], &j);
			if (!arr[k - 1])
				return (free_all(arr), NULL);
		}
	}
	return (arr[k] = NULL, arr);
}

int	main(int argc, char **argv)
{
	t_context	context;
	char		**arr;

	if (argc == 1)
		return (0);
	else if (have_only_space(argv, argc))
		return (error(), 0);
	arr = parse(argv, argc);
	stats_init(&context);
	if (!arr || check_args(arr, &context) == -1)
		return (free_all(arr), error(), 0);
	if (!initialize_stack(arr, &context))
		return (error(), 0);
	free_all(arr);
	start(&context);
	stack_free(&(context.a));
	stack_free(&(context.b));
}
