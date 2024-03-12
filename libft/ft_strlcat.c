/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:51:21 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/23 11:47:13 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	d_l;
	size_t	s_l;

	s = 0;
	s_l = ft_strlen(src);
	if (!dst && size == 0)
		return (s_l);
	d = ft_strlen(dst);
	d_l = d;
	if (size <= d_l)
		return (size + s_l);
	while (size > d + 1 && src[s] != '\0')
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = '\0';
	return (d_l + s_l);
}
