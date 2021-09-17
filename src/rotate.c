/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:26:49 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/17 12:11:15 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst, int n_elem)
{
	t_list	*aux;

	aux = NULL;
	if (n_elem > 1)
	{
		aux = lst[0];
		while (aux->next)
			aux = aux->next;
		aux->next = lst[0];
		aux = lst[0];
		lst[0] = lst[0]->next;
		aux->next = NULL;
	}
}

void	rotate_a(t_list **lst, int n_elem)
{
	rotate(lst, n_elem);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **lst, int n_elem)
{
	rotate(lst, n_elem);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b)
{
	rotate(lst_a, n_elem_a);
	rotate(lst_b, n_elem_b);
	write(1, "rr\n", 3);
}
