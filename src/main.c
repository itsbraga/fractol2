/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:12:58 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/20 23:09:15 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fdata	fractal;
	
	if (argc == 1)
		show_fparams();
	memset4struct(&fractal, 0, sizeof(t_fdata));
	ft_strlowcase(argv[1]);
	if (argc == 3)
	{
		ft_printf(BOLD YELLOW "Error: missing param for Julia set.\n");
		ft_printf(RESET "Please check the examples below:\n\n");
		(ft_printf(BOLD EX_HEADER "\n\n"), help_julia_examples(), exit(1));
	}
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		mandelbrot(argv, fractal);
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (!global_check_successful(argv))
			exit (1);
		julia(argv, fractal);
	}
	else
		show_fparams();
}
