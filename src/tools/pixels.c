/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/25 18:20:09 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    put_pixels(t_img *img, int x, int y, int color)
{
	char	*buffer;

	// if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
	// 	return ;
	buffer = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)buffer = color;
}

static void	create_cplan(t_data *fractal, t_complex *z, t_complex *c, double x, double y)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z->real = scale(x, -2, 2, WIN_WIDTH) * fractal->zoom;
		z->imagin = scale(y, 2, -2, WIN_HEIGHT) * fractal->zoom;
		c->real = fractal->julia_real;
		c->imagin = fractal->julia_i;
	}
	else
	{
		z->real = 0.0;
		z->imagin = 0.0;
		c->real = scale(x, -2, 2, WIN_WIDTH) * fractal->zoom;
		c->imagin = scale(y, 2, -2, WIN_HEIGHT) * fractal->zoom;
	}
}

void	set_pixels(t_data *fractal, double x, double y)
{
	int			it;
	int			color;
	t_complex	z;
	t_complex	c;
	
	it = 0;
	memset4struct(&z, 0, sizeof(t_complex));
	memset4struct(&c, 0, sizeof(t_complex));
	create_cplan(fractal, &z, &c, x, y);
	while (it < fractal->max_it)
	{
		z = sum(z_square(z), c);
		if ((z.real * z.real) + (z.imagin * z.imagin) > 4)
		{
			// color = scale(it, 0xC2BCD2, 0x473858, fractal->max_it);
			color = scale(it, 0xFF99C8, 0xE4C1F9, fractal->max_it);
			put_pixels(&fractal->img, x, y, color);
			// put_pixels(&fractal->img, x, y, fractal->color + (0xF682C8 * it));
			return ;
		}
		it++;
	}
	put_pixels(&fractal->img, x, y, 0x000000);
}
