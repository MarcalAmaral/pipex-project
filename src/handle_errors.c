/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:51:23 by marvin            #+#    #+#             */
/*   Updated: 2023/12/10 11:51:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	invalid_num_of_args(void)
{
	ft_putstr_fd("Error\n Missing parameters, pass like:", STDERR_FILENO);
	ft_putstr_fd(" ./program infile [CMD] [CMD] outfile\n", STDERR_FILENO);
	return (1);
}
