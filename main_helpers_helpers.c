/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:14:09 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/12 18:31:52 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sign_to_char(long long n, int *i, char *str)
{
	if (n < 0)
	{
		n *= -1;
		str[(*i)++] = '-';
	}
	if (n > 9)
		sign_to_char(n / 10, i, str);
	str[(*i)++] = '0' + (n % 10);
}

char	*int_to_char(int n)
{
	char	*str;
	int		i;

	str = (char *)malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	sign_to_char((long long)n, &i, str);
	str[i] = '\0';
	return (str);
}

int	lex_cmp(char *str1, char *str2)
{
	int	i;

	if (str_len(str1) > str_len(str2))
		return (1);
	if (str_len(str1) < str_len(str2))
		return (0);
	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		++i;
	}
	return (0);
}

int	is_integer(char *str)
{
	int		n;
	char	*s1;
	char	*s2;

	s1 = int_to_char(INT_MIN);
	s2 = int_to_char(INT_MAX);
	if (!s1 || !s2)
		return (free(s1), free(s2), 0);
	if (str[0] == '-')
		n = lex_cmp(str + 1, s1 + 1);
	else if (str[0] == '+')
		n = lex_cmp(str + 1, s2);
	else
		n = lex_cmp(str, s2);
	free(s1);
	free(s2);
	if (n > 0)
		return (0);
	return (1);
}
