/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:49:27 by marvin            #+#    #+#             */
/*   Updated: 2023/12/04 01:49:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	init_pipex(t_pipex *pipex, char *argv_cmd, char **envp, int *fd)
{
	ft_bzero(pipex, sizeof(t_pipex));
	get_cmds(pipex, argv_cmd);
	cmd_is_path(pipex, pipex->cmd[0]);
	get_path(pipex, envp);
	pipex->pipe_fd = fd;
}
