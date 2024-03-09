/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:42:12 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/25 15:08:54 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ns1;
	unsigned char	*ns2;

	if (s1 == s2)
		return (0);
	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (*ns1 != *ns2)
			return (*ns1 - *ns2);
		ns1++;
		ns2++;
		n--;
	}
	return (0);
}
