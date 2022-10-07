/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_bfs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:57:39 by altikka           #+#    #+#             */
/*   Updated: 2022/10/07 14:40:19 by atenhune         ###   ########.fr       */
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
