/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_color_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:38:33 by art3mis           #+#    #+#             */
/*   Updated: 2024/03/21 18:40:20 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putendl_color_fd(char *color, char *s, int fd)
{
    ft_putstr_fd(color, fd);
    ft_putendl_fd(s, fd);
    ft_putstr_fd(RESET, fd);
}
