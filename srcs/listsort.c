/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 11:36:19 by jthillar          #+#    #+#             */
/*   Updated: 2017/09/12 13:07:49 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_listsort2(char *sort, t_check *check)
{
	if (ft_strequ(sort, "ss"))
		ft_ss(check);
	if (ft_strequ(sort, "pa"))
		ft_pa(check);
	if (ft_strequ(sort, "pb"))
		ft_pb(check);
}

int		ft_listsort(char *sort, t_check *check)
{
	if (ft_strequ(sort, "sa"))
		ft_sa(&check->tab_a, check->size_a);
	else if (ft_strequ(sort, "sb"))
		ft_sa(&check->tab_b, check->size_b);
	else if (ft_strequ(sort, "ss") || ft_strequ(sort, "pa")
	|| ft_strequ(sort, "pb"))
		ft_listsort2(sort, check);
	else if (ft_strequ(sort, "ra"))
		ft_ra(&check->tab_a, check->size_a);
	else if (ft_strequ(sort, "rb"))
		ft_ra(&check->tab_b, check->size_b);
	else if (ft_strequ(sort, "rr"))
		ft_rr(check);
	else if (ft_strequ(sort, "rra"))
		ft_rra(&check->tab_a, check->size_a);
	else if (ft_strequ(sort, "rrb"))
		ft_rra(&check->tab_b, check->size_b);
	else if (ft_strequ(sort, "rrr"))
		ft_rrr(check);
	else
	{
		ft_putendl("Error");
		return (0);
	}
	return (1);
}

void	ft_ls_p(char *sort, t_check *check)
{
	if (ft_strequ(sort, "sa"))
		ft_sa(&check->tab_a, check->size_a);
	if (ft_strequ(sort, "sb"))
		ft_sa(&check->tab_b, check->size_b);
	if (ft_strequ(sort, "ss"))
		ft_ss(check);
	if (ft_strequ(sort, "pa"))
		ft_pa(check);
	if (ft_strequ(sort, "pb"))
		ft_pb(check);
	if (ft_strequ(sort, "ra"))
		ft_ra(&check->tab_a, check->size_a);
	if (ft_strequ(sort, "rb"))
		ft_ra(&check->tab_b, check->size_b);
	if (ft_strequ(sort, "rr"))
		ft_rr(check);
	if (ft_strequ(sort, "rra"))
		ft_rra(&check->tab_a, check->size_a);
	if (ft_strequ(sort, "rrb"))
		ft_rra(&check->tab_b, check->size_b);
	if (ft_strequ(sort, "rrr"))
		ft_rrr(check);
	ft_putendl(sort);
}
