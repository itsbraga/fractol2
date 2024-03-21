/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:11:51 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/21 22:53:26 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************\
 * WINDOW
\******************************************************************************/

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

/******************************************************************************\
 * NAVIGATION
\******************************************************************************/

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

/******************************************************************************\
 * SHOW POSSIBLE PARAMS (MENU)
\******************************************************************************/

# define SEP "================================="
# define HEADER " HELP MENU "
# define ARG_HEADER "  ARGS  "
# define INTRO "How to explore the fantastic world of fractals:\n\n"
# define M_ARG "-->\t./fractol mandelbrot\n"
# define J_ARGS "-->\t./fractol julia [double] [double]\n\n\n"
# define EX_HEADER " EXAMPLES "
# define EXAMPLE(x1, x2, x3) #x1 "\t--> ARGS=\"" \
								#x2 " " #x3"\"; ./fractol julia \"$ARGS\"\n"
# define EXAMPLE_MSG "\n\nExamples of Julia's set:\n\n"

/******************************************************************************\
 * COLORS
\******************************************************************************/

# define SALMON 0xFA8072
# define ORANGE_RED 0xFF4500

# define SEA_GREEN 0x2E8B57
# define LIGHT_SEA_GREEN 0x20B2AA

# define LAVENDER 0xE6E6FA

# define INDIGO 0x4B0082
# define DARK_MAGENTA 0x8B008B
# define DEEP_PINK 0xFF1493
# define HOT_PINK 0xFF69B4
# define ORCHID 0xFF83FA

#endif