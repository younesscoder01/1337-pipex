#include "../includes/pipex.h"

int open_file(char *file_name, int in_or_out)
{
    int ret;

    if (in_or_out == 0)
        ret = open(file_name, O_RDONLY);
    else if (in_or_out == 1)
        ret = open(file_name, O_RDWR | O_CREAT, 0777);
    if (ret == -1)
        exit(0);
    return ret;
}

char *exc_path(char *paths, char *the_cmd)
{
    char *first_part;
    char **the_paths;
    char *cmd;
    int i;

    i = 0;
    while (paths[i] && paths[i] != '=')
            i++;
    first_part = ft_substr(&paths[i+1], 0, ft_strlen(paths));
    the_paths = ft_split(first_part, ':');
    i = 0;
    while (the_paths[i])
    {
        cmd = ft_strjoin(the_paths[i], "/");
        cmd = ft_strjoin(cmd, the_cmd);
        // printf("%s = ", cmd);
        if (access(cmd, F_OK | X_OK) == 0)
            return (cmd);
            // printf("yes\n");
        i++;
    }
    return NULL;
}


char *get_path(char *the_cmd, char **env)
{
    char *path;
    char **all_paths;
    while (*env)
	{
		path = ft_strnstr(*env, "PATH", 4);
		if (path)
			break;
		env++;
	}
    path = exc_path(path, the_cmd);
    return  path;
}