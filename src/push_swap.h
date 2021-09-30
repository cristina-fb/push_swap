/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:04:45 by crisfern          #+#    #+#             */
/*   Updated: 2021/09/30 12:14:08 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	print_error(void);
void	print_list(t_list *lst);
void	free_list(t_list **lst);
void	repeated_elements(t_list **lst);
void	add_to_list(char *str, t_list **lst);

void	swap(t_list **lst);
void	swap_a(t_list **lst);
void	swap_b(t_list **lst);
void	swap_ab(t_list **lst_a, t_list **lst_b);
void	rotate(t_list **lst);
void	rotate_a(t_list **lst);
void	rotate_b(t_list **lst);
void	rotate_ab(t_list **lst_a, t_list **lst_b);
void	r_rotate(t_list **lst);
void	r_rotate_a(t_list **lst);
void	r_rotate_b(t_list **lst);
void	r_rotate_ab(t_list **lst_a, t_list **lst_b);
void	push_a(t_list **a, t_list **b, int *n_elem_a, int *n_elem_b);
void	push_b(t_list **b, t_list **a, int *n_elem_b, int *n_elem_a);

void	rotate_to_pos_a(t_list **lst, int pos);
void	rotate_to_pos_b(t_list **lst, int pos);
void	rotate_to_pos_ab(t_list **lst_a, t_list **lst_b, int pos);
void	rotate_2list(t_list **lst_a, t_list **lst_b, int pos_a, int pos_b);

void	sort_3n(t_list **lst);
void	sort_5n(t_list **lst_a, int n_elem_a);
void	sort_100n(t_list **lst_a, int n_elem_a);

int		is_valid_arg(int argc, char **argv);
int		get_args(int argc, char **argv, t_list **lst);
int		is_sorted(t_list *lst);
int		ft_abs(int n);

int		find_min_max(t_list *lst, int min);
int		find_number(t_list *lst, int pos, int n_elem);
int		find_position(t_list *lst, int n, int n_elem);
int		find_pos_insert_a(t_list *lst, int n, int n_elem);
int		find_pos_insert_b(t_list *lst, int n, int n_elem);
int		get_pos_mov(t_list *lst_a, t_list *lst_b, int n_elem_a, int n_elem_b);
int		get_n_mov(t_list *lst_b, int n_elem_b, int pos_a, int a);
#endif
