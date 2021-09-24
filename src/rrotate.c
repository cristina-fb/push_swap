/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:20:02 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/24 10:23:44 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_list **lst)
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = NULL;
	aux2 = NULL;
	if (*lst)
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

void	r_rotate_a(t_list **lst)
{
	r_rotate(lst);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_list **lst)
{
	r_rotate(lst);
	write(1, "rrb\n", 4);
}

void	r_rotate_ab(t_list **lst_a, t_list **lst_b)
{
	r_rotate(lst_a);
	r_rotate(lst_b);
	write(1, "rrr\n", 4);
}
