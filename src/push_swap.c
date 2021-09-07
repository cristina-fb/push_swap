/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:34:23 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/24 15:36:35 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(1, "Error", 5);
	exit(0);
}

int	is_valid_arg(int argc, char **argv)
{
	char	*ptr;

	while (argc > 1)
	{
		ptr = argv[argc - 1];
		while (*ptr)
		{
			if ((ft_atoi(ptr) > INT_MAX) || (ft_atoi(ptr) < INT_MIN))
				return (0);
			if (((*ptr == '+') || (*ptr == '-')) && ft_isdigit(*(ptr + 1)))
				ptr++;
			else if (((*ptr == '+') || (*ptr == '-'))
				&& !ft_isdigit(*(ptr + 1)))
				return (0);
			while (ft_isdigit(*ptr))
				ptr++;
			while (*ptr == ' ')
				ptr++;
			if (*ptr && !ft_isdigit(*ptr) && (*ptr != '+') && (*ptr != '-'))
				return (0);
		}
		argc--;
	}
	return (1);
}

int	get_args(int argc, char **argv, t_list **lst)
{
	int		i;
	int		j;
	int		n;
	char		**split;

	i = 1;
	n = 0;
	while (i <= argc)
	{
		j = 0;
		split = ft_split(argv[i++], ' ');
		if (split)
		{
			while (split[j])
			{
				add_to_list(split[j], lst);
				free(split[j++]);
				n++;
			}
			free(split);
		}
	}
	return (n);
}

void	repeated_elements(t_list **lst)
{
	t_list	*aux1;
	t_list	*aux2;
	int		element;

	aux1 = *lst;
	while (aux1)
	{
		element = *(int *)aux1->content;
		aux2 = aux1->next;
		while (aux2)
		{
			if (*(int *)aux2->content == element)
			{
				free_list(lst);
				print_error();
			}
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
	}
}

int	is_sorted(t_list **lst)
{
	t_list	*aux;
	
	aux = *lst;
	if (aux)
	{
		while (aux->next)
		{
			if ((*(int *)aux->content) > (*(int *)aux->next->content))
				return (0);
			aux = aux->next;
		}
	}
	return (1);
}

void	sort_3n(t_list **lst, int n_elem)
{
	if (!is_sorted(lst))
	{
		if ((*(int *)lst[0]->content) > (*(int *)lst[0]->next->content))
			write(1, "ra\n", 3);
			rotate(lst, n_elem);
		else
			write(1, "rra\n", 4);
			r_rotate(lst, n_elem);
		if (!is_sorted(lst))
		{
			write(1, "sa\n", 3);
			swap(lst, n_elem);
			if (!is_sorted(lst))
			{
				write(1, "ra\n", 3);
				rotate(lst, n_elem);
			}
		}
	}
}

void	sort_5n(t_list **lst_a, int n_elem_a)
{
	t_list	*lst_b;
	int	n_elem_b;
	int	min;
	int	max;
	int	pos;
	
	lst_b = NULL;
	n_elem_b = 0;
	min = 0;
	max = 0;
	if (!is_sorted(lst_a))
	{
		while (n_elem_a > 3)
		{
			max = find_min_max(lst_a, 0);
			min = find_min_max(lst_a, 1);
			write(1, "pb\n", 3);
			push(lst_a, &lst_b, &n_elem_a, &n_elem_b);
		}
		sort_3n(lst_a, n_elem_a);
		while (n_elem_b > 0)
		{
			if ((*(int *)lst_a[0]->content) < min)
			{
				pos = find_position(lst_a, min);
				if (pos <= n_elem_a / 2)
				{
					while (pos-- > 0)
					{
						write(1, "ra\n", 3);
						rotate(lst_a, n_elem_a);
					}
					write(1, "pa\n", 3);
					push(lst_b, &lst_a, &n_elem_b, &n_elem_a);
				}	
				else
				{
					while (pos-- > 0)
					{
						write(1, "rra\n", 3);
						r_rotate(lst_a, n_elem_a);
					}
					write(1, "pa\n", 3);
					push(lst_b, &lst_a, &n_elem_b, &n_elem_a);
				}
				min = *(int *)lst_a[0]->content;
			}
			else if ((*(int *)lst_a[0]->content) > max)
			{
				pos = find_position(lst_a, max);
				if (pos >= n_elem_a / 2)
				{
					while (pos-- > 0)
					{
						write(1, "ra\n", 3);
						rotate(lst_a, n_elem_a);
					}
					write(1, "pa\n", 3);
					push(lst_b, &lst_a, &n_elem_b, &n_elem_a);
				}	
				else
				{
					while (pos-- > 0)
					{
						write(1, "rra\n", 3);
						r_rotate(lst_a, n_elem_a);
					}
					write(1, "pa\n", 3);
					push(lst_b, &lst_a, &n_elem_b, &n_elem_a);
				}
				max = *(int *)lst_a[0]->content;
			}
			else
			{
				pos = find_position_insert(lst_a, *(int *)lst_b[0]->content);
				if (pos <= n_elem_a / 2)
				{
					while (pos-- > 0)
					{
						write(1, "ra\n", 3);
						rotate(lst_a, n_elem_a);
					}
					write(1, "pa\n", 3);
					push(lst_b, &lst_a, &n_elem_b, &n_elem_a);
				}	
				else
				{
					while (pos-- > 0)
					{
						write(1, "rra\n", 3);
						r_rotate(lst_a, n_elem_a);
					}
					write(1, "pa\n", 3);
					push(lst_b, &lst_a, &n_elem_b, &n_elem_a);
				}		
			}
		}
		pos = find_position(lst_a, min);
		if (pos <= n_elem_a / 2)
		{
			while (pos-- > 0)
			{
				write(1, "ra\n", 3);
				rotate(lst_a, n_elem_a);}
			}	
		else
		{
			while (pos-- > 0)
			{
				write(1, "rra\n", 3);
				r_rotate(lst_a, n_elem_a);
			}
		}
	}
}

int find_position(t_list **lst, int n)
{
	t_list	*aux;
	int	pos;
	
	pos = 0;
	aux = *lst;
	while(aux)
	{
		if ((*(int *)lst[0]->content) == n)
			return(pos);
		pos++;
	}
	return (pos);
}

int find_position_insert(t_list **lst, int n)
{
	t_list	*aux;
	int	pos;
	
	pos = 0;
	aux = *lst;
	if (aux)
	{
		while(aux->next)
		{
			if (((*(int *)lst[0]->content) < n) && (*(int *)lst[0]->next->content) > n))
				return(pos + 1);
			pos++;
		}
	}
	return (0);
}

int find_min_max(t_list **lst, int min)
{
	int	n;
	t_list	*aux;
	
	aux = *lst;
	n = 0;
	if (min)
	{
		while (aux)
		{
			if ((*(int *)aux->content) < n)
				n = *(int *)aux->content;
			aux = aux->next;
		}
	}
	else
	{
		while (aux)
		{
			if ((*(int *)aux->content) > n)
				n = *(int *)aux->content;
			aux = aux->next;
		}
	}
	return (n);
}

int	main(int argc, char **argv)
{
	t_list	*lst;
	int n_elem;

	if ((argc < 1) || !is_valid_arg(argc, argv))
		print_error();
	else
	{
		n_elem = get_args(argc, argv, &lst);
		repeated_elements(&lst);
		if ((n_elem_a > 1) && (n_elem_a <= 3))
			sort_3n(&lst, n_elem);
		else if ((n_elem_a > 3) && (n_elem_a <= 5))
			sort_5n(&lst, n_elem);
		else if ((n_elem_a > 5) && (n_elem_a <= 100))
			sort_100n(&lst, n_elem);
		else if (n_elem_a > 100)
			sort_500n(&lst, n_elem);
		print_list(&lst);
		free_list(&lst);
	}
	return (0);
}
