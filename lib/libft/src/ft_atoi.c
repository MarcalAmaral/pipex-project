/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 00:21:58 by myokogaw          #+#    #+#             */
/*   Updated: 2023/11/18 11:37:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	result;

	signal = 1;
	result = 0;
	while (((*nptr >= 9) && (*nptr <= 13)) || *nptr == 32)
		nptr++;
	if ((*nptr == 45) || (*nptr == 43))
	{
		if (*nptr == 45)
			signal *= -1;
		nptr++;
	}
	while ((*nptr >= 48) && (*nptr <= 57))
	{
		result *= 10;
		result += *nptr - 48;
		nptr++;
	}
	return (result * signal);
}
