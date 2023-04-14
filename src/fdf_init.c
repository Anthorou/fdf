/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:05:21 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/06 17:52:09 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static t_camera	*camera_init(void)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->zoom = 10;
	camera->angle_x = -1.2;
	camera->angle_y = -0.1;
	camera->angle_z = 0.2;
	camera->range_z = 0;
	camera->shift_x = 0;
	camera->shift_y = 0;
	return (camera);
}

static void	put_str(t_fdf *fdf)
{
	mlx_put_string(fdf->mlx, "Controls", 10, 10);
	mlx_put_string(fdf->mlx, "________", 10, 12);
	mlx_put_string(fdf->mlx, "Zoom: scroll", 10, 30);
	mlx_put_string(fdf->mlx, "Move: arrow keys", 10, 45);
	mlx_put_string(fdf->mlx, "Change height: +/-", 10, 60);
	mlx_put_string(fdf->mlx, "Rotation x: q/e", 10, 75);
	mlx_put_string(fdf->mlx, "Rotation y: a/d", 10, 90);
	mlx_put_string(fdf->mlx, "Rotation z: w/s", 10, 105);
	mlx_put_string(fdf->mlx, "Close: esc", 10, 120);
}

static t_fdf	*win_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init(1920, 1080, "fdf", true);
	if (fdf->mlx)
	{
		fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
		if (fdf->img)
		{
			put_str(fdf);
			fdf->camera = camera_init();
			if (!fdf->camera)
				return (NULL);
			return (fdf);
		}
	}
	return (NULL);
}

t_fdf	*fdf_init(int fd)
{
	t_fdf	*fdf;

	if (fd < 0)
	{
		write(1, "Map doesn't exist!", 18);
		return (NULL);
	}
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->matrix = map_creation(fd);
	if (!fdf->matrix)
	{
		write(1, "Map error!", 10);
		return (NULL);
	}
	close(fd);
	return (win_init(fdf));
}
