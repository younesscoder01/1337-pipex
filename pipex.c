#include "pipex.h"

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        ft_putstr_fd("\033[0;31mError: Bad arguments\n", 2);
        ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
        return 1;
    }
    // first cmd
    char *cmd1 = ft_calloc(1, 1);
    // the arguments
    char **cmdop1 = ft_split(argv[2], 32);
    cmd1 = ft_strjoin("/bin/", cmdop1[0]); 
    // second cmd
    char *cmd2 = ft_calloc(1, 1);
    // the arguments
    char **cmdop2 = ft_split(argv[3], 32);
    cmd2 = ft_strjoin("/bin/", cmdop2[0]);    

    //print the all argument 
        // for (int i = 1; i <= 4; i++)
        //     printf("%s\n", argv[i]);
    // create pipe
    int fd[2];
    pipe(fd);
    // fork
    int pid = fork();
    if (!pid)
    {
        close(fd[0]);
        // chech if the file exist and grants read
        int check = access(argv[1], F_OK|R_OK);
        if (check == -1)
        {
            perror("zsh");
            exit(0);
        }
        // open infile
        int fd_infile = open(argv[1], O_RDWR);
        // // dup the stdin
        int fd_stdin = dup(0);
        // // dup2 the stdin with our fd_infile
        int fd_newin = dup2(fd_infile, 0);
        // // dup the stdout
        int fd_stdout = dup(1);
        // // dup2 the stdout with our pipe
        int fd_pipe = dup2(fd[1], 1);
        // // start the cmd1 
        execve(cmd1, cmdop1, NULL);
        close(fd[1]);
    }
    else
    {
        wait(NULL);
        close(fd[1]);
        // open oufile
        int fd_oufile = open(argv[4], O_RDWR);
        // // dup the stdou
        int fd_stdou = dup(1);
        // // dup2 the stdin with our fd_oufile
        int fd_newou = dup2(fd_oufile, 1);
        // dup the stdin
        int fd_stdin = dup(0);
        // dup2 the stdin with our pipe
        int fd_pipe = dup2(fd[0], 0);
        execve(cmd2, cmdop2, NULL);
        dup2(0, fd_stdin);
        close(fd[0]);
    }


    // // printf(" => %s\n", cmd1);
    // // printf(" => %s\n", cmd2);
}