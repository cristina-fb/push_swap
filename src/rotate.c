/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern </var/mail/crisfern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 11:01:27 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/01 11:38:47 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **lst_a, int n_elem_a)
{
	t_list	*aux1;
	t_list	*aux2;

	if (n_elem_a > 1)
	{
		aux1 = *lst_a->next;
		aux2 = *lst_a;
		while (aux2)
			aux2 = aux2->next;
		aux2 = *lst_a;
		*lst_a->next = NULL;
		*lst_a = aux1;
	}
}

void	rotate_b(t_list **lst_b, int n_elem_b)
{
	t_list	*aux1;
	t_list	*aux2;

	if (n_elem_b > 1)
	{
		aux1 = *lst_b->next;
		aux2 = *lst_b;
		while (aux2)
			aux2 = aux2->next;
		aux2 = *lst_b;
		*lst_b->next = NULL;
		*lst_b = aux1;
	}
}

void	rotate_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b)
{
	rotate_a(lst_a, n_elem_a);
	rotate_b(lst_b, n_elem_b);
}
