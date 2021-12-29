/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 21:11:58 by rmerzak           #+#    #+#             */
/*   Updated: 2021/12/29 23:31:41 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include<stdio.h>
char	**ft_getpath(char **env)
{
	int i;
	char *str;
	char **splited_path;
	str="hello";

	i = 0;
	while(env[i])
	{
		if (!ft_strncmp("PATH=",env[i],5))
			break;
		i++;
	}
	str = ft_substr(env[i],5,ft_strlen(env[i]));
	splited_path = ft_split(str,':');
	return (splited_path);
}

char	*ft_search_command(char *cmd,char **splited_path)
{
	char	**splited_cmd;
	char	*full_cmd;
	int		i;

	i = 0;
	splited_cmd = ft_split(cmd,' ');
	cmd = ft_strjoin("/",splited_cmd[0]);
	while (splited_path[i])
	{
		full_cmd=ft_strjoin(splited_path[i],cmd);
		if (!access(full_cmd, X_OK))
			break;
		else
		{
			free(full_cmd);
			i++;
		}
	}
	return full_cmd;
}
int ft_child1(char **argv,char **env,int *fd)
{
	int pid;
	char **splited_path;
	char *cmd_exist;
	char **cmd;
	int f;
	
	splited_path = ft_getpath(env);
	cmd_exist = ft_search_command(argv[2],splited_path);
	cmd = ft_split(argv[2],' ');
	pid = fork();
	if (pid == -1)
		return -1;
	if (pid == 0)
	{
		f = open(argv[1],O_RDONLY);
		dup2(fd[1],1);
		close(fd[0]);
		dup2(f,0);
		close(fd[1]);
		close(f);
		execve(cmd_exist,cmd,env);
	}
	return pid;
	
}
int ft_child2(char **argv,char **env,int *fd)
{
	int pid;
	char **splited_path;
	char *cmd_exist;
	char **cmd;
	int f;
	
	splited_path = ft_getpath(env);
	cmd_exist = ft_search_command(argv[3],splited_path);
	cmd = ft_split(argv[3],' ');
	pid = fork();
	if (pid == -1)
		return -1;
	if (pid == 0)
	{
		f = open(argv[4], O_RDWR | O_CREAT | O_TRUNC ,0777);
		dup2(fd[0],0);
		close(fd[1]);
		dup2(f,1);
		close(fd[0]);
		close(f);
		execve(cmd_exist,cmd,env);
	}
	return pid;
	
}


int main(int argc,char **argv,char **env)
{
	int pid[2];
	int p[2];
	int status;

	if ( argc == 5)
	{
		if (pipe(p) == -1)
			return 1;
	pid[0] = ft_child1(argv,env,p);
	pid[1] = ft_child2(argv,env,p);
	close(p[1]);
	close(p[0]);
	waitpid(pid[0], &status, 0);
    waitpid(pid[1], &status, 0);
	}
	else
		return 0;
}
