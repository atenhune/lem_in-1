/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & atenhune <@student.hive.fi>       +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:18:54 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/10 11:27:56 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_printer(t_printer *p)
{
	if (p->result.alloc_size)
		ft_vecdel(&p->result);
	if (p->ant_line)
		free(p->ant_line);
	free_intarr((void *)p->ants_on_paths, p->path_count);
}

int	panic_printer(t_printer *p, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (p)
		free_printer(p);
	return (-1);
}
