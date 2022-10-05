/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_pathset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:50:02 by atenhune          #+#    #+#             */
/*   Updated: 2022/10/05 14:50:06 by atenhune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_set(t_lem *d, t_pathset *set)
{
	free(set->parent);
	free(set->seen);
	free(set->used);
	free(set->from);
	free(set->first);
	free(set->weight);
	ft_intdelarr((void *)set->paths, d->room_count);
	ft_intdelarr((void *)set->child, d->room_count);
	ft_intdelarr((void *)set->entries, d->room_count);
	ft_intdelarr((void *)set->to, d->room_count);
	free(set);
}

int	panic_pathset(t_lem *d, t_pathset *set, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (set)
		del_set(d, set);
	return (-1);
}