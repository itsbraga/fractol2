/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:32:04 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/21 23:09:49 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

t_complex	sum(t_complex z, t_complex c)
{
	t_complex	res;

	res.real = z.real + c.real;
	res.imagin = z.imagin + c.imagin;
	return (res);
}

t_complex	z_square(t_complex z)
{
	t_complex	res;
	
	res.real = (z.real * z.real);
	res.real -= (z.imagin * z.imagin);
	res.imagin = 2 * z.real * z.imagin;
	return (res);
}

/*	This function takes a value n within a range of values defined by old_max,
 *	then resizes it to fall within a new range of values defined by new_min
 *	and new_max. This is useful for normalizing data or scaling values to fit
 *	a certain interval.
*/
double	scale(double n, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * n / old_max + new_min);
}
