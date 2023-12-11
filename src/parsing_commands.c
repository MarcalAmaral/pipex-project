/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:48:39 by marvin            #+#    #+#             */
/*   Updated: 2023/12/04 01:48:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	split_cmd(t_pipex *pipex, char *argv_cmd, char c)
{
	int	i;

	pipex->cmd = ft_split(argv_cmd, c);
	i = 0;
	while (pipex->cmd[0][i] != ' ')
		i++;
	pipex->cmd[0] = ft_substr(pipex->cmd[0], 0, i);
}

void	get_cmds(t_pipex *pipex, char *argv_cmd)
{
	int	i;

	i = ft_strlen(argv_cmd);
	while (argv_cmd[i] != '\'' && argv_cmd[i] != '\"' && i != 0)
		--i;
	if (i == 0)
		pipex->cmd = ft_split(argv_cmd, ' ');
	else
	{
		if (argv_cmd[i] == '\'')
			split_cmd(pipex, argv_cmd, '\'');
		else if (argv_cmd[i] == '\"')
			split_cmd(pipex, argv_cmd, '\"');
	}
}

void	cmd_is_path(t_pipex *pipex, char *path)
{
	if (ft_strchr(path, '/') != NULL)
	{
		if (access(path, F_OK | X_OK) == -1)
		{
			perror(path);
			pipex->path = NULL;
		}
		else
			pipex->path = ft_strdup(path);
	}
}
