/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:37:49 by altikka           #+#    #+#             */
/*   Updated: 2022/10/06 08:38:06 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	init_hash_table(t_parser *p)
{
	int	i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		p->table[i].room = NULL;
		p->table[i].index = -1;
		i++;
	}
}

int	init_parser(t_parser *p)
{
	ft_bzero(p, sizeof(*p));
	if (ft_vecnew(&p->inputs, 32, sizeof(char)) < 0)
		return (panic(NULL, "Error: Couldn't initialize inputs."));
	p->line = NULL;
	p->start = 0;
	p->end = 0;
	p->state = ANTS;
	init_hash_table(p);
	return (1);
}
