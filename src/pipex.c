/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:21:05 by ysahraou          #+#    #+#             */
/*   Updated: 2024/04/17 13:17:02 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_shell(char **env)
{
	char	*shell;
	char	**shell_paths;
	int		i;

	i = 0;
	while (env[i])
	{
		shell = ft_strnstr(env[i], "SHELL", 5);
		if (shell)
			break ;
		i++;
	}
	i = 0;
	shell_paths = ft_split(shell, '/');
	while (shell_paths[i])
	{
		if (shell_paths[i + 1] == NULL)
			shell = ft_strdup(shell_paths[i]);
		i++;
	}
	free_all(shell_paths);
	shell_paths = NULL;
	return (shell);
}

static void	execute(char *cmd, char **env)
{
	char	**cmd_and_op;
	char	*path;

	if (cmd[0] == '\0')
	{
		ft_putstr_fd("pipex: command not found: \n", 2);
		exit(127);
	}
	cmd_and_op = ft_split(cmd, ' ');
	if (cmd_and_op[0][0] == '/' || cmd_and_op[0][0] == '.' )
	{
		path = cmd_and_op[0];
		if (access(path, F_OK | X_OK) == -1)
			err(path);
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

static void	child(char *argv[], char *env[], int p_fd[2])
{
	int		fd;
	char	*shell;

	shell = get_shell(env);
	if (!access(argv[1], F_OK))
	{
		if (access(argv[1], R_OK) == -1)
		{
			ft_putstr_fd(shell, 2);
			ft_putstr_fd(": permission denied: ", 2);
			ft_putendl_fd(argv[1], 2);
			free(shell);
			exit(1);
		}
	}
	fd = open_file(argv[1], 0, shell);
	dup2(fd, 0);
	close(fd);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	close(p_fd[1]);
	free(shell);
	execute(argv[2], env);
}

static void	child_2(char *argv[], char *env[], int p_fd[2])
{
	int		fd;
	char	*shell;

	shell = get_shell(env);
	if (!access(argv[4], F_OK))
	{
		if (access(argv[4], W_OK) == -1)
		{
			ft_putstr_fd(shell, 2);
			ft_putstr_fd(": permission denied: ", 2);
			ft_putendl_fd(argv[4], 2);
			free(shell);
			exit(1);
		}
	}
	fd = open_file(argv[4], 1, shell);
	dup2(fd, 1);
	close(fd);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	close(p_fd[0]);
	free(shell);
	execute(argv[3], env);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		p_fd[2];
	pid_t	pid;
	pid_t	pid_2;
	int		status;

	status = 0;
	pid_2 = 0;
	if (argc == 5)
	{
		if (pipe(p_fd) == -1)
			exit(-1);
		pid = fork();
		if (!pid)
			child(argv, envp, p_fd);
		else
			pid_2 = fork();
		if (!pid_2)
			child_2(argv, envp, p_fd);
		close(p_fd[0]);
		close(p_fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid_2, &status, 0);
		exit(status >> 8);
	}
	no_args(argv[2], argv[3]);
}
