/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:19:23 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/23 11:52:22 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	unsigned const char	*ps;

	if (dest == src)
		return (dest);
	pd = (unsigned char *)dest;
	ps = (unsigned const char *)src;
	while (n-- != 0)
		*pd++ = *ps++;
	return (dest);
}
