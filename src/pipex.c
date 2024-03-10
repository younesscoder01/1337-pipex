/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahraou <ysahraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:19:12 by ysahraou          #+#    #+#             */
/*   Updated: 2024/03/10 16:56:55 by ysahraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	parent(int *fd, char **argv, char *cmd2, char **cmdop2);
void	child(int *fd, char **argv, char *cmd1, char **cmdop1);

int	main(int argc, char *argv[])
{
	t_arg	args;

	if (argc != 5)
	{
		ft_putstr_fd("\033[0;31mError: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		return (1);
	}
	args.cmd1 = ft_calloc(1, 1);
	args.cmdop1 = ft_split(argv[2], 32);
	args.cmd1 = ft_strjoin("/bin/", args.cmdop1[0]);
	args.cmd2 = ft_calloc(1, 1);
	args.cmdop2 = ft_split(argv[3], 32);
	args.cmd2 = ft_strjoin("/bin/", args.cmdop2[0]);
	pipe(args.fd);
	args.pid = fork();
	if (!args.pid)
		child(args.fd, argv, args.cmd1, args.cmdop1);
	else
		parent(args.fd, argv, args.cmd2, args.cmdop2);
}

void	child(int *fd, char **argv, char *cmd1, char **cmdop1)
{
	int	fd_infile;
	int	fd_newin;
	int	fd_pipe;
	int	check;

	close(fd[0]);
	check = access(argv[1], F_OK | R_OK);
	if (check == -1)
	{
		perror("zsh");
		exit(0);
	}
	fd_infile = open(argv[1], O_RDWR);
	fd_newin = dup2(fd_infile, 0);
	fd_pipe = dup2(fd[1], 1);
	execve(cmd1, cmdop1, NULL);
	close(fd[1]);
}

void	parent(int *fd, char **argv, char *cmd2, char **cmdop2)
{
	int	fd_oufile;
	int	fd_stdin;
	int	fd_newou;
	int	fd_pipe;

	wait(NULL);
	close(fd[1]);
	fd_oufile = open(argv[4], O_RDWR);
	fd_stdin = dup(0);
	fd_newou = dup2(fd_oufile, 1);
	fd_pipe = dup2(fd[0], 0);
	execve(cmd2, cmdop2, NULL);
	dup2(0, fd_stdin);
	close(fd[0]);
}
