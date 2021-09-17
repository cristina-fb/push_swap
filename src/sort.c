/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:34:23 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/17 16:40:35 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **lst)
{
	t_list	*aux;

	aux = *lst;
	if (aux)
	{
		while (aux->next)
		{
			if ((*(int *)aux->content) > (*(int *)aux->next->content))
				return (0);
			aux = aux->next;
		}
	}
	return (1);
}

void	rotate_to_pos(t_list **lst, int pos, int n_elem)
{
	if (pos <= n_elem / 2)
	{
		while (pos-- > 0)
			rotate_a(lst, n_elem);
	}	
	else
	{
		pos = n_elem - pos;
		while (pos-- > 0)
			r_rotate_a(lst, n_elem);
	}
}

void	sort_3n(t_list **lst, int n_elem)
{
	if (!is_sorted(lst))
	{
		if ((*(int *)lst[0]->content) > (*(int *)lst[0]->next->content))
			rotate_a(lst, n_elem);
		else
			r_rotate_a(lst, n_elem);
		if (!is_sorted(lst))
		{
			swap_a(lst, n_elem);
			if (!is_sorted(lst))
				rotate_a(lst, n_elem);
		}
	}
}

void	sort_5n(t_list **lst_a, int n_elem_a)
{
	t_list	*lst_b;
	int		n_elem_b;
	int		min;

	n_elem_b = 0;
	if (!is_sorted(lst_a))
	{
		while (n_elem_a > 3)
			push_b(lst_a, &lst_b, &n_elem_a, &n_elem_b);
		sort_3n(lst_a, n_elem_a);
		while (n_elem_b > 0)
		{
			rotate_to_pos(lst_a, find_pos_insert(lst_a, *(int *)lst_b->content), n_elem_a);
			push_a(&lst_b, lst_a, &n_elem_b, &n_elem_a);
		}
		if (!is_sorted(lst_a))
		{
			min = find_min_max(lst_a, 1);
			rotate_to_pos(lst_a, find_position(lst_a, min), n_elem_a);
		}
	}
}
