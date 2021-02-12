/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:58:56 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/02 21:38:57 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

int		ft_stacklen(char **stack)
{
	int len;

	len = 0;
	while (*stack)
	{
		len++;
		stack++;
	}
	return (len);
}

int		ft_swap_a(t_ps *stack)
{
	if (ft_stacklen(stack->a) < 2)
		return (0);
	stack->tmp_a = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = stack->tmp_a;
	stack->tmp_a = NULL;
	ps_print("sa");
	return (0);
}

int		ft_swap_b(t_ps *stack)
{
	if (!stack->b || ft_stacklen(stack->b) < 2)
		return (0);
	stack->tmp_b = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = stack->tmp_b;
	stack->tmp_b = NULL;
	ps_print("sb");
	return (0);
}

int		ft_swap_ab(t_ps *stack)
{
	ft_swap_a(stack);
	ft_swap_b(stack);
	return (0);
}
