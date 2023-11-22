/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 07:38:17 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/01 08:29:25 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function converts the initial portion of the string pointed to by str to
** int representation.
** ASCII 9 - 13 and 32 => Spaces ('\t', '\n', '\v', '\f', '\r', ' ')
*/
int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	if (!str)
		return (0);
	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		++i;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}
