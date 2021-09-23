/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:34:23 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/23 15:39:05 by crisfern         ###   ########.fr       */
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
	if (pos <= 0)
	{
		while (pos++ < 0)
			r_rotate_a(lst, n_elem);
	}
	else
	{
		while (pos-- > 0)
			rotate_a(lst, n_elem);
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
			rotate_to_pos(lst_a, find_pos_insert(lst_a, *(int *)lst_b->content, n_elem_a), n_elem_a);
			push_a(&lst_b, lst_a, &n_elem_b, &n_elem_a);
		}
		if (!is_sorted(lst_a))
		{
			min = find_min_max(lst_a, 1);
			rotate_to_pos(lst_a, find_position(lst_a, min, n_elem_a), n_elem_a);
		}
	}
}

void	sort_100n(t_list **lst_a, int n_elem_a)
{
	t_list	*lst_b;
	int		n_elem_b;
	int		min;
	
	n_elem_b = 0;
	if (!is_sorted(lst_a))
	{
		while (n_elem_a)
		{
			get_pos_mov(lst_a, &lst_b, n_elem_a, n_elem_b);
		}
		while (n_elem_b > 0)
			push_a(&lst_b, lst_a, &n_elem_b, &n_elem_a);
		if (!is_sorted(lst_a))
		{
			min = find_min_max(lst_a, 1);
			rotate_to_pos(lst_a, find_position(lst_a, min, n_elem_a), n_elem_a);
		}
	}
}

int get_pos_mov(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b)
{
	t_list	*aux;
	int		n_mov;
	int		pos;
	int		i;

	n_mov = 0;
	pos = 0;
	i = 0;
	aux = *lst_a;
	while (aux)
	{
		if ((i < n_mov) || (i > n_elem_a - n_mov))
		{
			if (get_n_mov() < n_mov)
			{	
				n_mov = get_n_mov(lst_a, lst_b, n_elem_a, n_elem_b);
				pos = i;
			}
		}
		i++;
		aux = aux->next;
	}
	if (pos > n_elem_a / 2)
		pos = (n_elem_a - pos) * (-1);
	return (pos);
}

int get_n_mov(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b)
{

}






pos_b = find_pos_insert(&lst_b, *(int *)lst_a->content, n_elem_b)