/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:43:04 by jthillar          #+#    #+#             */
/*   Updated: 2017/09/11 17:38:44 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	n_tab_a(char *av)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 1 && ft_isdigit(av[i + 1]) == 0)
			n++;
		i++;
	}
	return (n);
}

int	check_arg(char **av)
{
	int i;
	int j;
	int n;

	j = 1;
	n = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (ft_isdigit(av[j][i]) == 0 && (av[j][i] != ' '
			&& av[j][i] != '-'))
				return (0);
			i++;
		}
		if (n_tab_a(av[j]) == 0)
			return (0);
		n += n_tab_a(av[j]);
		j++;
	}
	return (n);
}

int	check_and_fill(t_check *check, int ac, char **av)
{
	if (check_arg(av) == 0 || ac < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	else
	{
		if (!(check->tab_a = (int*)malloc(sizeof(int) * check_arg(av))))
			return (0);
		check->size_a = check_arg(av);
		if (!(check->tab_b = (int*)malloc(sizeof(int) * check_arg(av))))
			return (0);
		check->size_b = 0;
		if (fill_tab(av, check->tab_a) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}

int	sort_ok(t_check check)
{
	int i;

	i = 0;
	while (i < check.size_a - 1)
	{
		if (check.tab_a[i] < check.tab_a[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_check		check;

	if (check_and_fill(&check, ac, av) == 0)
		return (0);
	if (sort_ok(check) == 1)
	{
		ft_memdel((void**)&check);
		return (0);
	}
	if (check.size_a <= 5)
	{
		algo2(&check, 0);
		return (0);
	}
	repush_atob(&check, check.size_a);
	return (0);
}
