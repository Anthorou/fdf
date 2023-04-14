/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:57:49 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/14 13:10:33 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	check_line_if_ok(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] < '0' || line[i] > '9')
			&& line[i] != ' ' && line[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

static int	check_map(char **map, t_matrix *matrix)
{
	int	i;

	i = 0;
	matrix->width = ft_count_words(map[0], ' ');
	while (map[i])
	{
		if (ft_count_words(map[i], ' ') != matrix->width)
			return (0);
		if (!check_line_if_ok(map[i]))
			return (0);
		i++;
	}
	matrix->height = i;
	return (1);
}

static t_matrix	*donner_point(t_matrix *matrix, char **map)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	while (i < matrix->height)
	{
		j = 0;
		matrix->points[i] = (t_point *)malloc(sizeof(t_point)
				* matrix->width - 1);
		if (!matrix->points[i])
			return (NULL);
		split = ft_split(map[i], ' ');
		while (j < matrix->width)
		{
			matrix->points[i][j].x = j;
			matrix->points[i][j].y = i;
			matrix->points[i][j].z = ft_atoi(split[j]);
			j++;
		}
		i++;
		ft_free_map(split);
	}
	return (matrix);
}

static t_matrix	*matrix_init(t_matrix *matrix, char **map)
{
	if (!check_map(map, matrix))
		return (NULL);
	matrix->points = (t_point **)malloc(sizeof(t_point *) * matrix->height);
	if (!matrix->points)
		return (NULL);
	return (donner_point(matrix, map));
}

t_matrix	*map_creation(int fd)
{
	t_matrix	*matrix;
	char		*file;
	char		**map;

	file = NULL;
	file = get_all_line(fd, file);
	if (!file)
		return (NULL);
	map = ft_split(file, '\n');
	if (!map)
		return (NULL);
	ft_free_str(file);
	matrix = (t_matrix *)malloc(sizeof(t_matrix));
	if (!matrix)
		return (NULL);
	matrix = matrix_init(matrix, map);
	ft_free_map(map);
	if (!matrix)
	{
		matrix = ft_free_matrix(matrix);
		return (NULL);
	}
	return (matrix);
}
