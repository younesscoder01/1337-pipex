/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:16:27 by ysahraou          #+#    #+#             */
/*   Updated: 2023/11/20 14:52:31 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		size;

	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
