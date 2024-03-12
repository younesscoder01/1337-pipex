#include "../includes/pipex.h"

int open_file(char *file_name, int in_or_out)
{
    int ret;

    if (in_or_out == 0)
        ret = open(file_name, O_RDONLY);
    else if (in_or_out == 1)
        ret = open(file_name, O_RDWR | O_CREAT);
    if (ret == -1)
        exit(0);
    return ret;
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
    all_paths = ft_split(path, ':');
    while (all_paths != 0)
    {
        printf("=> %s\n", *all_paths);
        all_paths++;
    }
    return  path;
}