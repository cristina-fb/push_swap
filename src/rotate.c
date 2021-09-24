/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:26:49 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/24 10:22:53 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*aux;

	aux = NULL;
	if (*lst)
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

void	rotate_a(t_list **lst)
{
	rotate(lst);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **lst)
{
	rotate(lst);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
	write(1, "rr\n", 3);
}
