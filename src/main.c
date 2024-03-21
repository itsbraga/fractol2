/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 05:12:58 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/21 23:42:07 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_data	fractal;
	
	if (argc < 2)
		(perror("Error\n"), tutorial(), help_menu(), exit(EXIT_FAILURE));
	memset4struct(&fractal, 0, sizeof(t_data));
	// ft_strlowcase(argv[1]);
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		mandelbrot(argv, fractal);
	else if (argc == 3)
		help_and_exit();
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (!global_check_successful(argv))
			errcontext_exit();
		julia(argv, fractal);
	}
	else
		(tutorial(), help_menu());
	return (EXIT_SUCCESS);
}
