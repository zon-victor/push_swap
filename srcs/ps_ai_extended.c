/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ai_extended.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 14:40:47 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 16:29:59 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

int		ft_largest_anum(t_ps *s)
{
	char **a;

	a = s->a1 ? s->a1 : s->a;
	s->len = s->a1 ? ft_stacklen(s->a1) : ft_stacklen(s->a);
	if (s->len == 1)
		return (ft_atoi(a[0]));
	if (s->i + s->rot < s->len)
	{
		if (ft_atoi(a[s->i]) > ft_atoi(a[s->i + s->rot]))
		{
			s->lnum = ft_atoi(a[s->i]);
			s->rot = s->rot + 1;
			return (ft_largest_anum(s));
		} 
		else
		{
			s->lnum = ft_atoi(a[s->i + s->rot]);
			s->i = s->i + s->rot;
			s->rot = 1;
			return (ft_largest_anum(s));
		}
	}
	ft_reset_or_init_vars(s);
	return (s->lnum);
}

int		ft_largest_bnum(t_ps *s)
{
	if (s->len == 1)
		return (ft_atoi(s->b[0]));
	if (s->i + s->rot < s->len)
	{
		if (ft_atoi(s->b[s->i]) > ft_atoi(s->a[s->i + s->rot]))
		{
			s->lnumb = ft_atoi(s->b[s->i]);
			s->rot = s->rot + 1;
			return (ft_largest_bnum(s));
		}
		else
		{
			s->lnumb = ft_atoi(s->b[s->i + s->rot]);
			s->i = s->i + s->rot;
			s->rot = 1;
			return (ft_largest_bnum(s));
		}
	}
	ft_reset_or_init_vars(s);
	return (s->lnumb);
}

int		ft_smallest_anum(t_ps *s)
{
	s->len = ft_stacklen(s->a) - 1;
	if (s->len == 1)
		return (ft_atoi(s->a[0]));
	if (s->i + s->rot < s->len)
	{
		if (ft_atoi(s->a[s->i]) < ft_atoi(s->a[s->i + s->rot]))
		{
			s->snum = ft_atoi(s->a[s->i]);
			s->rot = s->rot + 1;
			return (ft_smallest_anum(s));
		}
		else
		{
			s->snum = ft_atoi(s->a[s->i + s->rot]);
			s->i =  s->i + s->rot;
			s->rot = 1;
			return (ft_smallest_anum(s));
		}
	}
	s->spos = s->i + s->rot;
	ft_reset_or_init_vars(s);
	return (s->snum);
}

int		ft_smallest_bnum(t_ps *s)
{
	if (s->len == 1)
		return (ft_atoi(s->b[0]));
	if (s->i + s->rot < s->len)
	{
		if (ft_atoi(s->a[s->i]) < ft_atoi(s->a[s->i + s->rot]))
		{
			s->pb = s->pb + 1;
			s->snumb = ft_atoi(s->a[s->i]);
			s->rot = s->rot + 1;
			return (ft_smallest_bnum(s));
		}
	}
	ft_reset_or_init_vars(s);
	return (s->snumb);
}
