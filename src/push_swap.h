/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:04:45 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/10 13:55:48 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#endif

void	swap(t_list **lst, int n_elem);
void	swap_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b);
void	push(t_list **origin, t_list **end, int *n_elem_o, int *n_elem_e);
void	rotate(t_list **lst, int n_elem);
void	rotate_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b);
void	r_rotate(t_list **lst, int n_elem);
void	r_rotate_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b);