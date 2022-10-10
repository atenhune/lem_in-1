/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_pathset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:50:02 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/10 11:27:28 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_pathset(t_lem *d, t_pathset *set)
{
	free(set->parent);
	free(set->seen);
	free(set->used);
	free(set->from);
	free(set->first);
	free(set->weight);
	free_intarr((void *)set->paths, d->room_count);
	free_intarr((void *)set->child, d->room_count);
	free_intarr((void *)set->entries, d->room_count);
	free_intarr((void *)set->to, d->room_count);
	free(set);
}

int	panic_pathset(t_lem *d, t_pathset *set, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (set)
		free_pathset(d, set);
	return (-1);
}
