/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:29:45 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/25 16:15:33 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	while (n > 0 && (*u1 || *u2))
	{
		if (*u1 != *u2)
		{
			return (*u1 - *u2);
		}
		u1++;
		u2++;
		n--;
	}
	return (0);
}
