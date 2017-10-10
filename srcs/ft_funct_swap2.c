/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funct_swap2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 13:35:13 by jthillar          #+#    #+#             */
/*   Updated: 2017/09/11 16:18:19 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rra(int **tab_a, int size_a)
{
	int tmp;
	int n;
	int *tmp_a;

	tmp_a = *tab_a;
	if (size_a == 0)
		return ;
	n = size_a - 1;
	tmp = tmp_a[n];
	while (n > 0)
	{
		tmp_a[n] = tmp_a[n - 1];
		n--;
	}
	tmp_a[0] = tmp;
	*tab_a = tmp_a;
}

void	ft_rrr(t_check *check)
{
	int tmp;
	int n;
	int *tmp_a;

	tmp_a = check->tab_a;
	if (check->size_a != 0)
	{
		n = check->size_a - 1;
		tmp = tmp_a[n];
		while (n > 0)
		{
			tmp_a[n] = tmp_a[n - 1];
			n--;
		}
		tmp_a[0] = tmp;
	}
	check->tab_a = tmp_a;
	ft_rra(&check->tab_b, check->size_b);
}

void	ft_ra(int **tab_a, int size_a)
{
	int tmp;
	int	i;
	int *tmp_a;

	tmp_a = *tab_a;
	if (size_a == 0)
		return ;
	tmp = tmp_a[0];
	i = 0;
	while (i < size_a - 1)
	{
		tmp_a[i] = tmp_a[i + 1];
		i++;
	}
	tmp_a[size_a - 1] = tmp;
	*tab_a = tmp_a;
}

void	ft_rr(t_check *check)
{
	int tmp;
	int	i;
	int *tmp_a;

	tmp_a = check->tab_a;
	i = 0;
	if (check->size_a != 0)
	{
		tmp = tmp_a[0];
		while (i < check->size_a - 1)
		{
			tmp_a[i] = tmp_a[i + 1];
			i++;
		}
		tmp_a[check->size_a - 1] = tmp;
		check->tab_a = tmp_a;
	}
	ft_ra(&check->tab_b, check->size_b);
}
