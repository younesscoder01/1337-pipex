#include "../includes/pipex.h"

void child(char *argv[], char *env[], int p_fd[2]);
void parent(char *argv[], char *env[], int p_fd[2]);
void execute(char *cmd, char **env);


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
		if(!pid)
			child(argv, envp, p_fd);
		else
			parent(argv, envp, p_fd);
	}
	else
	{
		ft_putstr_fd("\033[0;31mError: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
}
void execute(char *cmd, char **env)
{
	char **cmd_and_op;
	char *path;

	cmd_and_op = ft_split(cmd, ' ');
	path = get_path(cmd_and_op[0], env);
	if (execve(path, cmd_and_op, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_and_op[0], 2);
		//ft_free_tab(s_cmd);
		exit(0);
	}
}

void child(char *argv[], char *env[], int p_fd[2])
{
	int fd;

	fd = open_file(argv[1], 0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execute(argv[2], env);
}

void parent(char *argv[], char *env[], int p_fd[2])
{
	int fd;

	fd = open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execute(argv[3], env);
}
