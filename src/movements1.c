/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern </var/mail/crisfern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:20:02 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/03 21:26:39 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, int n_elem)
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = NULL;
	aux2 = NULL;
	if (n_elem > 1)
	{
		aux1 = lst[0]->next->next;
		lst[0]->next->next = lst[0];
		aux2 = lst[0]->next;
		lst[0]->next = aux1;
		lst[0] = aux2;
	}
}

void	swap_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b)
{
	swap(lst_a, n_elem_a);
	swap(lst_b, n_elem_b);
}

void	push(t_list **origin, t_list **end, int n_elem_o, int n_elem_e)
{
	t_list	*aux;

	aux = NULL;
	if (n_elem_o > 0)
	{
		aux = origin[0]->next;
		origin[0]->next = end[0];
		end[0] = origin[0];
		origin[0] = aux;
		n_elem_o--;
		n_elem_e++;
	}
}
