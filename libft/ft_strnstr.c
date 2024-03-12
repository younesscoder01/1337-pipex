/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:01:24 by ysahraou          #+#    #+#             */
/*   Updated: 2024/03/11 09:38:33 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	ltlen;

	ltlen = ft_strlen(little);
	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (len > i && big[i] && i + ltlen <= len)
	{
		if (ft_strncmp(little, &big[i], ltlen) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
