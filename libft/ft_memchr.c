/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:37:28 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/25 15:04:28 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ns;

	ns = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (ns[i] == (unsigned char)c)
			return (&ns[i]);
		n--;
		i++;
	}
	return (0);
}
