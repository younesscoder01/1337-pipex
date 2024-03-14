/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:21:05 by ysahraou          #+#    #+#             */
/*   Updated: 2024/03/14 22:02:21 by ysahraou         ###   ########.fr       */
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

	cmd_and_op = ft_split(cmd, ' ');
	free(cmd);
	if (cmd_and_op[0][0] == '/')
	{
		path = cmd_and_op[0];
		if (access(path, F_OK | X_OK) == -1)
		{
			ft_putstr_fd("zsh: No such file or directory: ", 2);
			ft_putendl_fd(path, 2);
			exit(127);
		}
	}
	else
		path = get_path(cmd_and_op[0], env);
	if (execve(path, cmd_and_op, env) == -1)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putendl_fd(cmd_and_op[0], 2);
		free_all(cmd_and_op);
		exit(127);
	}
}

static void	child(char *argv[], char *env[], int p_fd[2])
{
	int		fd;
	char	*shell;

	free(argv[3]);
	shell = get_shell(env);
	if (!access(argv[1], F_OK))
	{
		if (access(argv[1], R_OK) == -1)
		{
			ft_putstr_fd(shell, 2);
			ft_putstr_fd(": permission denied: ", 2);
			ft_putendl_fd(argv[1], 2);
			exit(1);
		}
	}
	fd = open_file(argv[1], 0, shell, argv[2]);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	free(shell);
	execute(argv[2], env);
}

static void	parent(char *argv[], char *env[], int p_fd[2])
{
	int		fd;
	char	*shell;

	free(argv[2]);
	shell = get_shell(env);
	if (!access(argv[4], F_OK))
	{
		if (access(argv[4], W_OK) == -1)
		{
			ft_putstr_fd(shell, 2);
			ft_putstr_fd(": permission denied: ", 2);
			ft_putendl_fd(argv[4], 2);
			exit(1);
		}
	}
	fd = open_file(argv[4], 1, shell, argv[3]);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	free(shell);
	execute(argv[3], env);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		p_fd[2];
	pid_t	pid;

	argv[2] = ft_strtrim(argv[2], " 	");
	argv[3] = ft_strtrim(argv[3], " 	");
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
		free(argv[2]);
		free(argv[3]);
		exit(127);
	}
}
