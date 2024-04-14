/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:24:17 by ysahraou          #+#    #+#             */
/*   Updated: 2024/04/14 13:24:52 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	err(char	*path)
{
	ft_putstr_fd("pipex: No such file or directory: ", 2);
	ft_putendl_fd(path, 2);
	exit(127);
}
