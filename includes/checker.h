/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthillar <jthillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 13:33:45 by jthillar          #+#    #+#             */
/*   Updated: 2017/09/11 18:22:56 by jthillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include "../libft/includes/libft.h"

typedef struct	s_check
{
	int	*tab_a;
	int	*tab_b;
	int size_a;
	int size_b;
}				t_check;

int				ft_listsort(char *sort, t_check *check);
void			ft_ls_p(char *sort, t_check *check);
int				sort_ok(t_check check);
int				fill_tab(char **av, int *tab);
void			ft_sa(int **tab_a, int size_a);
void			ft_ss(t_check *check);
void			ft_pa(t_check *check);
void			ft_pb(t_check *check);
void			ft_ra(int **tab_a, int size_a);
void			ft_rr(t_check *check);
void			ft_rra(int **tab_a, int size_a);
void			ft_rrr(t_check *check);
void			repush_atob(t_check *check, int len);
void			repush_btoa(t_check *check, int len);
int				sort_ok(t_check check);
int				side_start(int *tab, int size, int mediane);
int				ft_mediane(int *tab_a, int len);
void			algo2(t_check *check, int pb);
#endif
