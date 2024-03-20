/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:06 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/20 23:15:53 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	init_fdata(t_fdata *fractal)
{
	fractal->max_iter = 100;
	fractal->zoom = 1.0;
	fractal->esc_val = 4.0;
}

void	init_mlx(t_fdata *fractal)
{
	t_img	img;
	char	*title;

	title = ft_strjoin("Ana's fract-ol: ", fractal->name);
	memset4struct(&img, 0, sizeof(t_img));
	fractal->mlx_co = mlx_init();
	if (!fractal->mlx_co)
		(ft_printf(BOLD RED "MiniLibX connection failed!\n"), exit(1));
	fractal->win = mlx_new_window(fractal->mlx_co, WIN_WIDTH, WIN_HEIGHT, 
					title);
	if (!fractal->win)
		del_win(fractal);
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_co, WIN_WIDTH, WIN_HEIGHT);
	if (!fractal->img.img_ptr)
		del_img(fractal);
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr,
						&fractal->img.bpp,
						&fractal->img.line_len,
						&fractal->img.endian);
	init_fdata(fractal);
	handle_mlx_hooks(fractal);
}

void	draw(t_fdata *fractal)
{
	double	x;
	double	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			handle_pixels(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_co, fractal->win, 
		fractal->img.img_ptr, 0, 0);
}
