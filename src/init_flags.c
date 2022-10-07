/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:40:34 by altikka           #+#    #+#             */
/*   Updated: 2022/10/07 16:09:52 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	set_flag(t_flag *flag, char *arg_ptr)
{
	char	*p;

	p = ft_strchr(LEM_FLAGS, *arg_ptr++);
	if (!p || *arg_ptr)
		return (-1);
	if (*p == 'p')
		*flag = PATHS;
	if (*p == 'q')
		*flag = QUIET;
	if (*p == 't')
		*flag = TEST;
	return (1);
}

int		init_flags(t_flag *flag, int argc, char **argv)
{
	char	*p;

	*flag = NONE;
	if (argc == 1)
		return (1);
	if (argc > 2)
		return (panic(NULL, "Error: Too many options."));
	p = argv[1];
	if (*p++ != '-')
		return (panic(NULL, "Error: Invalid option."));
	if (*p == 'h')
		return (0);
	if (set_flag(flag, p) < 0)
		return (-1);
	return (1);
}
