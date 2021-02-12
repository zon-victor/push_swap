/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 02:57:32 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 16:57:13 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

void	ft_push_b_if(t_ps *s)
{
	if (ft_atoi(s->a[0]) == ft_smallest_bnum(s))
	{
		ft_execute(s);
	}
	else
	{
		ft_strategize(s);
	}
}

void	ft_push_a_if(t_ps *s)
{
	int i;

	i = 0;
	if (ft_atoi(s->a[0]) == ft_smallest_anum(s))
	{
		while (ft_atoi(s->b[i]) == ft_largest_bnum(s))
		{
			i++;
		}
		s->pb = i + 1;
	}
	ft_execute(s);
}
