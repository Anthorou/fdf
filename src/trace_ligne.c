/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ligne.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:14:58 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/14 11:15:42 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	dx_dy(t_draw draw, t_point point1, t_fdf *fdf)
{
	while (draw.i <= draw.d_x)
	{
		if ((point1.x < 1920 && point1.y < 1080)
			&& (point1.x >= 0 && point1.y >= 0))
			mlx_put_pixel(fdf->img, point1.x, point1.y, 0xFFFFFFFF);
		draw.i++;
		point1.x += draw.x_incr;
		draw.ex -= draw.dy;
		if (draw.ex < 0)
		{
				point1.y += draw.y_incr;
			draw.ex += draw.dx;
		}
	}
}

static void	dy_dx(t_draw draw, t_point point1, t_fdf *fdf)
{
	while (draw.i <= draw.d_y)
	{
		if ((point1.x < 1920 && point1.y < 1080)
			&& (point1.x >= 0 && point1.y >= 0))
			mlx_put_pixel(fdf->img, point1.x, point1.y, 0xFFFFFFFF);
		draw.i++;
		point1.y += draw.y_incr;
		draw.ey -= draw.dx;
		if (draw.ey < 0)
		{
			point1.x += draw.x_incr;
			draw.ey += draw.dy;
		}
	}
}

void	trace_ligne(t_point point1, t_point point2, t_fdf *fdf)
{
	t_draw	draw;

	draw.ex = ft_abs(point2.x - point1.x);
	draw.ey = ft_abs(point2.y - point1.y);
	draw.dx = 2 * draw.ex;
	draw.dy = 2 * draw.ey;
	draw.d_x = draw.ex;
	draw.d_y = draw.ey;
	draw.i = 0;
	draw.x_incr = 1;
	draw.y_incr = 1;
	if (point1.x > point2.x)
		draw.x_incr = -1;
	if (point1.y > point2.y)
		draw.y_incr = -1;
	if (draw.d_x > draw.d_y)
	{
		dx_dy(draw, point1, fdf);
	}
	if (draw.d_x <= draw.d_y)
	{
		dy_dx(draw, point1, fdf);
	}
}
