/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:20:02 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/24 10:24:31 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = NULL;
	aux2 = NULL;
	if (*lst)
	{
		aux1 = lst[0]->next->next;
		lst[0]->next->next = lst[0];
		aux2 = lst[0]->next;
		lst[0]->next = aux1;
		lst[0] = aux2;
	}
}

void	swap_a(t_list **lst)
{
	swap(lst);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **lst)
{
	swap(lst);
	write(1, "sb\n", 3);
}

void	swap_ab(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
	write(1, "ss\n", 3);
}
