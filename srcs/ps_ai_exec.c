/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ai_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 01:41:30 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 11:06:29 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

void	ft_exec_swap(t_ps *s)
{
	if (s->sa == 1)
		ft_swap_a(s);
	else if (s->sb == 1)
		ft_swap_b(s);
	else if (s->ss == 1)
		ft_swap_ab(s);
	s->sa= 0;
}

void	ft_exec_push(t_ps *s)
{
	if (s->pa > 0)
		ft_push_a(s);
	else if (s->pb > 0)
		ft_push_b(s);
}

void	ft_exec_rotate(t_ps *s)
{
	if (s->ra > 0)
		ft_rotate_a(s);
	else if (s->rb > 0)
		ft_rotate_b(s);
	else if (s->rr > 0)
		ft_rotate_ab(s);
}

void	ft_exec_reverse_rotate(t_ps *s)
{
	if (s->rra > 0)
		ft_reverse_rotate_a(s);
	else if (s->rrb > 0)
		ft_reverse_rotate_b(s);
	else if (s->rrr > 0)
		ft_reverse_rotate_ab(s);
}
