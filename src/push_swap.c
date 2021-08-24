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

void	get_args(int argc, char **argv, t_list **lst)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
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
			}
			free(split);
		}
	}
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

int	main(int argc, char **argv)
{
	t_list	*lst;

	if ((argc < 1) || !is_valid_arg(argc, argv))
		print_error();
	else
	{
		get_args(argc, argv, &lst);
		repeated_elements(&lst);
		print_list(&lst);
		free_list(&lst);
	}
	return (0);
}
