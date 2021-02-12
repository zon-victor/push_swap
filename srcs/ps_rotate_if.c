/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 04:25:29 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 17:00:54 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

void	ft_rotate_a_if(t_ps *s)
{
	int i;
	int len;

	i = 0;
	len = ft_stacklen(s->a) - 1;
	while (i <= len)
	{
		ft_sort_last(s, i, len);
		i++;
	}
	ft_execute(s);
}

void	ft_rotate_b_if(t_ps *s)
{
	if (ft_atoi(s->b[1]) == ft_smallest_bnum(s))
		s->rb = 1;
	ft_execute(s);
}

void	ft_rotate_ab_if(t_ps *s)
{
	if (ft_atoi(s->a[0]) == ft_largest_anum(s) && ft_atoi(s->b[1]) ==
			ft_largest_bnum(s))
	{
		s->rr = 1;
	}
	ft_execute(s);
}
