/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:31:59 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/23 11:48:24 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	result;

	result = !n;
	while (n)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static char	*a_min(void)
{
	char	*min_int;
	char	*p;
	int		i;

	min_int = malloc(12 * sizeof(char));
	if (!min_int)
		return (NULL);
	p = "-2147483648";
	i = 0;
	while (i < 12)
	{
		min_int[i] = p[i];
		i++;
	}
	return (min_int);
}

char	*ft_itoa(int n)
{
	bool	sign;
	int		count;
	char	*nstr;

	if (n == -2147483648)
		return (a_min());
	sign = n < 0;
	count = ft_count(n) + sign;
	nstr = malloc((count + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	nstr[count--] = 0;
	while (sign && count)
	{
		*nstr = '-';
		nstr[count--] = -n % 10 + '0';
		n /= 10;
	}
	while (!sign && count >= 0)
	{
		nstr[count--] = n % 10 + '0';
		n /= 10;
	}
	return (nstr);
}
