/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:02:44 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/20 22:30:45 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static int key_hook(int keycode, t_fdata *fractal)
{
    if (keycode == XK_Escape)
        clean(XK_Escape, fractal);
    return (EXIT_SUCCESS);
}

static int mouse_hook(int mousecode, double x, double y, t_fdata *fractal)
{
    (void)x;
    (void)y;
    if (mousecode == MOUSE_WHEEL_UP)
    {
        ft_printf(BOLD BLUE "Scroll up: zoom +\n");
        fractal->zoom += 0.05;
    }
    else if (mousecode == MOUSE_WHEEL_DOWN)
    {
        ft_printf(BOLD BLUE "Scroll down: zoom -\n");
        fractal->zoom -= 0.05;
    }
    draw(fractal);
    return (EXIT_SUCCESS);
}

void	handle_mlx_hooks(t_fdata *fractal)
{
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_hook(fractal->win, 04, (1L << 2), mouse_hook, fractal);
	mlx_hook(fractal->win, 17, (1L << 17), clean, fractal);
}
