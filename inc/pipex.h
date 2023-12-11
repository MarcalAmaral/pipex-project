/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:42:12 by myokogaw          #+#    #+#             */
/*   Updated: 2023/12/03 22:17:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/inc/libft.h"

/* perror funct */
# include <stdio.h>

/* open funct*/
# include <fcntl.h>

/* wait funct */
# include <sys/wait.h>

/* perror funct */
# include <errno.h>

typedef struct s_pipex {
	char	*path;
	char	**cmd;
	int		file_fd;
	int		*pipe_fd;
}	t_pipex;

/* Handling process */
void	handle_first_process(char *file, char *argv_cmd, char **envp, int *fd);
void	handle_second_process(char *file, char *argv_cmd, char **envp, int *fd);

/* Get paths for bin*/
void	cmd_is_path(t_pipex *pipex, char *path);
void	get_path(t_pipex *pipex, char **envp);

/* Handle free */
void	ft_free_matrix(void **matrix);

/* Validations */
int		validate_infile(char *file_path);
int		validate_outfile(char *file_path);
int		command_not_found(t_pipex *pipex);

/* Handle errors */
int		invalid_num_of_args(void);

/* Parsing argv for get cmd*/
void	get_cmds(t_pipex *pipex, char *argv_cmd);

/* Initializing struct pipex */
void	init_pipex(t_pipex *pipex, char *argv_cmd, char **envp, int *fd);

#endif