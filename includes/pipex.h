/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:47:18 by ysahraou          #+#    #+#             */
/*   Updated: 2024/03/10 16:56:35 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*libraries*/
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

/*args*/
typedef struct s_arg
{
	char	*cmd1;
	char	*cmd2;
	char	**cmdop1;
	char	**cmdop2;
	int		fd[2];
	int		pid;
}			t_arg;

#endif
