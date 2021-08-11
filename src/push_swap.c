/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:34:23 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/11 15:56:51 by crisfern         ###   ########.fr       */
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
	int i;

	while (argc > 1)
	{
		i = 0;
		while (argv[argc - 1][i])
		{
			if (!ft_isdigit(argv[argc - 1][i]) || (argv[argc - 1][i] != '+') || (argv[argc - 1][i] != '-'))
				print_error();
			i++;
		}
		argc--;
	}
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

int	main(int argc, char **argv)
{
	t_list	*lst;

	if ((argc < 2) || !is_valid_arg(argc, argv))
		print_error();
	else
	{
		get_args(argc, argv, &lst);
		print_list(&lst);
		//free_list(&lst);
	}
	//system("leaks push_swap");
	return (0);
}
