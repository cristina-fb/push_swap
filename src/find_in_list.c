/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:20:02 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/23 10:31:32 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_max(t_list **lst, int min)
{
	int		n;
	t_list	*aux;

	aux = *lst;
	n = *(int *)aux->content;
	if (min)
	{
		while (aux->next)
		{
			if ((*(int *)aux->next->content) < n)
				n = *(int *)aux->next->content;
			aux = aux->next;
		}
	}
	else
	{
		while (aux->next)
		{
			if ((*(int *)aux->next->content) > n)
				n = *(int *)aux->next->content;
			aux = aux->next;
		}
	}
	return (n);
}

int	find_pos_insert(t_list **lst, int n, int n_elem)
{
	t_list	*aux;
	int		pos;

	pos = 0;
	aux = *lst;
	if (aux)
	{
		while (aux->next)
		{
			if ((n > find_min_max(lst, 0)) || (n < find_min_max(lst, 1)))
				return (find_position(lst, find_min_max(lst, 1), n_elem));
			else
			{
				if (((*(int *)aux->content) < n)
					&& ((*(int *)aux->next->content) > n))
					break ;
			}
			aux = aux->next;
			pos++;
		}
		if (++pos > n_elem / 2)
			pos = (n_elem - pos) * (-1);
		return (pos);
	}
	return (0);
}

int	find_position(t_list **lst, int n, int n_elem)
{
	t_list	*aux;
	int		pos;

	pos = 0;
	aux = *lst;
	while (aux)
	{
		if ((*(int *)aux->content) == n)
			break ;
		aux = aux->next;
		pos++;
	}
	if (pos > n_elem / 2)
		pos = (n_elem - pos) * (-1);
	return (pos);
}
