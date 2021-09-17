/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:20:02 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/17 12:07:50 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	r_rotate_a(t_list **lst, int n_elem)
{
	r_rotate(lst, n_elem);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_list **lst, int n_elem)
{
	r_rotate(lst, n_elem);
	write(1, "rrb\n", 4);
}

void	r_rotate_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b)
{
	r_rotate(lst_a, n_elem_a);
	r_rotate(lst_b, n_elem_b);
	write(1, "rrr\n", 4);
}
