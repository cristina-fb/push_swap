/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:33:37 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/30 12:05:31 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_list(char *str, t_list **lst)
{
	int		*value;
	t_list	*aux;

	value = ft_calloc(1, sizeof(int));
	if (value)
	{
		*value = ft_atoi((const char *)str);
		aux = ft_lstnew(value);
		if (!lst[0])
			lst[0] = aux;
		else
			ft_lstadd_back(lst, aux);
	}
}

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
		if (pos_a == pos_b)
			rotate_to_pos_ab(lst_a, lst_b, pos_a);
		else if (((pos_a > pos_b) && (pos_a >= 0) && (pos_b >= 0))
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
