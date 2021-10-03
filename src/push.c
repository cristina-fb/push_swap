/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:20:02 by crisfern          #+#    #+#             */
/*   Updated: 2021/10/03 11:36:47 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b, int *n_elem_a, int *n_elem_b)
{
	t_list	*aux;

	aux = NULL;
	if (*n_elem_a > 0)
	{
		aux = a[0]->next;
		a[0]->next = b[0];
		b[0] = a[0];
		a[0] = aux;
		*n_elem_a -= 1;
		*n_elem_b += 1;
		write(1, "pa\n", 3);
	}
}

void	push_b(t_list **b, t_list **a, int *n_elem_b, int *n_elem_a)
{
	t_list	*aux;

	aux = NULL;
	if (*n_elem_b > 0)
	{
		aux = b[0]->next;
		b[0]->next = a[0];
		a[0] = b[0];
		b[0] = aux;
		*n_elem_b -= 1;
		*n_elem_a += 1;
		write(1, "pb\n", 3);
	}
}
