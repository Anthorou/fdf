/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:53:51 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/14 11:20:33 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "../libft/libft.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_matrix
{
	t_point	**points;
	int		width;
	int		height;
}	t_matrix;

typedef struct s_camera
{
	int		zoom;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	int		range_z;
	int		shift_x;
	int		shift_y;
}	t_camera;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_matrix	*matrix;
	t_camera	*camera;
}	t_fdf;

typedef struct s_draw
{
	int	ex;
	int	ey;
	int	dx;
	int	dy;
	int	d_x;
	int	d_y;
	int	i;
	int	x_incr;
	int	y_incr;
}	t_draw;

void		trace_ligne(t_point point1, t_point point2, t_fdf *fdf);
t_fdf		*fdf_init(int fd);
t_matrix	*map_creation(int fd);
void		ft_free_str(char *str);
void		ft_free_map(char **map);
t_matrix	*ft_free_matrix(t_matrix *matrix);
t_fdf		*ft_free_fdf(t_fdf *fdf);
void		draw(t_fdf *fdf);
t_point		point_projected(t_point *point, t_fdf *fdf);
void		event_handler(void *param);

#endif