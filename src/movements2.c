/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern </var/mail/crisfern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:26:49 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/03 21:34:58 by crisfern         ###   ########.fr       */
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

void	rotate_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b)
{
	rotate(lst_a, n_elem_a);
	rotate(lst_b, n_elem_b);
}

void	r_rotate(t_list **lst, int n_elem)
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = NULL;
	aux2 = NULL;
	if (n_elem > 1)
	{
		aux1 = lst[0];
		while (aux1->next->next)
			aux1 = aux1->next;
		aux2 = aux1->next;
		aux1->next->next = lst[0];
		aux1->next = NULL;
		lst[0] = aux2;
	}
}

void	r_rotate_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b)
{
	r_rotate(lst_a, n_elem_a);
	r_rotate(lst_b, n_elem_b);
}
