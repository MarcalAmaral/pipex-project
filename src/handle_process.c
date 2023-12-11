/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:13:45 by marvin            #+#    #+#             */
/*   Updated: 2023/12/06 17:13:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	execute(char *path, char **cmds, char **envp);

static void	first_process(t_pipex *pipex, char **envp)
{
	close(pipex->pipe_fd[0]);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	dup2(pipex->file_fd, STDIN_FILENO);
	close(pipex->pipe_fd[1]);
	close(pipex->file_fd);
	if (execute(pipex->path, pipex->cmd, envp) == 1)
		exit (1);
}

static void	second_process(t_pipex *pipex, char **envp)
{
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	dup2(pipex->file_fd, STDOUT_FILENO);
	close(pipex->pipe_fd[0]);
	close(pipex->file_fd);
	if (execute(pipex->path, pipex->cmd, envp) == 1)
		exit (1);
}

void	handle_first_process(char *file, char *argv_cmd, char **envp, int *fd)
{
	t_pipex	pipex;

	init_pipex(&pipex, argv_cmd, envp, fd);
	pipex.file_fd = validate_infile(file);
	if (pipex.file_fd == 1 || pipex.file_fd == -1)
	{
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		free(pipex.path);
		ft_free_matrix((void **) pipex.cmd);
		exit (1);
	}
	if (command_not_found(&pipex) == 127)
	{
		close(pipex.pipe_fd[0]);
		close(pipex.pipe_fd[1]);
		close(pipex.file_fd);
		exit (127);
	}
	else
		first_process(&pipex, envp);
	exit (0);
}

void	handle_second_process(char *file, char *argv_cmd, char **envp, int *fd)
{
	t_pipex	pipex;

	init_pipex(&pipex, argv_cmd, envp, fd);
	pipex.file_fd = validate_outfile(file);
	if (pipex.file_fd == 1 || pipex.file_fd == -1)
	{
		close(pipex.pipe_fd[0]);
		free(pipex.path);
		ft_free_matrix((void **) pipex.cmd);
		exit(1);
	}
	if (command_not_found(&pipex) == 127)
	{
		close(pipex.pipe_fd[0]);
		close(pipex.file_fd);
		exit(127);
	}
	else
		second_process(&pipex, envp);
	exit (0);
}

int	execute(char *path, char **cmds, char **envp)
{
	if (execve(path, cmds, envp) == -1)
	{
		free(path);
		ft_free_matrix((void **) cmds);
		perror("Error\n- Execve: ");
		return (1);
	}
	else
		return (0);
}
