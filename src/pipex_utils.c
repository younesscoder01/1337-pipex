/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:23:13 by ysahraou          #+#    #+#             */
/*   Updated: 2024/03/13 11:48:56 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char *file_name, int in_or_out)
{
	int	ret;

	ret = 0;
	if (in_or_out == 0)
		ret = open(file_name, O_RDONLY);
	else if (in_or_out == 1)
		ret = open(file_name, O_RDWR | O_CREAT, 0777);
	if (ret == -1)
	{
		ft_putstr_fd("No such file or directory: ", 2);
		ft_putendl_fd(file_name, 2);
		exit(0);
	}
	return (ret);
}

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

char	*exc_cmd(char **the_paths, char *the_cmd)
{
	char	*cmd;
	char	*temp;
	int		i;

	i = 0;
	while (the_paths[i])
	{
		cmd = ft_strjoin(the_paths[i], "/");
		temp = cmd;
		cmd = ft_strjoin(cmd, the_cmd);
		if (access(cmd, F_OK | X_OK) == 0)
		{
			free_all(the_paths);
			return (cmd);
		}
		free(temp);
		free(cmd);
		i++;
	}
	free_all(the_paths);
	return (NULL);
}

char	*get_cmd(char *paths, char *the_cmd)
{
	char	*first_part;
	char	**the_paths;
	int		i;

	i = 0;
	while (paths[i] && paths[i] != '=')
		i++;
	first_part = ft_substr(&paths[i + 1], 0, ft_strlen(paths));
	the_paths = ft_split(first_part, ':');
	free(first_part);
	return (exc_cmd(the_paths, the_cmd));
}

char	*get_path(char *the_cmd, char **env)
{
	char	*path;

	while (*env)
	{
		path = ft_strnstr(*env, "PATH", 4);
		if (path)
			break ;
		env++;
	}
	path = get_cmd(path, the_cmd);
	return (path);
}
