/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:19:21 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/14 11:13:40 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_point	cp_point(t_point *point)
{
	t_point	new_point;

	new_point.x = point->x;
	new_point.y = point->y;
	new_point.z = point->z;
	return (new_point);
}

static void	rotate(int *x, int *y, int *z, t_camera *camera)
{
	float	old_x;
	float	old_y;

	old_y = *y;
	*y = (old_y * cos(camera->angle_x) + *z * sin(camera->angle_x)) + 0.5;
	*z = (-old_y * sin(camera->angle_x) + *z * cos(camera->angle_x)) + 0.5;
	old_x = *x;
	*x = (old_x * cos(camera->angle_y) + *z * sin(camera->angle_y)) + 0.5;
	*z = (-old_x * sin(camera->angle_y) + *z * cos(camera->angle_y)) + 0.5;
	old_x = *x;
	old_y = *y;
	*x = (old_x * cos(camera->angle_z) - old_y * sin(camera->angle_z)) + 0.5;
	*y = (old_x * sin(camera->angle_z) + old_y * cos(camera->angle_z)) + 0.5;
}

static void	iso(int *x, int *y, int z)
{
	float	old_x;
	float	old_y;

	old_x = *x;
	old_y = *y;
	*x = ((old_x - z) / sqrt(2)) + 0.5;
	*y = ((old_x + (2 * old_y) + z) / sqrt(6)) + 0.5;
}

t_point	point_projected(t_point *point, t_fdf *fdf)
{
	t_point	p_pro;

	p_pro = cp_point(point);
	p_pro.x *= fdf->camera->zoom;
	p_pro.y *= fdf->camera->zoom;
	p_pro.z *= fdf->camera->zoom - fdf->camera->range_z;
	p_pro.x -= ((fdf->matrix->width * fdf->camera->zoom) / 2) + 0.5;
	p_pro.y -= ((fdf->matrix->height * fdf->camera->zoom) / 2) + 0.5;
	rotate(&p_pro.x, &p_pro.y, &p_pro.z, fdf->camera);
	iso(&p_pro.x, &p_pro.y, p_pro.z);
	p_pro.x += 1920 / 2 + fdf->camera->shift_x;
	p_pro.y += 1080 / 2 + fdf->camera->shift_y;
	return (p_pro);
}
