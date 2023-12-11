/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 01:05:05 by marvin            #+#    #+#             */
/*   Updated: 2023/12/04 01:05:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	*ft_delete_start_str(char *str, char *str_to_del);
static char	**ft_append_str_matrix(char **matrix, char *str);
static char	**formating_paths(char **envp);

void	get_path(t_pipex *pipex, char **envp)
{
	int		i;
	char	**format_paths;
	char	*path_to_validate;

	format_paths = formating_paths(envp);
	i = 0;
	while (format_paths[i])
	{
		path_to_validate = \
		ft_strjoin(format_paths[i], pipex->cmd[0]);
		if (access(path_to_validate, F_OK | X_OK) == 0 && pipex->path == NULL)
			pipex->path = ft_strdup(path_to_validate);
		free(path_to_validate);
		i++;
	}
	ft_free_matrix((void **) format_paths);
	return ;
}

static char	*ft_delete_start_str(char *str, char *str_to_del)
{
	int		str_to_del_len;
	int		str_len;
	char	*str_ret;

	str_to_del_len = ft_strlen(str_to_del);
	str_len = ft_strlen(str);
	str_ret = ft_substr(str, str_to_del_len, str_len);
	return (str_ret);
}

static char	**ft_append_str_matrix(char **matrix, char *str)
{
	char	*prev_str;
	int		i;

	i = 0;
	while (matrix[i])
	{
		prev_str = matrix[i];
		matrix[i] = ft_strjoin(matrix[i], str);
		free(prev_str);
		i++;
	}
	return (matrix);
}

static char	**formating_paths(char **envp)
{
	int		i;
	char	*format_str;
	char	**matrix_to_ret;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	format_str = ft_delete_start_str(ft_strdup(envp[i]), "PATH=");
	matrix_to_ret = ft_split(format_str, ':');
	matrix_to_ret = ft_append_str_matrix(matrix_to_ret, "/");
	free(format_str);
	return (matrix_to_ret);
}
