/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokogaw <myokogaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:28:37 by myokogaw          #+#    #+#             */
/*   Updated: 2023/10/10 21:02:29 by myokogaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = (char *) s + ft_strlen(s);
	while (ret >= s)
	{
		if (*ret == (char) c)
			return ((char *)ret);
		ret--;
	}
	return (NULL);
}
