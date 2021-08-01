/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern </var/mail/crisfern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:04:20 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/01 14:23:21 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_list **lst_a, int n_elem_a)
{
	t_list	*aux1;
	t_list	*aux2;

	if (n_elem_a > 1)
	{
		aux1 = *lst_a;
		while (aux1->next)
			aux1 = aux1->next;
		aux2 = aux1;
		aux1->next = *lst_a;
		aux1 = NULL;
		*lst_a = aux2;
	}
}

void	r_rotate_b(t_list **lst_b, int n_elem_b)
{
	t_list	*aux1;
	t_list	*aux2;

	if (n_elem_b > 1)
	{
		aux1 = *lst_b;
		while (aux1->next)
			aux1 = aux1->next;
		aux2 = aux1;
		aux1->next = *lst_b;
		aux1 = NULL;
		*lst_b = aux2;
	}
}

void	r_rotate_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b)
{
	r_rotate_a(lst_a, n_elem_a);
	r_rotate_b(lst_b, n_elem_b);
}
