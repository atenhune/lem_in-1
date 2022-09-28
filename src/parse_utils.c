/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: altikka <altikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:35:52 by altikka           #+#    #+#             */
/*   Updated: 2022/09/28 09:44:02 by altikka          ###   ########.fr       */
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

int	return_next_line(const int fd, char **line, int *ret)
{
	*ret = get_next_line(fd, line);
	return (*ret);
}

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
	if (ft_vecnew(&p->inputs, 32, sizeof(char)) < 0) //32 min chars in map
		return (-1); //what
	p->line = NULL;
	p->start = 0;
	p->end = 0;
	p->state = ANTS;
	init_hash_table(p);
	return (1);
}
