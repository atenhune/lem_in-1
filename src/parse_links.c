/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:14:18 by altikka           #+#    #+#             */
/*   Updated: 2022/09/21 11:15:02 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	parse_links(t_lem *d, t_parser *p)
{
	(void )d;
	p->state = DONE;
	ft_printf("got links, DONE\n");//del
	return (1);
}
