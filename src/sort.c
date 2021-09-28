/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:34:23 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/28 15:53:13 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			if ((*(int *)lst->content) > (*(int *)lst->next->content))
				return (0);
			lst = lst->next;
		}
	}
	return (1);
}

void	sort_3n(t_list **lst)
{
	if (!is_sorted(*lst))
	{
		if ((*(int *)lst[0]->content) > (*(int *)lst[0]->next->content))
			rotate_a(lst);
		else
			r_rotate_a(lst);
		if (!is_sorted(*lst))
		{
			swap_a(lst);
			if (!is_sorted(*lst))
				rotate_a(lst);
		}
	}
}

void	sort_5n(t_list **lst_a, int n_elem_a)
{
	t_list	*lst_b;
	int		n_elem_b;
	int		min;
	int		aux;

	n_elem_b = 0;
	if (!is_sorted(*lst_a))
	{
		while (n_elem_a > 3)
			push_b(lst_a, &lst_b, &n_elem_a, &n_elem_b);
		sort_3n(lst_a);
		while (n_elem_b > 0)
		{
			aux = find_pos_insert_a(*lst_a, *(int *)lst_b->content, n_elem_a);
			rotate_to_pos_a(lst_a, aux);
			push_a(&lst_b, lst_a, &n_elem_b, &n_elem_a);
		}
		if (!is_sorted(*lst_a))
		{
			min = find_min_max(*lst_a, 1);
			rotate_to_pos_a(lst_a, find_position(*lst_a, min, n_elem_a));
		}
	}
}

void	sort_100n(t_list **lst_a, int n_elem_a)
{
	t_list	*lst_b;
	int		n_elem_b;
	int		min;
	int		pos_a;
	int		pos_b;
	
	n_elem_b = 0;
	if (!is_sorted(*lst_a))
	{
		while (n_elem_a)
		{
			pos_a = get_pos_mov(*lst_a, lst_b, n_elem_a, n_elem_b);
			pos_b = find_pos_insert_b(lst_b, find_number(*lst_a, pos_a, n_elem_a), n_elem_b);
			printf("--- %d %d---\n", pos_a, pos_b);
			rotate_2list(lst_a, &lst_b, pos_a, pos_b);
			push_b(lst_a, &lst_b, &n_elem_a, &n_elem_b);
			print_list(lst_b);
		}
		while (n_elem_b > 0)
			push_a(&lst_b, lst_a, &n_elem_b, &n_elem_a);
		if (!is_sorted(*lst_a))
		{
			min = find_min_max(*lst_a, 1);
			rotate_to_pos_a(lst_a, find_position(*lst_a, min, n_elem_a));
		}
	}
}
