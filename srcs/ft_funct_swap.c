/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funct_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:32:08 by jthillar          #+#    #+#             */
/*   Updated: 2017/09/11 16:20:08 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(int **tab_a, int size_a)
{
	int *tmp;

	tmp = *tab_a;
	if (size_a == 0)
		return ;
	ft_swap(&tmp[0], &tmp[1]);
	*tab_a = tmp;
}

void	ft_ss(t_check *check)
{
	int *tmp_a;
	int *tmp_b;

	tmp_a = check->tab_a;
	tmp_b = check->tab_b;
	if (check->size_a != 0)
	{
		ft_swap(&tmp_a[0], &tmp_a[1]);
		check->tab_a = tmp_a;
	}
	if (check->size_b != 0)
	{
		ft_swap(&tmp_b[0], &tmp_b[1]);
		check->tab_b = tmp_a;
	}
}

void	ft_pa(t_check *check)
{
	int *tab_a;
	int *tab_b;
	int i;
	int size_a;

	tab_a = check->tab_a;
	tab_b = check->tab_b;
	if (check->size_b == 0)
		return ;
	size_a = check->size_a + 1;
	while (--size_a > 0)
		tab_a[size_a] = tab_a[size_a - 1];
	tab_a[0] = tab_b[0];
	i = 0;
	while (i < check->size_b)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	check->tab_b = tab_b;
	check->tab_a = tab_a;
	check->size_b = check->size_b - 1;
	check->size_a = check->size_a + 1;
}

void	ft_pb(t_check *check)
{
	int *tab_a;
	int *tab_b;
	int i;
	int	size_b;

	tab_a = check->tab_a;
	tab_b = check->tab_b;
	if (check->size_a == 0)
		return ;
	size_b = check->size_b + 1;
	while (--size_b > 0)
		tab_b[size_b] = tab_b[size_b - 1];
	tab_b[0] = tab_a[0];
	i = 0;
	while (i < check->size_a)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	check->size_b = check->size_b + 1;
	check->size_a = check->size_a - 1;
	check->tab_b = tab_b;
	check->tab_a = tab_a;
}
