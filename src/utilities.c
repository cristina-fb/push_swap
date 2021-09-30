/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:20:02 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/30 12:41:40 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	get_pos_mov(t_list *lst_a, t_list *lst_b, int n_elem_a, int n_elem_b)
{
	int		pos;
	int		n_mov_min;
	int		pos_min;
	int		a;

	pos_min = 0;
	pos = -1;
	n_mov_min = n_elem_a;
	while (lst_a)
	{
		if (++pos > (n_elem_a / 2))
			pos = (n_elem_a - pos) * (-1);
		if (ft_abs(pos) < ft_abs(n_mov_min))
		{
			a = find_number(lst_a, 0, n_elem_a);
			if (ft_abs(get_n_mov(lst_b, n_elem_b, pos, a)) < n_mov_min)
			{
				n_mov_min = ft_abs(get_n_mov(lst_b, n_elem_b, pos, a));
				pos_min = pos;
			}
		}
		lst_a = lst_a->next;
	}
	return (pos_min);
}

int	get_n_mov(t_list *lst_b, int n_elem_b, int pos_a, int a)
{
	int	pos_b;

	pos_b = find_pos_insert_b(lst_b, a, n_elem_b);
	if (((pos_a >= 0) && (pos_b < 0)) || ((pos_b >= 0) && (pos_a < 0)))
		return (ft_abs(pos_a) + ft_abs(pos_b));
	else if (ft_abs(pos_a) >= ft_abs(pos_b))
		return (pos_a);
	else if (ft_abs(pos_a) < ft_abs(pos_b))
		return (pos_b);
	return (0);
}
