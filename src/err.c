/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 13:24:17 by ysahraou          #+#    #+#             */
/*   Updated: 2024/04/17 14:26:22 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	err(char	*path)
{
	ft_putstr_fd("pipex: No such file or directory: ", 2);
	ft_putendl_fd(path, 2);
	exit(127);
}

void	no_args(void)
{
	ft_putstr_fd("\033[0;31mError: Bad arguments\n", 2);
	ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\033[1;0m\n", 1);
	exit(127);
}


void	close_pipes(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
