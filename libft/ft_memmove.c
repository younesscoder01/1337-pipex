/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:21:30 by ysahraou          #+#    #+#             */
/*   Updated: 2024/03/11 09:39:49 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	unsigned char		*lastpd;
	unsigned const char	*lastps;
	unsigned const char	*ps;

	if (dest == src)
		return (dest);
	pd = (unsigned char *)dest;
	ps = (unsigned const char *)src;
	if (pd < ps)
	{
		while (n-- != 0)
			*pd++ = *ps++;
	}
	else
	{
		lastpd = (unsigned char *)dest + (n - 1);
		lastps = (unsigned const char *)src + (n - 1);
		while (n-- != 0)
			*lastpd-- = *lastps--;
	}
	return (dest);
}
