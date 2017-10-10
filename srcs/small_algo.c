/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 13:40:56 by jthillar          #+#    #+#             */
/*   Updated: 2017/09/12 13:45:40 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	small_algo1(t_check *check)
{
	if (check->tab_a[0] > check->tab_a[1])
		ft_ls_p("sa", check);
	if (sort_ok(*check) == 1)
		return ;
	ft_ls_p("rra", check);
	small_algo1(check);
}

void	algo2(t_check *check, int pb)
{
	if (check->size_a <= 3)
	{
		small_algo1(check);
		return ;
	}
	while (check->size_a > 3)
	{
		if (check->tab_a[0] < ft_mediane(check->tab_a, check->size_a))
		{
			ft_ls_p("pb", check);
			pb++;
		}
		else
			ft_ls_p("ra", check);
	}
	small_algo1(check);
	while (pb > 0)
	{
		if (check->size_b == 2 && check->tab_b[0] < check->tab_b[1])
			ft_ls_p("sb", check);
		ft_ls_p("pa", check);
		pb--;
	}
}
