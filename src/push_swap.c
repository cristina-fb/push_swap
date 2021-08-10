/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:34:23 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/10 15:45:15 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list **list)
{
	t_list	*aux;

	aux = list[0];
	while (aux)
	{
		printf("<%d>\n", *(int *)aux->content);
		aux = aux->next;
	}
}

void	print_error(void)
{
	write(1, "Error", 5);
	exit(0);
}

void prueba(t_list *lst_a)
{
	ft_lstadd_back(&lst_a, ft_lstnew(28));
}

int	main(int argc, char **argv)
{
	int a = 1, d = 4, e = 5, f = 6;
	int n_elem_a = 6, n_elem_b = 0;
	t_list	*lst_a = NULL, *lst_b = NULL;

	if (argc < 2)
		print_error();
	else
	{
		printf("<Prog %s>\n", argv[0]);
		lst_a = ft_lstnew(&a);
		prueba(lst_a);
		prueba(lst_a);
		ft_lstadd_back(&lst_a, ft_lstnew(&d));
		ft_lstadd_back(&lst_a, ft_lstnew(&e));
		ft_lstadd_back(&lst_a, ft_lstnew(&f));
		push(&lst_a, &lst_b, &n_elem_a, &n_elem_b);
		push(&lst_a, &lst_b, &n_elem_a, &n_elem_b);
		push(&lst_a, &lst_b, &n_elem_a, &n_elem_b);
		print_list(&lst_a);
		printf("\\\\\\\\\\ \n");
		print_list(&lst_b);
		printf("%d %d\n", n_elem_a, n_elem_b);
		printf("-------------------------- \n");
		rotate_ab(&lst_a, &lst_b, n_elem_a, n_elem_b);
		rotate_ab(&lst_a, &lst_b, n_elem_a, n_elem_b);
		print_list(&lst_a);
		printf("\\\\\\\\\\ \n");
		print_list(&lst_b);
		printf("%d %d\n", n_elem_a, n_elem_b);
	}
	return (0);
}
