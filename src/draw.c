/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:44:51 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/14 11:18:27 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	draw_point(t_point *point, t_fdf *fdf, int i, int j)
{
	t_point	point1;
	t_point	point2;

	point1 = point_projected(point, fdf);
	if (i == fdf->matrix->height - 1 && j == fdf->matrix->width - 1)
		return ;
	else if (i == fdf->matrix->height - 1)
	{
		point2 = point_projected(&fdf->matrix->points[i][j + 1], fdf);
		trace_ligne(point1, point2, fdf);
	}
	else if (j == fdf->matrix->width - 1)
	{
		point2 = point_projected(&fdf->matrix->points[i + 1][j], fdf);
		trace_ligne(point1, point2, fdf);
	}
	else
	{
		point2 = point_projected(&fdf->matrix->points[i][j + 1], fdf);
		trace_ligne(point1, point2, fdf);
		point2 = point_projected(&fdf->matrix->points[i + 1][j], fdf);
		trace_ligne(point1, point2, fdf);
	}
}

void	draw(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	ft_bzero(fdf->img->pixels, 1920 * 1080 * 4);
	while (i < fdf->matrix->height)
	{
		j = 0;
		while (j < fdf->matrix->width)
		{
			draw_point(&fdf->matrix->points[i][j], fdf, i, j);
			j++;
		}
		i++;
	}
}
