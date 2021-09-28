/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:20:02 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/28 15:46:15 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_pos_a(t_list **lst, int pos)
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

void	rotate_to_pos_b(t_list **lst, int pos)
{
	if (pos <= 0)
	{
		while (pos++ < 0)
			r_rotate_b(lst);
	}
	else
	{
		while (pos-- > 0)
			rotate_b(lst);
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

void	rotate_2list(t_list **lst_a, t_list **lst_b, int pos_a, int pos_b)
{
	if (((pos_a >= 0) && (pos_b < 0)) || ((pos_b >= 0) && (pos_a < 0)))
	{
		rotate_to_pos_a(lst_a, pos_a);
		rotate_to_pos_b(lst_b, pos_b);
	}
	else
	{
		if (((pos_a > pos_b) && (pos_a >= 0) && (pos_b >= 0))
			|| ((pos_b > pos_a) && (pos_b < 0) && (pos_a < 0)))
		{
			rotate_to_pos_ab(lst_a, lst_b, pos_b);
			rotate_to_pos_a(lst_a, pos_a - pos_b);
		}
		else if (((pos_b > pos_a) && (pos_b >= 0) && (pos_a >= 0))
			|| ((pos_a > pos_b) && (pos_b < 0) && (pos_a < 0)))
		{
			rotate_to_pos_ab(lst_a, lst_b, pos_a);
			rotate_to_pos_b(lst_b, pos_b - pos_a);
		}
	}
}

int	get_pos_mov(t_list *lst_a, t_list *lst_b, int n_elem_a, int n_elem_b)
{
	int		pos;
	int		n_mov_min;
	int		pos_min;
	int		a;
	
	pos_min = 0;
	pos = -1;
	n_mov_min = get_n_mov(lst_b, n_elem_b, 0, find_number(lst_a, 0, n_elem_a));
	while (lst_a)
	{
		if (++pos < n_mov_min)
		{
			if (pos > (n_elem_a / 2))
				pos = (n_elem_a - pos) * (-1);
			a = find_number(lst_a, pos, n_elem_a);
			if (get_n_mov(lst_b, n_elem_b, pos, a) < n_mov_min)
			{
				n_mov_min = get_n_mov(lst_b, n_elem_b, pos, a);
				pos_min = pos;
			}
		}
		lst_a = lst_a->next;
	}
	return (pos_min);
}

int	get_n_mov(t_list *lst_b, int n_elem_b, int pos_a, int a)
{
	int	pos_b;

	pos_b = find_pos_insert_b(lst_b, a, n_elem_b);
	if ((pos_a >= 0) && (pos_b < 0))
		return (pos_a + (-1 * pos_b));
	else if ((pos_b >= 0) && (pos_a < 0))
		return ((-1 * pos_a) + pos_b);
	else
	{
		if (((pos_a > pos_b) && (pos_a >= 0) && (pos_b >= 0))
			|| ((pos_b > pos_a) && (pos_b < 0) && (pos_a < 0)))
			return (pos_a);
		else if (((pos_b > pos_a) && (pos_b >= 0) && (pos_a >= 0))
			|| ((pos_a > pos_b) && (pos_b < 0) && (pos_a < 0)))
			return (pos_b);
	}
	return (0);
}
