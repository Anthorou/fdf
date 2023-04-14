/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:32:01 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/15 16:04:14 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	ft_close(t_fdf *fdf)
{
	ft_free_fdf(fdf);
	mlx_terminate(fdf->mlx);
	exit(0);
}

static void	rotation(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_Q)
		fdf->camera->angle_x += 0.1;
	else if (keydata.key == MLX_KEY_E)
		fdf->camera->angle_x -= 0.1;
	else if (keydata.key == MLX_KEY_A)
		fdf->camera->angle_y += 0.1;
	else if (keydata.key == MLX_KEY_D)
		fdf->camera->angle_y -= 0.1;
	else if (keydata.key == MLX_KEY_W)
		fdf->camera->angle_z += 0.1;
	else if (keydata.key == MLX_KEY_S)
		fdf->camera->angle_z -= 0.1;
}

static void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keydata.key == MLX_KEY_KP_ADD)
		fdf->camera->range_z -= 1;
	else if (keydata.key == MLX_KEY_KP_SUBTRACT)
		fdf->camera->range_z += 1;
	else if (keydata.key == MLX_KEY_UP)
		fdf->camera->shift_y += fdf->camera->zoom;
	else if (keydata.key == MLX_KEY_DOWN)
		fdf->camera->shift_y -= fdf->camera->zoom;
	else if (keydata.key == MLX_KEY_LEFT)
		fdf->camera->shift_x += fdf->camera->zoom;
	else if (keydata.key == MLX_KEY_RIGHT)
		fdf->camera->shift_x -= fdf->camera->zoom;
	else if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_E
		|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_D
		|| keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S)
		rotation(keydata, fdf);
	else if (keydata.key == MLX_KEY_ESCAPE)
		ft_close(fdf);
	draw(fdf);
}

static void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	(void)(xdelta);
	if (ydelta > 0)
		fdf->camera->zoom += 1;
	else if (ydelta < 0)
		fdf->camera->zoom -= 1;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf);
}

void	event_handler(void *param)
{
	t_fdf			*fdf;
	mlx_scrollfunc	scrollhandler;
	mlx_keyfunc		keyhandler;

	scrollhandler = &scroll_handler;
	keyhandler = &key_handler;
	fdf = (t_fdf *)param;
	mlx_scroll_hook(fdf->mlx, scrollhandler, fdf);
	mlx_key_hook(fdf->mlx, keyhandler, fdf);
}
