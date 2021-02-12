/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:04:24 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 13:31:38 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "../../libft/libft.h"

# define PS_BUF			16382

typedef struct			s_ps
{
	int					i;
	int					c;
	int					le;
	int					fe;
	int					elp;
	int					elb;
	int					ela;
	int					lnum;
	int					lnumb;
	int					lpos;
	int					snum;
	int					snumb;
	int					spos;
	int					rot;
	int					len;
	int					alen;
	int					blen;
	const char			*s1;
	const char			*s2;
	char				**a;
	char				**b;
	char				**tmp;
	char				**a1;
	char				*tmp_a;
	char				*tmp_b;
	int					sa;
	int					sb;
	int					ss;
	int					pa;
	int					pb;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
	int					sn;
	int					bn;
}						t_ps;

void					ps_print(char *str);
int						ft_check_args(int ac, int i, char **av);
int						ft_check_dupl(char **av, const char *s1,
						const char *s2, int ac, int i, int rot, int next);
int						ft_stacklen(char **stack);
int						ft_blen(char **s);
int						ft_swap_a(t_ps *stack);
int						ft_swap_b(t_ps *stack);
int						ft_swap_ab(t_ps *stack);
int						ft_push_a(t_ps *stack);
int						ft_push_b(t_ps *stack);
int						ft_push_b_again(t_ps *stack, char **temp);
int						ft_rotate_a(t_ps *stack);
int						ft_rotate_a_mod(t_ps *stack);
int						ft_rotate_b(t_ps *stack);
int						ft_rotate_ab(t_ps *stack);
int						ft_reverse_rotate_a(t_ps *stack);
int						ft_reverse_rotate_b(t_ps *stack);
int						ft_reverse_rotate_ab(t_ps *stack);
void					ft_reset_or_init_vars(t_ps *stack);
int						ft_sorted(t_ps *s, char **elem, const char *s1,
						const char *s2, int ac, int i, int rot);
int						ft_sort_stack(t_ps *stack);
int						ft_largest_anum(t_ps *stack);
int						ft_largest_bnum(t_ps *stack);
int						ft_smallest_anum(t_ps *stack);
int						ft_smallest_bnum(t_ps *stack);
int						ft_execute(t_ps *stack);
void					ft_exec_swap(t_ps *stack);
void					ft_exec_push(t_ps *stack);
void					ft_exec_rotate(t_ps *stack);
void					ft_exec_reverse_rotate(t_ps *stack);
void					ft_swap_a_if(t_ps *stack);
void					ft_swap_b_if(t_ps *stack);
void					ft_swap_ab_if(t_ps *stack);
void					ft_push_a_if(t_ps *stack);
void					ft_push_b_if(t_ps *stack);
void					ft_rotate_a_if(t_ps *stack);
void					ft_rotate_b_if(t_ps *stack);
void					ft_rotate_ab_if(t_ps *stack);
void					ft_reverse_rotate_a_if(t_ps *stack);
void					ft_reverse_rotate_b_if(t_ps *stack);
void					ft_reverse_rotate_ab_if(t_ps *stack);
int						ft_set_strategy(t_ps *s);
int						ft_strategize(t_ps *s);
int						ft_find_element_before(t_ps *stack, char *cmp, char *opt);
int						ft_find_element_after(t_ps *stack, char *cmp, char *opt);
int						ft_sort_last(t_ps *stack, int i, int len);
int						ft_sort_first(t_ps *stack, int i, int len);
int						ft_sort_middle(t_ps *stack);
#endif
