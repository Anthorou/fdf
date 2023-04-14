/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:52:54 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/14 12:40:23 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i] != NULL)
			free(map[i++]);
		free(map);
		map = NULL;
	}
}

t_matrix	*ft_free_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		if (matrix->points)
		{
			while (i < matrix->height)
				free(matrix->points[i++]);
			free(matrix->points);
		}
		free(matrix);
		matrix = NULL;
	}
	return (matrix);
}

t_fdf	*ft_free_fdf(t_fdf *fdf)
{
	if (fdf)
	{
		if (fdf->matrix)
			ft_free_matrix(fdf->matrix);
		if (fdf->camera)
			free(fdf->camera);
	}
	fdf = NULL;
	return (fdf);
}
