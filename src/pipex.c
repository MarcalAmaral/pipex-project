/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:25:44 by marvin            #+#    #+#             */
/*   Updated: 2023/12/03 22:25:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	get_ret_process(int pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}

int	handle_forks(int argc, char **argv, char **envp, int *fd)
{
	int	pid1;
	int	pid2;
	int	ret1;
	int	ret2;

	pid1 = fork();
	if (pid1 == -1)
		perror("Fork first process: ");
	if (pid1 == 0)
		handle_first_process(argv[1], argv[2], envp, fd);
	close(fd[1]);
	pid2 = fork();
	if (pid2 == 0)
		handle_second_process(argv[argc - 1], argv[argc - 2], envp, fd);
	close(fd[0]);
	ret1 = get_ret_process(pid1);
	ret2 = get_ret_process(pid2);
	if (ret2 != 0)
		return (ret2);
	else if (ret1 != 0 && ret2 != 0)
		return (ret1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc != 5)
		exit (invalid_num_of_args());
	if (pipe(fd) == -1)
	{
		perror("Pipe: ");
		return (2);
	}
	return (handle_forks(argc, argv, envp, fd));
}
