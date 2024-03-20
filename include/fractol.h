/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:15:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/20 22:30:14 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/******************************************************************************\
 * LIBRAIRIES
\******************************************************************************/

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "defines.h"

# include "../mlx/mlx.h"

# include "X11/X.h"
# include "X11/keysym.h"
# include <math.h>
# include <stdbool.h>

/******************************************************************************\
 * STRUCTS
\******************************************************************************/

/* Endianness : Big-endian (BE) + Little-endian (LE)
 * 
 * BE stores the big-end first (reading left->right)
 * LE stores the little-end first (reading right->left)
 * 
 * Least Significant Byte (LSbyte) : smallest position
 * Most Significant Byte (MSbyte) : most significant position
 * 
 * so...
 * BE stores data MSbyte first
 * LE stores data MSbyte last
*/

typedef	struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_complex
{
	double	real;
	double	imagin;
}				t_complex;

typedef	struct	s_fdata
{
	void	*mlx_co;
	void	*win;
	t_img	img;
	char	*name;
	double	max_iter;
	double	zoom;
	double	j_real;
	double	j_imagin;
	double	esc_val;
}				t_fdata;

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

double		atod(char *s);
bool		global_check_successful(char **argv);
void		*memset4struct(void *s, int c, size_t n);

void		help_julia_examples(void);
void		show_fparams(void);

void		handle_mlx_hooks(t_fdata *fractal);
void		handle_pixels(t_fdata *fractal, double x, double y);
double		scale(double n, double new_min, double new_max, double old_max);

void		init_mlx(t_fdata *fractal);

void    	del_win(t_fdata *fractal);
void    	del_img(t_fdata *fractal);
int			clean(int keycode, t_fdata *fractal);

t_complex	z_sqrt(t_complex z);
t_complex	sum(t_complex z, t_complex c);

void		draw(t_fdata *fractal);
void		mandelbrot(char **argv, t_fdata fractal);
void		julia(char **argv, t_fdata fractal);

#endif