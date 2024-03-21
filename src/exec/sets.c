/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:05:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/21 22:55:50 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	mandelbrot(char **argv, t_data fractal)
{
	t_complex	z;
	t_complex	c;
	
	fractal.name = argv[1];
	init_mlx(&fractal);
	memset4struct(&z, 0, sizeof(t_complex));
	memset4struct(&c, 0, sizeof(t_complex));
	draw(&fractal);
	mlx_loop(fractal.mlx_co);
}

void	julia(char **argv, t_data fractal)
{
	t_complex	z;
	t_complex	c;
	
	fractal.name = argv[1];
	init_mlx(&fractal);
	memset4struct(&z, 0, sizeof(t_complex));
	memset4struct(&c, 0, sizeof(t_complex));
	fractal.j_real = atod(argv[2]);
	fractal.j_imagin = atod(argv[3]);
	draw(&fractal);
	mlx_loop(fractal.mlx_co);
}
