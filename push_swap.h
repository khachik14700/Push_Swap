/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:10:42 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/14 20:38:15 by kkhachat         ###   ########.fr       */
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

typedef struct s_helper
{
	int	*l;
	int	*r;
	int	n1;
	int	n2;
	int	left;
	int	i;
	int	j;
}	t_helper;

typedef struct s_helper_2
{
	int	*copy;
	int	k;
	int	chunk_size;
	int	chunk;
	int	l;
	int	r;
	int	pos;
}	t_helper_2;

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

void	bubble_sort(t_context *c);
void	transfer_left_run_to_b(t_context *c, int lenL);
int		min_int(int a, int b);
void	merge_runs(t_context *c, int lenL, int lenR);
void	merge_sort(t_context *c);
void	merge_sort_arr(int *arr, int size);
int		*mallocer(int *arr, int n, int start);
int		merge_init(t_helper *t, int *arr, int left, int mid);
int		*make_copy_a(t_context *c);
int		find_index_in_sorted(int *copy, int size, int value);
int		indexize_a(t_context *c, int *copy);
int		my_sqrt(int n);
int		find_best_pos_in_range(t_context *c, int L, int R);
void	rotate_a_to_pos(t_context *c, int pos);
void	push_chunk(t_context *c, int L, int R);
void	chunk_based_sort(t_context *c);

char	**parse(char **argv, int argc);
char	*get_elem(char *str, int *j);
int		elem_count(char **argv, int argc);
int		check_args(char **arr, t_context *context);
int		check_second_arg(char **arr, t_context *context);
int		is_valid(char **arr);
int		is_valid_number(char *str);
int		str_cmp(const char *str1, const char *str2);
void	error(void);
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
int		have_only_space(char **argv, int argc);
double	compute_disorder(t_stack *a);
void	adaptive_sort(double disorder, t_context *context);
void	bench_mode(double disorder, t_context *context);
void	start(t_context *context);
void	print_disorder(double disorder);
void	print_strategy(t_context *context, double disorder);
void	print_total_ops(t_context *context);
void	free_strs(char *str1, char *str2, char *str3, char *str4);
void	print_operations_1(t_context *context);
void	make_operations_char(char **strs, t_context *context);
void	print_operations_2(t_context *context);
void	radix_sort(t_context *c);
int		is_sorted_a(t_context *c);

#endif
