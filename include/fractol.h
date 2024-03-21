/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:15:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/21 23:50:19 by art3mis          ###   ########.fr       */
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
 * ABOUT MLX
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

/******************************************************************************\
 * STRUCTS
\******************************************************************************/

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
	double	max_it;
	double	zoom;
	double	j_real;
	double	j_imagin;
	double	esc_val;
}				t_data;

/******************************************************************************\
 * FUNCTIONS
\******************************************************************************/

double		atod(char *s);
bool		global_check_successful(char **argv);
void		*memset4struct(void *s, int c, size_t n);

void		julia_examples(void);
void		help_menu(void);
void		help_and_exit(void);
void		errcontext_exit(void);

void		handle_mlx_hooks(t_data *fractal);
void		set_pixels(t_data *fractal, double x, double y);
double		scale(double n, double new_min, double new_max, double old_max);

void		init_mlx(t_data *fractal);

void    	del_win(t_data *fractal);
void    	del_img(t_data *fractal);
int			clean(int keycode, t_data *fractal);

t_complex	z_square(t_complex z);
t_complex	sum(t_complex z, t_complex c);

void		draw(t_data *fractal);
void		mandelbrot(char **argv, t_data fractal);
void		julia(char **argv, t_data fractal);

#endif