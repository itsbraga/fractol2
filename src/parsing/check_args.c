/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:50:28 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/21 22:54:44 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static bool	is_only_double(char *argv)
{
	int		i;
	bool	has_decimal;

	i = 0;
	has_decimal = false;
	if (argv[i] == '-' && argv[i + 1])
		i++;
	while (argv[i] && (ft_isdigit(argv[i]) || argv[i] == '.' || argv[i] == ','))
	{
		if (argv[i] == '.' || argv[i] == ',')
		{
			if (has_decimal)
				return (false);
			else
				has_decimal = true;
		}
		i++;
	}
	return (true);
}

static bool	have_duplicate(char *argv)
{
    int i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (argv[j] == argv[i] && (argv[i] < 48 || argv[i] > 57))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	global_check_successful(char **argv)
{
	if (!is_only_double(argv[2]) || !is_only_double(argv[3]))
	{
		write(STDERR_FILENO, "Error: Invalid argument. ", 25);
		write(STDERR_FILENO, "Should be decimal.\n\n", 19);
		ft_printf(BOLD EX_HEADER RESET EXAMPLE_MSG);
		julia_examples();
		return (false);
	}
	if (have_duplicate(argv[2]) || have_duplicate(argv[3]))
		return (write(2, "Error: Contains duplicates.\n", 6), false);
	return (true);
}
