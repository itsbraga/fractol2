/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:39:10 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/20 23:09:40 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

// ft_printf("|\tElephant valley\t--> ARGS="0.0 0.3"; ./fractol "$ARGS"\n");
void	help_julia_examples(void)
{
	ft_printf("%s", EXAMPLE(Elephant Valley, 0.0, 0.3));
	ft_printf("%s", EXAMPLE(Sea Horse Valley, -0.75, 0.1));
	ft_printf("%s", EXAMPLE(Mystic Dragon, -0.8, 0.156));
	ft_printf("%s", EXAMPLE(American S, 0.285, -0.01));
	ft_printf("%s", EXAMPLE(Medieval S, 1.74856, 0.00075));
	ft_printf("%s", EXAMPLE(Winter Season, -0.4, 0.6));
	ft_printf("%s", EXAMPLE(BPM, 1.401155, 0.0));
	ft_printf("%s", EXAMPLE(Misshapen Bird, 0.38, -0.12));
	ft_printf("\n");
}

void	show_fparams(void)
{
	ft_printf("\n" BOLD SEP HEADER SEP "\n\n");
	ft_printf(RESET INTRO"\n\n");
	ft_printf(BOLD PINK MANDELBROT RESET M_ARG);
	ft_printf(BOLD PINK JULIA RESET J_ARGS BOLD SEP EX_HEADER SEP "\n\n");
	ft_printf(RESET ITAL RED "(For Julia sets only)\n\n" RESET);
	help_julia_examples();
}

void	*memset4struct(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*fractal;

	i = 0;
	fractal = s;
	while (i < n)
	{
		*(fractal + i) = c;
		i++;
	}
	return (fractal);
}
