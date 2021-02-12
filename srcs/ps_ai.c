/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ai.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 16:53:18 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 17:14:55 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

int		ps_check_dupl(char **av, const char *s1, const char *s2, int ac,
							int i, int rot, int next)
{
	if (i + rot <= ac - 1 && ac != 2)
	{
		if (ft_atoi(s1) == ft_atoi(s2))
		{
			ps_print("Error");
			exit (0);
		}
		else
		{
			rot++;
			return (ps_check_dupl(av, av[i], av[i + rot], ac, i, rot, next));
		}
	}
	next++;
	if (next <= ac - 1 && next + 1 <= ac - 1)
		return (ps_check_dupl(av, av[next], av[next + 1], ac, next, 0, next));
	return (0);
}

int		ps_check_args(int ac, int i, char **av)
{
	unsigned int	j;
	unsigned int	k;

	j = 0;
	k = ft_strlen(av[i]);
	while (j < k)
	{
		if ((av[i][j] == '-' || av[i][j] == '+') && j == 0)
		   j++;
		if (!ft_isdigit(av[i][j]))
		{
			ps_print("Error");
			exit (1);
		}
		j++;
	}
	i++;
	if (i <= ac - 1)
		return (ps_check_args(ac, i, av));
	return (0);
}

