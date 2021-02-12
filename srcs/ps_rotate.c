/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:01:12 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 13:54:17 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

int		ft_rotate_a(t_ps *stack)
{
	int len;
	int i;

	i = 0;
	len = ft_stacklen(stack->a);
	if (len < 2)
		return (0);
	stack->tmp_a = stack->a[0];
	while (i <= len - 2)
	{
		stack->a[i] = stack->a[i + 1];
		ps_print(stack->a[i]);
		i++;
	}
	stack->a[len] = stack->tmp_a;
	//stack->tmp_a = NULL;
	ps_print(stack->a[len]);
	return (0);
}

int		ft_rotate_a_mod(t_ps *stack)
{
	int len;
	int j;
	int i;

	i = 0;
	len = ft_stacklen(stack->a1);
	if (len < 2)
		return (0);
	j = len - 1;
	stack->tmp_a = stack->a1[0];
	while (j < len)
	{
		if (i == j)
			stack->a1[i] = stack->tmp_a;
		else
			stack->a1[i] = stack->a1[i + 1];
		i++;
		ps_print(stack->a1[i]);
	}
	stack->tmp_a = NULL;
	ps_print("ra");
	return (0);
}

int		ft_rotate_b(t_ps *stack)
{
	int i;
	int j;
	int len;

	i = 0;
	len = ft_stacklen(stack->b);
	if (len < 2)
		return (0);
	j = len -1;
	stack->tmp_b = stack->b[0];
	while (i < len)
	{
		if (i == j)
			stack->b[i] = stack->tmp_b;
		else
			stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->tmp_b = NULL;
	ps_print("rb");
	return (0);
}

int		ft_rotate_ab(t_ps *stack)
{
	ft_rotate_a(stack);
	ft_rotate_b(stack);
	return (0);
}
