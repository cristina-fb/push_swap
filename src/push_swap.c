/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern </var/mail/crisfern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:34:23 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/01 10:59:22 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	is_valid_arg(int argc, char **argv)
{
	int	i;

	while (argc > 1)
	{
		i = 0;
		while (argv[argc][i])
		if (argv[argc][i])
		argc--;
	}
}*/

void	print_error(void)
{
	write(1, "Error", 5);
	exit(0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		print_error();
	else
	{
		printf("<%s>", argv[1]);
		//lst = initial_list();
	}
	return (0);
}
