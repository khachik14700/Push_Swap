/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhachat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:10:42 by kkhachat          #+#    #+#             */
/*   Updated: 2026/02/10 18:19:25 by kkhachat         ###   ########.fr       */
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

#endif
