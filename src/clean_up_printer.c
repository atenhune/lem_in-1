/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:18:54 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/05 21:39:28 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_intdelarr(void **apa, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(apa[i]);
		i++;
	}
	free(apa);
	apa = NULL;
}

void	free_printer(t_printer *p)
{
	if (p->result.alloc_size)
		ft_vecdel(&p->result);
	if (p->ant_line)
		free(p->ant_line);
	ft_intdelarr((void *)p->ants_on_paths, p->path_count);
}

int	panic_printer(t_printer *p, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (p)
		free_printer(p);
	return (-1);
}
