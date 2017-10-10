/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:04:53 by jthillar          #+#    #+#             */
/*   Updated: 2017/09/11 14:55:16 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	side_start(int *tab, int size, int mediane)
{
	int	left;
	int	rigth;
	int	i;

	i = 0;
	left = 0;
	rigth = 0;
	while (tab[i] > mediane)
	{
		left++;
		i++;
	}
	i = size - 1;
	while (tab[i] > mediane)
	{
		rigth++;
		i--;
	}
	if (rigth < left)
		return (2);
	else
		return (1);
}

int	ft_mediane(int *tab_a, int len)
{
	int	i;
	int	j;
	int	upper;
	int	lower;

	j = 0;
	while (j < len)
	{
		upper = 0;
		lower = 0;
		i = 0;
		while (i < len)
		{
			if (tab_a[i] < tab_a[j])
				lower++;
			else if (tab_a[i] > tab_a[j])
				upper++;
			i++;
		}
		if (lower == upper || lower + 1 == upper)
			return (tab_a[j]);
		j++;
	}
	return (0);
}
