/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:10:42 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/12 20:25:38 by vgurginy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*data;
	int	size;
	int	cap;
}	t_stack;

typedef struct s_stats
{
	long	total;
	long	sa;
	long	sb;
	long	ss;
	long	pa;
	long	pb;
	long	ra;
	long	rb;
	long	rr;
	long	rra;
	long	rrb;
	long	rrr;
}	t_stats;

typedef struct s_context
{
	t_stack	a;
	t_stack	b;
	t_stats	st;
	int		mode;
	int		bench;
}	t_context;

int		stack_init(t_stack *s, int cap);
void	stack_free(t_stack *s);
void	stats_init(t_context *c);
void	op_sa(t_context *c);
void	op_sb(t_context *c);
void	op_ss(t_context *c);
void	op_pb(t_context *c);
void	op_pa(t_context *c);
void	op_ra(t_context *c);
void	op_rb(t_context *c);
void	op_rr(t_context *c);
void	op_rra(t_context *c);
void	op_rrb(t_context *c);
void	op_rrr(t_context *c);
char	**parse(char **argv, int argc);
char	*get_elem(char *str, int *j);
int		elem_count(char **argv, int argc);
int		check_args(char **arr, t_context *context);
int		check_second_arg(char **arr, t_context *context);
int		is_valid(char **arr);
int		is_valid_number(char *str);
int		str_cmp(const char *str1, const char *str2);
int		error(void);
void	free_all(char **arr);
char	*int_to_char(int n);
int		str_len(char *str);
int		lex_cmp(char *str1, char *str2);
int		is_integer(char *str);
int		have_duplicate(char **arr);
void	sign_to_char(long long n, int *i, char *str);
int		len_arr(char **arr);
int		char_to_int(char *str);
void	arr_to_stack(char **arr, t_stack *stack);
int		initialize_stack(char **arr, t_context *context);
void	bubble_sort(t_context *c);

#endif
