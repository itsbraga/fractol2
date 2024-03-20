/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:55:00 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/20 23:12:02 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void    put_pixels(t_img *img, int x, int y, double color)
{
	char	*buffer;

	if (x < 0 || x >= img->line_len || y < 0 || y >= WIN_HEIGHT)
		return ;
	buffer = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)buffer = color;
}

static void	create_cplan(t_fdata *fractal, t_complex *z, t_complex *c, double x, double y)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		z->real = scale(x, -2, 2, WIN_WIDTH) * fractal->zoom;
		z->imagin = scale(y, 2, -2, WIN_HEIGHT) * fractal->zoom;
		c->real = fractal->j_real;
		c->imagin = fractal->j_imagin;
	}
	else
	{
		z->real = 0.0;
		z->imagin = 0.0;
		c->real = scale(x, -2, 2, WIN_WIDTH) * fractal->zoom;
		c->imagin = scale(y, 2, -2, WIN_HEIGHT) * fractal->zoom;
	}
}

void	handle_pixels(t_fdata *fractal, double x, double y)
{
	double		it;
	double		color;
	t_complex	z;
	t_complex	c;
	
	it = 0;
	// memset4struct(&z, 0, sizeof(t_complex));
	// memset4struct(&c, 0, sizeof(t_complex));
	create_cplan(fractal, &z, &c, x, y);
	while (it < fractal->max_iter)
	{
		z = sum(z_sqrt(z), c);
		if ((z.real * z.real) + (z.imagin * z.imagin) > fractal->esc_val)
		{
			color = scale(it, 0xFFFFFF, 0x56F1FF, fractal->max_iter);
			put_pixels(&fractal->img, x, y, color);
			break ;
		}
		it++;
	}
	put_pixels(&fractal->img, x, y, 0x000000);
}
