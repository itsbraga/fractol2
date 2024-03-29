/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:20:22 by art3mis           #+#    #+#             */
/*   Updated: 2024/03/23 21:29:35 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    help_and_exit(void)
{
    perror("\nError");
	ft_printf("Please, check the menu below:\n\n");
	ft_printf(BOLD SEP EX_HEADER SEP RESET "\n\n");
	julia_examples();
	exit(EXIT_FAILURE);
}

void    errcontext_exit(void)
{
    perror("\nError");
    exit(EXIT_FAILURE);
}
