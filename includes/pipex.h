/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:47:18 by ysahraou          #+#    #+#             */
/*   Updated: 2024/04/17 14:25:01 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*libraries*/
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

/*functions declaratio*/
int		open_file(char *file_name, int in_or_out, char *shell);
char	*get_path(char *the_cmd, char **env);
void	free_all(char **str);
void	err(char	*path);
void	no_args(void);
void	close_pipes(int fd1, int fd2);

#endif
