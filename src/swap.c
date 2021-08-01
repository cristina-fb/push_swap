/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern </var/mail/crisfern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 19:46:48 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/01 11:41:15 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_a(t_list **lst_a, int n_elem_a)
{
	t_list	*aux1;
	t_list	*aux2;

	if (n_elem_a > 1)
	{
		aux1 = *lst_a->next->next;
		*lst_a->next->next = *lst_a;
		aux2 = *lst_a->next;
		*lst_a->next = aux1;
		*lst_a = aux2;
	}
}

void	swap_b(t_list **lst_b, int n_elem_b)
{
	t_list	*aux1;
	t_list	*aux2;

	if (n_elem_b > 1)
	{
		aux1 = *lst_b->next->next;
		*lst_b->next->next = *lst_b;
		aux2 = *lst_b->next;
		*lst_b->next = aux1;
		*lst_b = aux2;
	}
}

void	swap_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b)
{
	swap_a(lst_a, n_elem_a);
	swap_b(lst_b, n_elem_b);
}
