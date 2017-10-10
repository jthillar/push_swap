/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repush_btoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 11:41:24 by jthillar          #+#    #+#             */
/*   Updated: 2017/09/11 14:54:59 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	repush_btoa_3(t_check *check, int len, int rb, int side_s)
{
	if (len / 2 + len % 2 != check->size_b)
	{
		while (rb > 0)
		{
			side_s == 1 ? ft_ls_p("rrb", check) : ft_ls_p("rb", check);
			rb--;
		}
	}
}

void	repush_btoa_2(t_check *check, int len, int mediane, int i)
{
	int	rb;
	int	half_len;
	int	side_s;

	rb = 0;
	half_len = 0;
	while (++i < len && half_len < (len / 2))
	{
		if (check->tab_b[0] > mediane)
		{
			ft_ls_p("pa", check);
			half_len++;
		}
		else
		{
			side_s = side_start(check->tab_b, check->size_b, mediane);
			side_s == 1 ? ft_ls_p("rb", check) : ft_ls_p("rrb", check);
			rb++;
			i = -2;
		}
	}
	repush_btoa_3(check, len, rb, side_s);
}

void	repush_btoa(t_check *check, int len)
{
	int	i;
	int	mediane;

	i = -1;
	if (len <= 2)
	{
		if (len == 2 && check->tab_b[0] < check->tab_b[1])
			ft_ls_p("sb", check);
		while (++i < len)
			ft_ls_p("pa", check);
	}
	else
	{
		mediane = ft_mediane(check->tab_b, len);
		repush_btoa_2(check, len, mediane, i);
		repush_atob(check, len / 2);
		repush_btoa(check, len / 2 + len % 2);
	}
}
