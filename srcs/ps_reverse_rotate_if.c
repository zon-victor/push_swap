/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate_if.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 12:10:55 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 17:04:35 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

void	ft_reverse_rotate_a_if(t_ps *s)
{
	if (ft_atoi(s->a[s->alen - 2]) == ft_largest_anum(s))
	{
		s->rra = 1;
		ft_execute(s);
	}
	else
	{
		ft_strategize(s);
	}
}

void	ft_reverse_rotate_b_if(t_ps *s)
{
	s->blen = s->len - s->alen;
	if (s->blen > 1)
	{
		if (ft_atoi(s->b[s->blen - 2]) == ft_smallest_bnum(s))
			s->rrb = 1;
	}
	ft_execute(s);
}

void	ft_reverse_rotate_ab_if(t_ps *s)
{
	s->blen = s->len - s->alen;
	if (ft_atoi(s->a[s->alen - 2]) == ft_largest_anum(s) && 
			ft_atoi(s->b[s->blen - 2]) == ft_smallest_bnum(s))
	{
		s->rrr = 1;
	}
}
