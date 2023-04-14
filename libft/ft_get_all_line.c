/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:58:17 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/08 12:45:14 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_all_line(int fd, char *str)
{
	char	*buf;
	int		check;

	check = -1;
	buf = (char *)malloc(sizeof(char) * 2);
	while (check != 0)
	{
		check = read(fd, buf, 1);
		if (check < 0)
			return (NULL);
		buf[1] = '\0';
		if (check != 0)
			str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}
