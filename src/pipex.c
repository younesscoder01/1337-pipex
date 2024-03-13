/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:21:05 by ysahraou          #+#    #+#             */
/*   Updated: 2024/03/13 14:14:00 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child(char *argv[], char *env[], int p_fd[2]);
void	parent(char *argv[], char *env[], int p_fd[2]);
void	execute(char *cmd, char **env);

int	main(int argc, char *argv[], char *envp[])
{
	int		p_fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(p_fd) == -1)
			exit(-1);
		pid = fork();
		if (pid == -1)
			exit(-1);
		if (!pid)
			child(argv, envp, p_fd);
		else
			parent(argv, envp, p_fd);
	}
	else
	{
		ft_putstr_fd("\033[0;31mError: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\033[1;0m\n", 1);
		exit(127);
	}
}

void	execute(char *cmd, char **env)
{
	char	**cmd_and_op;
	char	*path;

	cmd_and_op = ft_split(cmd, ' ');
	if (cmd_and_op[0][0] == '/')
	{
		path = cmd_and_op[0];
		if (access(path, F_OK | X_OK) == -1)
		{
			ft_putstr_fd("pipex: No such file or directory: ", 2);
			ft_putendl_fd(path, 2);
			exit(127);
		}
	}
	else
		path = get_path(cmd_and_op[0], env);
	if (execve(path, cmd_and_op, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_and_op[0], 2);
		free_all(cmd_and_op);
		exit(127);
	}
}

void	child(char *argv[], char *env[], int p_fd[2])
{
	int	fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execute(argv[2], env);
}

void	parent(char *argv[], char *env[], int p_fd[2])
{
	int	fd;

	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execute(argv[3], env);
}
