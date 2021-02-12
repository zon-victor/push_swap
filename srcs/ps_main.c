/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:57:56 by zmakhube          #+#    #+#             */
/*   Updated: 2016/07/03 14:41:37 by zmakhube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps.h"

void	ft_reset_or_init_vars(t_ps *stack)
{
	stack->i = 0;
	stack->rot = 1;
	stack->sa = 0;
	stack->sb = 0;
	stack->ss = 0;
	stack->pa = 0;
	stack->pb = 0;
	stack->ra = 0;
	stack->rb = 0;
	stack->rr = 0;
	stack->rra = 0;
	stack->rrb = 0;
	stack->rrr = 0;
}

void	ps_print(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

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

int		main(int ac, char **av)
{
	t_ps	*stack;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char*) * ac);
	stack = (t_ps *)malloc(sizeof(t_ps) * PS_BUF);
	if (ac == 1 || !stack)
	{
		ps_print("Error");
		return (0);
	}
	ps_check_args(ac, 1, av);
	ps_check_dupl(av, av[1], av[2], ac, 1, 0, 1);
	if (ft_sorted(stack, av, av[1], av[2], ac - 1, 1, 0) == 0)
	{
		stack->len = ac - 1;
		stack->alen = stack->len;
		stack->a = av + 1;
		tmp[0] = "";
		stack->b = tmp;
		ft_reset_or_init_vars(stack);
		ft_set_strategy(stack);
		ft_putchar('\n');
		return (0);
	}
	return (0);
}
