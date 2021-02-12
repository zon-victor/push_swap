/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 03:29:52 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 16:55:47 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

void	ft_swap_a_if(t_ps *s)
{
	if (ft_atoi(s->a[1]) == ft_largest_anum(s) ||  (ft_atoi(s->a[1]) ==
				ft_smallest_anum(s)))
	{
		s->sa = 1;
		ft_execute(s);
	}
	else if (ft_atoi(s->a[0]) > ft_atoi(s->a[1]))
	{
		ft_strategize(s);
	}
}

void	ft_swap_b_if(t_ps *s)
{
	if (ft_atoi(s->b[1]) < ft_atoi(s->b[0]))
	{
		s->sb = 1;
	}
	ft_execute(s);
}

void	ft_swap_ab_if(t_ps *s)
{
	s->ss = 1;
	ft_execute(s);
}
