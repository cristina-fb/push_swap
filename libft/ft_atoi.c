/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:35:09 by crisfern          #+#    #+#             */
/*   Updated: 2021/08/24 14:40:28 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	num;

	i = 0;
	neg = 0;
	num = 0;
	while ((str[i] == '\n') || (str[i] == '\v') || (str[i] == '\f')
		|| (str[i] == '\r') || (str[i] == '\t') || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
		num = (num * 10) + str[i++] - 48;
	if (neg)
		num = ((long) num) * -1;
	return (num);
}
