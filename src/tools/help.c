/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 23:39:10 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/23 21:48:17 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	tutorial(void)
{
	ft_printf("\n" BOLD SEP HEADER SEP RESET "\n\n");
	ft_printf(GREEN "Available commands to use:\n" RESET);
	ft_printf("\n⭒ %s\n", "Arrows to move:\t↑ ↓ ← →");
	ft_printf("⭒ %s\n", "Mouse wheel:\t\tscroll up (zoom -)");
	ft_printf("%s\n\n\n", "\t\t\tscroll down (zoom +)");
}

void	julia_examples(void)
{
	ft_printf("%s", EXAMPLE(Elephant Valley, 0.0, 0.3));
	ft_printf("%s", EXAMPLE2(Sea Horse Valley, -0.75, 0.1));
	ft_printf("%s", EXAMPLE(Mystic Dragon, -0.8, 0.156));
	ft_printf("%s", EXAMPLE(American S, 0.285, -0.01));
	ft_printf("%s", EXAMPLE(Medieval S, 1.74856, 0.00075));
	ft_printf("%s", EXAMPLE(Winter Season, -0.4, 0.6));
	ft_printf("%s", EXAMPLE7(BPM, 1.401155, 0.0));
	ft_printf("%s\n", EXAMPLE(Misshapen Bird, 0.38, -0.12));
}

void	help_menu(void)
{
	ft_printf(BOLD SEP ARG_HEADER SEP RESET "\n\n");
	(ft_printf(INTRO1), rainbow_txt(INTRO2 "\n"));
	(ft_printf(BOLD M_ARG1 M_ARG2), ft_printf(J_ARGS1 J_ARGS2 RESET "\n\n"));
	ft_printf(BOLD SEP EX_HEADER SEP RESET "\n\n");
	ft_printf(ITAL YELLOW "(For Julia sets only)\n\n" RESET);
	(julia_examples(), ft_printf("\n"));
}
