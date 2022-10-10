/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_bfs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka & atenhune <@student.hive.fi>       +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:57:39 by altikka           #+#    #+#             */
/*   Updated: 2022/10/10 11:43:46 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_bfs(t_lem *d, t_bfs *bf)
{
	free_intarr((void *)bf->flow, d->room_count);
	free(bf->fl_dir);
	if (bf->best != NULL)
		free_pathset(d, bf->best);
}

int	panic_bfs(t_lem *d, t_bfs *bf, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (bf)
		free_bfs(d, bf);
	return (-1);
}
