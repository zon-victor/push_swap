/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ai_extended_again.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 22:43:01 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 16:20:27 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

int		ft_find_element_before(t_ps *s, char *stack, char *cmp)
{
	int len;

	s->tmp = ft_strcmp(stack, "a") == 0 ? s->a : s->b;
	len = ft_strcmp(stack, "a") == 0 ? s->alen : s->blen;
	if (s->i + s->rot < len)
	{
		if (ft_atoi(s->tmp[s->i]) < ft_atoi(cmp) && ft_atoi(s->tmp[s->i]) >
				ft_atoi(s->tmp[s->i + s->rot]))
		{
			s->elb = ft_atoi(s->tmp[s->i]);
			s->rot = s->rot + 1;
			return (ft_find_element_before(s, stack, cmp));
		}
		else
		{
			s->i = s->i + s->rot;
			s->rot = 1;
			return (ft_find_element_before(s, stack, cmp));
		}
	}
	s->elp = s->i;
	s->i = 0;
	s->rot = 0;
	return (s->elb);
}

int		ft_find_element_after(t_ps *s, char *stack, char *cmp)
{
	int len;

	s->tmp = ft_strcmp(stack, "a") == 0 ? s->a : s->b;
	len = ft_strcmp(stack, "a") == 0 ? s->alen : s->blen;
	if (s->i + s->rot < len)
	{
		if (ft_atoi(s->tmp[s->i]) > ft_atoi(cmp) && ft_atoi(s->tmp[s->i]) <
				ft_atoi(s->tmp[s->i + s->rot]))
		{
			s->ela = ft_atoi(s->tmp[s->i]);
			s->rot = s->rot + 1;
			return (ft_find_element_after(s, stack, cmp));
		}
		else
		{
			s->i = s->rot + s->i;
			s->rot = 1;
			return (ft_find_element_after(s, stack, cmp));
		}
	}
	s->elp = s->i;
	s->i = 0;
	s->rot = 0;
	return (s->ela);
}

int		ft_sort_last(t_ps *s, int i, int len)
{
	if (ft_atoi(s->a[len - i]) == ft_largest_anum(s) && i == len)
		s->ra = i + 1;
	if (ft_atoi(s->a[len - i]) == ft_largest_anum(s) && i <= len/2)
		s->rra = i + 1;
	if (ft_atoi(s->a[len - i]) == ft_largest_anum(s) && i >= len/2 && i > 1)
		s->ra = i + 1;
	if (ft_atoi(s->a[len - i]) == ft_largest_anum(s) && len - i == 1)
	{
		s->sa = 1;
		s->ra = 1;
	}
	return (0);
}

int		ft_sort_first(t_ps *s, int i, int len)
{
	if (ft_atoi(s->a[len - i]) == ft_smallest_anum(s) && len - i == 1)
		s->sa = 1;
	if (ft_atoi(s->a[len - i]) == ft_smallest_anum(s) && len - i > 1 && i >= len/2)
	{
		s->ra = i + 1;
	}
	if (ft_atoi(s->a[len - i]) == ft_smallest_anum(s) && i <= len/2)
	{
		s->rra = i + 1;
	}
	return (0);
}

int		ft_sort_middle(t_ps *s)
{
	s->c = 0;
   	if (ft_sorted(s, s->a, s->a[0], s->a[1], s->alen, 0, 0) == 1)
	{
		ps_print("OK");
	}
	s->pb = s->c;
	return (0);
}
