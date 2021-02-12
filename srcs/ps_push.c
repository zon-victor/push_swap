/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:00:10 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 15:45:30 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

int		ft_push_a(t_ps *s)
{
	int i;
	int b;

	b = 0;
	i = s->len;
	while (i >= 0)
	{
		if (i > s->pa)
			s->a[i] = s->a[i - 1];
		else
		{
			s->a[i] = s->b[b];
			ps_print("pa");
			b++;
		}
		i--;
	}
	return (0);
}

int		ft_push_b(t_ps *s)
{
	int		i;
	int		j;
	char	**temp;

	temp = (char **)malloc(sizeof(char*) * (s->alen - s->pb));
	i = s->pb - 1;
	j = 0;
	if (ft_strcmp(s->b[0], "") == 0)
	{
		while (i >= 0)
		{
			s->b[i] = s->a[j];
			ps_print("pb");
			j++;
			i--;
		}
		temp = s->a + s->pb;
		s->a = NULL;
		s->a = temp;
		i = 0;
		while (i < (s->alen - s->pb))
		{
			ps_print(s->a[i]);
			i++;
		}
		temp = NULL;
	}
	else
		ft_push_b_again(s, temp);
	//s->a = s->a + 1;
	return (0);
}

int		ft_push_b_again(t_ps *s, char **temp)
{
	int blen;
	int i;
	int	j;

	blen = ft_stacklen(s->b) + s->pb;
	i = blen - 1;
	j = 0;
	//ft_putnbr(blen);
	return (0);
	while (i >= 0)
	{
		if (i > s->pb - 1)
			s->b[i] = s->b[i - 1];
		else
		{
			s->b[i] = s->a[j];
			ps_print("pb");
			j++;
		}
		--i;
	}
	temp = s->a + s->pb;
	s->a = NULL;
	s->a = temp;
	temp = NULL;
	return (0);
}
