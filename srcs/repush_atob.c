/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repush_atob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:53:20 by jthillar          #+#    #+#             */
/*   Updated: 2017/09/11 15:06:34 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	repush_atob_3(t_check *check, int len, int turn, int side_s)
{
	if (len / 2 != check->size_a)
	{
		while (turn > 0)
		{
			side_s == 1 ? ft_ls_p("rra", check) : ft_ls_p("ra", check);
			turn--;
		}
	}
}

void	repush_atob_2(t_check *check, int len, int mediane, int i)
{
	int half_len;
	int turn;
	int side_s;

	half_len = 0;
	turn = 0;
	while (++i < len && half_len < (len / 2 + len % 2))
	{
		if (check->tab_a[0] <= mediane)
		{
			ft_ls_p("pb", check);
			half_len++;
		}
		else
		{
			side_s = side_start(check->tab_a, check->size_a, mediane);
			side_s == 1 ? ft_ls_p("ra", check) : ft_ls_p("rra", check);
			turn++;
			i = -2;
		}
	}
	repush_atob_3(check, len, turn, side_s);
}

void	repush_atob(t_check *check, int len)
{
	int i;
	int mediane;

	if (sort_ok(*check) == 1)
		return ;
	if (len <= 2)
	{
		if (len == 2 && check->tab_a[0] > check->tab_a[1])
			ft_ls_p("sa", check);
	}
	else
	{
		mediane = ft_mediane(check->tab_a, len);
		i = -1;
		repush_atob_2(check, len, mediane, i);
		repush_atob(check, len / 2);
		repush_btoa(check, len / 2 + len % 2);
	}
}
