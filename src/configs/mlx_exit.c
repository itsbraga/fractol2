/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:29:29 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/21 23:49:54 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void    del_win(t_data *fractal)
{
    mlx_destroy_window(fractal->mlx_co, fractal->win);
	free(fractal->mlx_co);
    fractal->mlx_co = NULL;
    ft_printf(BOLD YELLOW "\nWindow successfully destroyed.\n\n");
	ft_printf(RESET);
    exit(EXIT_FAILURE);
}

void    del_img(t_data *fractal)
{
    mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_co, fractal->win);
	free(fractal->mlx_co);
    fractal->mlx_co = NULL;
    ft_printf(BOLD YELLOW "\nImage and window successfully destroyed.\n\n");
    ft_printf(RESET);
	exit(EXIT_FAILURE);
}

int clean(int keycode, t_data *fractal)
{
    if (keycode == XK_Escape)
    {
        ft_printf(BOLD YELLOW"\nESC pressed: Exited the program cleanly.\n\n");
        ft_printf(RESET);
    }
    else
        ft_printf(BOLD YELLOW "\nExited the program cleanly.\n\n" RESET);
    mlx_destroy_image(fractal->mlx_co, fractal->img.img_ptr);
    mlx_destroy_window(fractal->mlx_co, fractal->win);
    mlx_destroy_display(fractal->mlx_co);
    free(fractal->mlx_co);
	exit(EXIT_SUCCESS);
}
