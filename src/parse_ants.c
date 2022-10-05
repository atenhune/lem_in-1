/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:06:32 by altikka           #+#    #+#             */
/*   Updated: 2022/10/05 19:51:49 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_ants(t_lem *d, t_parser *p)
{
	if (!ft_isnbr(p->line))
		return (panic(NULL, "Error: Has nothing to do with ants."));
	d->ants = ft_atoi(p->line);
	if (d->ants < 0)
		return (panic(NULL, "Error: Negative ammount of ants."));
	if (d->ants == 0)
		return (panic(NULL, "Error: No ants."));
	p->state = ROOMS;
	return (1);
}
