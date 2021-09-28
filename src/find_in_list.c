/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:20:02 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/28 15:06:00 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_max(t_list *lst, int min)
{
	int		n;

	n = *(int *)lst->content;
	if (min)
	{
		while (lst->next)
		{
			if ((*(int *)lst->next->content) < n)
				n = *(int *)lst->next->content;
			lst = lst->next;
		}
	}
	else
	{
		while (lst->next)
		{
			if ((*(int *)lst->next->content) > n)
				n = *(int *)lst->next->content;
			lst = lst->next;
		}
	}
	return (n);
}

int	find_pos_insert_a(t_list *lst, int n, int n_elem)
{
	int		pos;

	pos = 0;
	if (lst)
	{
		while (lst->next)
		{
			if ((n > find_min_max(lst, 0)) || (n < find_min_max(lst, 1)))
				return (find_position(lst, find_min_max(lst, 1), n_elem));
			else
			{
				if (((*(int *)lst->content) < n)
					&& ((*(int *)lst->next->content) > n))
					break ;
			}
			lst = lst->next;
			pos++;
		}
		if (++pos > n_elem / 2)
			pos = (n_elem - pos) * (-1);
		return (pos);
	}
	return (0);
}

int	find_pos_insert_b(t_list *lst, int n, int n_elem)
{
	int		pos;

	pos = 0;
	if (lst)
	{
		while (lst->next)
		{
			if ((n > find_min_max(lst, 0)) || (n < find_min_max(lst, 1)))
				return (find_position(lst, find_min_max(lst, 0), n_elem));
			else
			{
				if (((*(int *)lst->content) > n)
					&& ((*(int *)lst->next->content) < n))
					break ;
			}
			lst = lst->next;
			pos++;
		}
		if (++pos > n_elem / 2)
			pos = (n_elem - pos) * (-1);
		return (pos);
	}
	return (0);
}

int	find_position(t_list *lst, int n, int n_elem)
{
	int		pos;

	pos = 0;
	while (lst)
	{
		if ((*(int *)lst->content) == n)
			break ;
		lst = lst->next;
		pos++;
	}
	if (pos > n_elem / 2)
		pos = (n_elem - pos) * (-1);
	return (pos);
}

int	find_number(t_list *lst, int pos, int n_elem)
{
	int		i;

	i = 0;
	if (pos < 0)
		pos = n_elem + pos;
	while (lst)
	{
		if (i == pos)
			return (*(int *)lst->content);
		lst = lst->next;
		i++;
	}
	return (0);
}
