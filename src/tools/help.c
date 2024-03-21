/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:39:10 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/21 23:20:45 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	tutorial(void)
{
	ft_printf("\n" BOLD SEP HEADER SEP "\n\n");
	ft_printf("		available commands to use \n\n");
	ft_printf(" Arrows to move: ↑ ↓ ← → \n");
	ft_printf(" Mouse wheel can zoom in and out \n");
}

void	julia_examples(void)
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

void	help_menu(void)
{
	ft_printf("\n" BOLD SEP ARG_HEADER SEP "\n\n");
	ft_printf(RESET INTRO"\n\n");
	(ft_printf(BOLD PINK M_ARG RESET), ft_printf(BOLD PINK J_ARGS RESET));
	ft_printf(BOLD SEP EX_HEADER SEP RESET "\n\n");
	ft_printf(ITAL RED "(For Julia sets only)\n\n" RESET);
	julia_examples();
}
