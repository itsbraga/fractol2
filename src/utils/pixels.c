/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/18 00:18:12 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    put_pixels_in_img(t_img *img, int x, int y, int color)
{
	char	*buffer;

	if (x < 0 || x >= img->line_len || y < 0 || y >= WIN_HEIGHT)
		return ;
	buffer = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)buffer = color;
}

void	handle_pixels(t_data *fractal, int x, int y)
{
	int			it;
	int			color;
	t_complex	z;
	t_complex	c;
	
	it = 0;
	create_cplan(fractal, &z, &c, x, y);
	while (it < fractal->max_iter)
	{
		z = sum(z_sqrt(z), c);
		if (((z.real * z.real) + (z.imagin * z.imagin)) > fractal->esc_val)
		{
			color = scale(it, 0xFFFFFF, 0x56F1FF, fractal->max_iter);
			put_pixels_in_img(&fractal->img, x, y, color);
			break ;
		}
		it++;
	}
	put_pixels_in_img(&fractal->img, x, y, 0x000000);
}
