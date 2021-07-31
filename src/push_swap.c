/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern </var/mail/crisfern>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:34:23 by crisfern          #+#    #+#             */
/*   Updated: 2021/07/31 12:34:54 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_error(void)
{
	write(1, "Error", 5);
	exit(0);
}

int main(int argc, char** argv)
{
	char	**p = ft_split(argv[1], ' ');

	if (argc < 2)
		print_error();
	else
	{
		printf("<%s>\n", p[0]);
		printf("<%s>\n", p[1]);
	}
	return (0);
}
