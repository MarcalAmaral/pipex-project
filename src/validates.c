/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validates.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:47:39 by marvin            #+#    #+#             */
/*   Updated: 2023/12/04 01:47:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	command_not_found(t_pipex *pipex)
{
	if (pipex->path == NULL)
	{
		ft_putstr_fd(pipex->cmd[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		free(pipex->path);
		ft_free_matrix((void **) pipex->cmd);
		return (127);
	}
	return (0);
}

int	validate_infile(char *file_path)
{
	int	fd;

	if (access(file_path, F_OK) == -1)
	{
		perror(file_path);
		return (1);
	}
	if (access(file_path, R_OK) == -1)
	{
		perror(file_path);
		return (1);
	}
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("An error ocurred when open infile: ");
		return (-1);
	}
	return (fd);
}

int	validate_outfile(char *file_path)
{
	int	fd;

	if (access(file_path, F_OK))
	{
		fd = open(file_path, O_WRONLY | O_CREAT, 0644);
		return (fd);
	}
	else
	{
		if (access(file_path, W_OK))
		{
			perror(file_path);
			return (1);
		}
		fd = open(file_path, O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("An error ocurred when open/create outfile: ");
			return (1);
		}
		return (fd);
	}
}
