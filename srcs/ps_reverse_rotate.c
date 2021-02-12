/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:03:06 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 17:12:20 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

int		ft_reverse_rotate_a(t_ps *s)
{
	int i;
	int len;

	len = ft_stacklen(s->a);
	if (len < 2)
		return (0);
	i = 0;
	s->tmp_a = s->a[len - 1];
	while (i < len - 2)
	{
		s->a[i + 1] = s->a[i];
		i++;
	}
	s->tmp_a = NULL;
	ps_print("rra");
	return (0);
}

int		ft_reverse_rotate_b(t_ps *stack)
{
	int	i;
	int len;

	len = ft_stacklen(stack->b);
	if (len < 2)
		return (0);
	i = len;
	stack->tmp_b = stack->b[len - 1];
	while (i-- >= 0)
	{
		if (i == 0)
			stack->b[i] = stack->tmp_b;
		else
			stack->b[i] = stack->b[i - 1];
	}
	stack->tmp_b = NULL;
	ps_print("rrb");
	return (0);
}

int		ft_reverse_rotate_ab(t_ps *stack)
{
	ft_reverse_rotate_a(stack);
	ft_reverse_rotate_b(stack);
	return (0);
}
