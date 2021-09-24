/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:20:02 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/24 15:44:11 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_pos(t_list **lst, int pos)
{
	if (pos <= 0)
	{
		while (pos++ < 0)
			r_rotate_a(lst);
	}
	else
	{
		while (pos-- > 0)
			rotate_a(lst);
	}
}

void	rotate_to_pos_ab(t_list **lst_a, t_list **lst_b, int pos)
{
	if (pos <= 0)
	{
		while (pos++ < 0)
			r_rotate_ab(lst_a, lst_b);
	}
	else
	{
		while (pos-- > 0)
			rotate_ab(lst_a, lst_b);
	}
}

void	rotate_2list(t_list **lst_a, t_list **lst_b, int n_elem_b, int pos_a)
{
	int	pos_b;

	pos_b = find_pos_insert(lst_b, find_number(lst_a, pos_a), n_elem_b);
	if (((pos_a >= 0) && (pos_b < 0)) || ((pos_b >= 0) && (pos_a < 0)))
	{
		rotate_to_pos(lst_a, pos_a);
		rotate_to_pos(lst_b, pos_b);
	}
	else
	{
		if (((pos_a > pos_b) && (pos_a >= 0) && (pos_b >= 0))
			|| ((pos_b > pos_a) && (pos_b < 0) && (pos_a < 0)))
		{
			rotate_to_pos_ab(lst_a, lst_b, pos_b);
			rotate_to_pos(lst_a, pos_a - pos_b);
		}
		else if (((pos_b > pos_a) && (pos_b >= 0) && (pos_a >= 0))
			|| ((pos_a > pos_b) && (pos_b < 0) && (pos_a < 0)))
		{
			rotate_to_pos_ab(lst_a, lst_b, pos_a);
			rotate_to_pos(lst_b, pos_b - pos_a);
		}
	}
}