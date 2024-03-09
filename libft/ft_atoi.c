/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:32:59 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/22 17:57:32 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*nump;
	int		result;
	int		sign;

	nump = (char *)nptr;
	result = 0;
	sign = 1;
	while ((*nump >= 9 && *nump <= 13) || *nump == 32)
		nump++;
	if (*nump == '-' || *nump == '+')
	{
		if (*nump == '-')
			sign *= -1;
		nump++;
	}
	while (*nump != '\0')
	{
		if (*nump >= '0' && *nump <= '9')
			result = result * 10 + (*nump - 48);
		else
			return (result * sign);
		nump++;
	}
	return (result * sign);
}
