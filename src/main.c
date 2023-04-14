/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroussea <aroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:53:33 by aroussea          #+#    #+#             */
/*   Updated: 2023/03/14 11:10:00 by aroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = fdf_init(open(argv[1], O_RDONLY));
		if (!fdf)
		{
			ft_free_fdf(fdf);
			return (1);
		}
		draw(fdf);
		mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
		mlx_loop_hook(fdf->mlx, event_handler, fdf);
		mlx_loop(fdf->mlx);
		return (0);
	}
	write (1, "Error, more than 1 arguments", 28);
	return (1);
}
