/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:05:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/23 22:46:07 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	mandelbrot(char **argv, t_data fractal)
{
	// memset4struct(&fractal, 0, sizeof(t_data));
	fractal.name = argv[1];
	init_mlx(&fractal);
	draw(&fractal);
	mlx_loop(fractal.mlx_co);
}

void	julia(char **argv, t_data fractal)
{
	// memset4struct(&fractal, 0, sizeof(t_data));
	fractal.name = argv[1];
	init_mlx(&fractal);
	fractal.julia_real = atod(argv[2]);
	fractal.julia_i = atod(argv[3]);
	draw(&fractal);
	mlx_loop(fractal.mlx_co);
}
