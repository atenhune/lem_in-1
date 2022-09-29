/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:55:07 by altikka           #+#    #+#             */
/*   Updated: 2022/09/29 11:56:00 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_parser(t_parser *p)
{
	if (p->inputs.data)
		ft_vecdel(&p->inputs);
	if (p->line)
		ft_strdel(&p->line);
}

int	panic_parser(t_parser *p, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (p)
		free_parser(p);
	return (-1);
}
