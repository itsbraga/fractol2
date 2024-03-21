/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 22:38:52 by art3mis           #+#    #+#             */
/*   Updated: 2024/03/21 22:39:17 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

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
