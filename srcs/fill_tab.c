/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 16:45:09 by jthillar          #+#    #+#             */
/*   Updated: 2017/09/12 12:14:58 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_equal(int n, int *tab, int j)
{
	int i;

	i = 0;
	while (i < j)
	{
		if (n == tab[i])
			return (0);
		i++;
	}
	tab[j] = n;
	return (1);
}

int	fill_tab2(char *av, int i, int j, int *tab)
{
	int n;
	int neg;

	n = 0;
	neg = 1;
	if (av[i] == '-')
	{
		i++;
		neg = -1;
	}
	while (ft_isdigit(av[i]) == 1 && av[i])
	{
		n = n * 10 + av[i] - '0';
		if ((n > -2147483648 && n < 0 && neg == -1) ||
		(n >= -2147483648 && n < 0 && neg == 1))
			return (0);
		i++;
	}
	n = n * neg;
	if (check_equal(n, tab, j) == 0)
		return (0);
	else
		j++;
	return (i);
}

int	fill_tab(char **av, int *tab)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 1;
	while (av[k])
	{
		i = 0;
		while (av[k][i])
		{
			if ((ft_isdigit(av[k][i]) == 1 || av[k][i] == '-') && av[k][i])
			{
				if (fill_tab2(av[k], i, j, tab) == 0)
					return (0);
				i = fill_tab2(av[k], i, j, tab);
				j++;
			}
			else
				i++;
		}
		k++;
	}
	return (1);
}
