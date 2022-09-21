/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:35:52 by altikka           #+#    #+#             */
/*   Updated: 2022/09/21 08:49:26 by altikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_parser_data(t_parser *p)
{
	if (p->inputs.data)
		ft_vecdel(&p->inputs);
	if (p->line)
		ft_strdel(&p->line);
}

int	free_parser(t_parser *p, const char *msg)
{
	ft_putendl_fd(msg, 2);
	if (p)
		free_parser_data(p);
	return (-1);
}

int	return_next_line(const int fd, char **line, int *ret)
{
	*ret = get_next_line(fd, line);
	return (*ret);
}

int	init_parser(t_parser *p)
{
	ft_bzero(p, sizeof(*p));
	if (ft_vecnew(&p->inputs, 1, sizeof(char)) < 0) //'1' could be bigger
		return (-1);
	p->line = NULL;
	p->state = ANTS;
	p->start = 0;
	p->end = 0;
	return (1);
}
