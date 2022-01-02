/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:11:58 by rmerzak           #+#    #+#             */
/*   Updated: 2022/01/02 23:36:49 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_getpath(char **env)
{
	int		i;
	char	*str;
	char	**splited_path;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			break ;
		i++;
	}
	str = ft_substr(env[i], 5, ft_strlen(env[i]));
	splited_path = ft_split(str, ':');
	free(str);
	return (splited_path);
}

static char	*ft_search_command(char *cmd, char **splited_path)
{
	char	**splited_cmd;
	char	*full_cmd;
	int		i;

	i = 0;
	splited_cmd = ft_split(cmd, ' ');
	cmd = ft_strjoin("/", splited_cmd[0]);
	while (splited_path[i])
	{
		full_cmd = ft_strjoin(splited_path[i], cmd);
		if (access(full_cmd, X_OK) == 0)
			break ;
		free(full_cmd);
		i++;
	}
	if (!splited_path[i])
	{
		write (1, "command not found\n", 18);
		ft_freee(splited_path);
		exit(0);
	}
	ft_fre(splited_cmd, cmd);
	return (full_cmd);
}

static int	ft_child1(char **argv, char **env, int *fd)
{
	int		pid;
	char	*cmd_exist;
	char	**cmd;
	char	**path;
	int		f;

	path = ft_getpath(env);
	cmd_exist = ft_search_command(argv[2], path);
	ft_freee(path);
	cmd = ft_split(argv[2], ' ');
	pid = fork();
	ft_pid(pid);
	if (pid == 0)
	{
		f = open(argv[1], O_RDONLY);
		ft_file(f);
		dup2(fd[1], 1);
		close(fd[0]);
		dup2(f, 0);
		close(fd[1]);
		close(f);
		execve(cmd_exist, cmd, env);
	}
	ft_fre(cmd, cmd_exist);
	return (pid);
}

static int	ft_child2(char **argv, char **env, int *fd)
{
	char	*cmd_exist;
	char	**cmd;
	char	**path;
	int		pid;
	int		f;

	path = ft_getpath(env);
	cmd_exist = ft_search_command(argv[3], path);
	ft_freee(path);
	cmd = ft_split(argv[3], ' ');
	pid = fork();
	ft_pid(pid);
	if (pid == 0)
	{
		f = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
		ft_file(f);
		dup2(fd[0], 0);
		close(fd[1]);
		dup2(f, 1);
		close(fd[0]);
		close(f);
		execve(cmd_exist, cmd, env);
	}
	ft_fre(cmd, cmd_exist);
	return (pid);
}

int	main(int argc, char **argv, char **env)
{
	int	pid[2];
	int	p[2];
	int	status;

	if (argc != 5)
		return (0);
	if (pipe(p) == -1)
	{
		perror("Error: pipe");
		return (-1);
	}
	pid[0] = ft_child1(argv, env, p);
	pid[1] = ft_child2(argv, env, p);
	close(p[1]);
	close(p[0]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
}
