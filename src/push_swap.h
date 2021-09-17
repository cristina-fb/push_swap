/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:04:45 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/17 13:47:25 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int     get_args(int argc, char **argv, t_list **lst);
int     is_valid_arg(int argc, char **argv);
int     is_sorted(t_list **lst);
int     find_position(t_list **lst, int n);
int     find_pos_insert(t_list **lst, int n);
int     find_min_max(t_list **lst, int min);

void	sort_3n(t_list **lst, int n_elem);
void	sort_5n(t_list **lst_a, int n_elem_a);

void	print_error(void);
void	free_list(t_list **lst);
void	print_list(t_list **lst);
void	repeated_elements(t_list **lst);
void	add_to_list(char *str, t_list **lst);
void	rotate_to_pos(t_list **lst, int pos, int n_elem);

void	swap(t_list **lst, int n_elem);
void	swap_a(t_list **lst, int n_elem);
void	swap_b(t_list **lst, int n_elem);
void	swap_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b);
void	push_a(t_list **origin, t_list **end, int *n_elem_o, int *n_elem_e);
void	push_b(t_list **origin, t_list **end, int *n_elem_o, int *n_elem_e);
void	rotate(t_list **lst, int n_elem);
void	rotate_a(t_list **lst, int n_elem);
void	rotate_b(t_list **lst, int n_elem);
void	rotate_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b);
void	r_rotate(t_list **lst, int n_elem);
void	r_rotate_a(t_list **lst, int n_elem);
void	r_rotate_b(t_list **lst, int n_elem);
void	r_rotate_ab(t_list **lst_a, t_list **lst_b, int n_elem_a, int n_elem_b);

#endif