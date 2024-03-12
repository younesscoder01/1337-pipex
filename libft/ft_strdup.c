/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:54:36 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/25 16:14:56 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*str;

	len = ft_strlen(s);
	i = len;
	str = malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (len-- > 0)
		*str++ = *s++;
	*str = '\0';
	return (str - i);
}
