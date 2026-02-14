/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgurginy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:26:39 by vgurginy          #+#    #+#             */
/*   Updated: 2026/02/14 18:00:08 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_disorder(double disorder)
{
	int		n;
	char	*str;

	disorder *= 100;
	write (2, "[bench] disorder:  ", 19);
	n = (int)disorder;
	str = int_to_char(n);
	if (!str)
		return (error(), (void)1);
	if (n < 10)
		write (2, str, 1);
	else if (n < 100)
		write (2, str, 2);
	else
		write (2, str, 3);
	write (2, ".", 1);
	disorder -= n;
	disorder *= 10;
	n = disorder;
	str[0] = '0' + n;
	disorder -= n;
	disorder *= 10;
	n = disorder;
	str[1] = '0' + n;
	return (write (2, str, 2), write (2, "%\n", 2), free(str), (void)1);
}

void	print_strategy(t_context *context, double disorder)
{
	write (2, "[bench] strategy:  ", 19);
	if (context->mode == 1)
	{
		if (disorder < 0.2)
			write (2, "Adaptive / O(n^2)\n", 18);
		else if (disorder >= 0.2 && disorder < 0.5)
			write (2, "Adaptive / O(n\xE2\x88\x9An)\n", 20);
		else if (disorder >= 0.5)
			write (2, "Adaptive / O(nlog(n))\n", 22);
	}
	else if (context->mode == 2)
		write (2, "Simple / O(n^2)\n", 16);
	else if (context->mode == 3)
		write (2, "Medium / O(n\xE2\x88\x9An)\n", 18);
	else if (context->mode == 4)
		write (2, "Complex / O(nlog(n))\n", 22);
}

void	print_total_ops(t_context *context)
{
	char	*str;
	int		size;

	write (2, "[bench] total_ops:  ", 20);
	str = int_to_char((context->st).total);
	if (!str)
		return (error(), (void)1);
	size = 0;
	while (str[size])
		size++;
	write (2, str, size);
	write (2, "\n", 1);
	free(str);
}

void	free_strs(char *str1, char *str2, char *str3, char *str4)
{
	free(str1);
	free(str2);
	free(str3);
	free(str4);
}

void	print_operations_1(t_context *context)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	char	*str5;

	str1 = int_to_char((context->st).sa);
	str2 = int_to_char((context->st).sb);
	str3 = int_to_char((context->st).ss);
	str4 = int_to_char((context->st).pa);
	str5 = int_to_char((context->st).pb);
	if (!str1 || !str2 || !str3 || !str4 || !str5)
		return (error(), (void)1);
	write (2, "[bench] sa:  ", 13);
	write (2, str1, str_len(str1));
	write (2, "  sb:  ", 7);
	write (2, str2, str_len(str2));
	write (2, "  ss:  ", 7);
	write (2, str3, str_len(str3));
	write (2, "  pa:  ", 7);
	write (2, str4, str_len(str4));
	write (2, "  pb:  ", 7);
	write (2, str5, str_len(str5));
	write (2, "\n", 1);
	return (free_strs(str1, str2, str3, str4), free(str5), (void)1);
}
