/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern </var/mail/crisfern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:26:36 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/01 11:47:47 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **lst_a, t_list **lst_b, int n_elem_a)
{
	t_list	*aux;

	if (n_elem_a > 0)
	{
		aux = *lst_a->next;
		*lst_a->next = *lst_b;
		*lst_b = *lst_a;
		*lst_a = aux;
	}
}

void	push_b(t_list **lst_a, t_list **lst_b, int n_elem_b)
{
	t_list	*aux;

	if (n_elem_b > 0)
	{
		aux = *lst_b->next;
		*lst_b->next = *lst_a;
		*lst_a = *lst_b;
		*lst_b = aux;
	}
}
