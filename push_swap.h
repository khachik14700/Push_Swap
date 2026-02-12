/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:10:42 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/12 21:06:56 by kkhachat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

#endif
